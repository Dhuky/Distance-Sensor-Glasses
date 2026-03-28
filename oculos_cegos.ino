
/**
 * Projeto: Óculos para Cegos (VERSÃO CORRIGIDA NO ARQUIVO CERTO)
 * Se você não ouvir 2 bips ao ligar, o código não foi carregado!
 */

const int TRIG_PIN = 7;
const int ECHO_PIN = 8;
const int BUZZer_PIN = 9;

// CONFIGURAÇÃO: 1 Metro (100 cm)
int DISTANCIA_MAXIMA = 85;  
int DISTANCIA_CRITICA = 20; 

void setup() {
  pinMode(TRIG_PIN, OUTPUT);
  pinMode(ECHO_PIN, INPUT);
  pinMode(BUZZer_PIN, OUTPUT);
  
  digitalWrite(BUZZer_PIN, HIGH); // Começa desligado (Active Low)
  Serial.begin(9600);

  // --- BIP DE TESTE DE INICIALIZAÇÃO ---
  digitalWrite(BUZZer_PIN, LOW); delay(100);
  digitalWrite(BUZZer_PIN, HIGH); delay(100);
  digitalWrite(BUZZer_PIN, LOW); delay(100);
  digitalWrite(BUZZer_PIN, HIGH);

  Serial.println("--- SISTEMA PRONTO: ALCANCE 1 METRO ---");
}

void loop() {
  long duracao;
  int distancia;

  digitalWrite(TRIG_PIN, LOW);
  delayMicroseconds(2);
  digitalWrite(TRIG_PIN, HIGH);
  delayMicroseconds(10);
  digitalWrite(TRIG_PIN, LOW);

  // Lê a distância com timeout
  duracao = pulseIn(ECHO_PIN, HIGH, 30000);
  distancia = duracao * 0.034 / 2;

  // MONITOR SERIAL
  if (distancia <= 0 || distancia > 400) {
    Serial.println("MONITORAMENTO: LIVRE");
    distancia = 999;
  } else {
    Serial.print("MONITORAMENTO: ");
    Serial.print(distancia);
    Serial.println(" cm");
  }

  // Lógica de Som (Agora até 100cm)
  if (distancia > 2 && distancia <= DISTANCIA_MAXIMA) {
    if (distancia <= DISTANCIA_CRITICA) {
      digitalWrite(BUZZer_PIN, LOW); // Som contínuo (Muito perto)
    } 
    else {
      // Mapeia 20-100cm para bips rápidos-lentos
      int delayBip = map(distancia, DISTANCIA_CRITICA, DISTANCIA_MAXIMA, 40, 500);
      digitalWrite(BUZZer_PIN, LOW); 
      delay(40);                     
      digitalWrite(BUZZer_PIN, HIGH);
      delay(delayBip);               
    }
  } 
  else {
    digitalWrite(BUZZer_PIN, HIGH); // Silêncio total acima de 1 metro
  }

  delay(30);
}
