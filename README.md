# 👓 Óculos para Cegos - Detector de Obstáculos Ultrassônico

Este projeto consiste em um dispositivo assistivo vestível projetado para auxiliar pessoas com deficiência visual a detectar obstáculos à sua frente. Utilizando um sensor ultrassônico e um buzzer, o dispositivo emite sinais sonoros que variam de frequência conforme a proximidade do objeto, funcionando de forma semelhante a um "detector de metais".

## 🚀 Funcionalidades

- **Detecção em Tempo Real:** Medição de distância constante via sensor HC-SR04.
- **Feedback Auditivo Dinâmico:** 
  - **Caminho Livre:** Silêncio total para distâncias acima de 1 metro.
  - **Aproximação:** Bips que aceleram conforme o obstáculo se aproxima (entre 20cm e 100cm).
  - **Alerta Crítico:** Som contínuo para obstáculos a menos de 20cm.
- **Auto-Diagnóstico:** Emite dois bips rápidos ao ser ligado para confirmar que o sistema está operacional.
- **Otimizado para Bateria:** Configurado para rodar em um Arduino Pro Micro alimentado por uma célula 18650.

## 🛠️ Hardware Necessário

| Componente | Descrição |
| :--- | :--- |
| **Microcontrolador** | Arduino Pro Micro (ATmega32U4) |
| **Sensor de Distância** | Ultrassônico HC-SR04 |
| **Atuador Sonoro** | Buzzer Ativo (Low Level Trigger) |
| **Alimentação** | Bateria 18650 + Módulo de Carga/Saída 5V |

## 🔌 Esquema de Ligação

| Componente | Pino no Componente | Pino no Arduino |
| :--- | :--- | :--- |
| **HC-SR04** | VCC | VCC (5V) |
| **HC-SR04** | GND | GND |
| **HC-SR04** | Trig | Pino 7 |
| **HC-SR04** | Echo | Pino 8 |
| **Buzzer** | VCC | VCC (5V) |
| **Buzzer** | GND | GND |
| **Buzzer** | I/O (S) | Pino 9 |

> **Nota:** Como o buzzer utilizado é *Low Level Trigger*, o código está configurado para acioná-lo em nível `LOW`.

## 💻 Instalação e Uso

1. Certifique-se de ter a [Arduino IDE](https://www.arduino.cc/en/software) instalada.
2. No menu **Ferramentas > Placa**, selecione **Arduino Leonardo** (o Pro Micro usa o mesmo bootloader).
3. Conecte o Pro Micro via USB e selecione a porta serial correspondente.
4. Clone este repositório ou copie o código do arquivo `.ino`.
5. Clique em **Upload**.

## ⚙️ Ajustes de Calibração

Você pode personalizar a sensibilidade do óculos alterando estas variáveis no início do código:

```cpp
int DISTANCIA_MAXIMA = 100;  // Distância onde os bips começam (em cm)
int DISTANCIA_CRITICA = 20; // Distância para som contínuo (em cm)
```

## ⚠️ Aviso de Segurança

Se estiver alimentando o projeto via pino **VCC** com uma bateria externa, **nunca conecte o cabo USB simultaneamente**. Isso pode danificar o microcontrolador ou a porta USB do seu computador. Para programar, desconecte a bateria.

---
Projeto desenvolvido para fins educacionais e de acessibilidade.
