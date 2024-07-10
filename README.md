# CpcProject

## Descrição

CpcProject é um sistema de controle e monitoramento de áudio que utiliza um ESP32 para ler dados de um potenciômetro e enviar essas informações para uma API. O sistema também utiliza lógica fuzzy para controlar LEDs com base nos valores lidos do potenciômetro.

## Funcionalidades

- Leitura de dados de um potenciômetro de áudio.
- Envio de dados para uma API via WiFi.
- Controle de LEDs com base nos valores do potenciômetro usando lógica fuzzy.

## Requisitos

- ESP32
- Potenciômetro
- LEDs
- Conexão WiFi
- Biblioteca Arduino HTTPClient
- Biblioteca Fuzzy

## Instalação

### Clonar o Repositório

Primeiro, clone o repositório do GitHub:

```bash
git clone https://github.com/USERNAME/CpcProject.git
cd CpcProject
```

## Configurar o Ambiente

Placa ESP32:

Certifique-se de ter o ESP32 board package instalado na sua IDE Arduino.
Bibliotecas Necessárias:

Certifique-se de ter as bibliotecas WiFi, HTTPClient, e Fuzzy instaladas na sua IDE Arduino.
Configuração
Configuração WiFi
No arquivo main.ino, configure o SSID e a senha do WiFi:

Carregue o código para o ESP32 usando a IDE Arduino.
Monitoramento:

Use o monitor serial da IDE Arduino para verificar as saídas e depurar.
Contribuição
Contribuições são bem-vindas! Sinta-se à vontade para abrir um issue ou enviar um pull request.


Contato
Para mais informações, entre em contato com Caio Grasso.
