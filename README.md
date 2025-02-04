# 🎮 Projeto Temporizador de Semáforo

Este projeto implementa um temporizador cíclico que controla um semáforo com LEDs representando os estados vermelho, amarelo e verde. A troca entre os estados ocorre automaticamente a cada 3 segundos por meio de uma função de callback.

---

## 🔧 Hardware
### Componentes necessários:
- Placa **Raspberry Pi Pico**
- 3 LEDs (vermelho, amarelo e verde)
- 3 resistores de 330Ω

### 📍 Pinagem
- LED **Vermelho**: GPIO13 
- LED **Amarelo**: GPIO12 
- LED **Verde**: GPIO11 

---

## 💻 Software Necessário
- **IDE**: Visual Studio Code (com extensão CMake e ambiente configurado para Raspberry Pi Pico)
- **SDK**: Raspberry Pi Pico C/C++ SDK ([Documentação Oficial](https://github.com/raspberrypi/pico-sdk))
- **Compilador**: GCC e CMake
- **Simulador**: Wokwi (opcional, útil para simulações online)

---

## 📁 Estrutura do Projeto

```plaintext
.
├── .vscode/ # Configurações do workspace no VSCode
├── build/ # Build gerado pelo CMake
├── TemporizadorPeriodico.c # Código principal do semáforo
├── CMakeLists.txt # Configurações do projeto com CMake
├── pico_sdk_import.cmake # Inclusão do SDK do Raspberry Pi Pico
├── diagram.json # Simulador Wokwi (opcional)
├── wokwi.toml # Configuração para simulação no Wokwi
└── README.md # Documentação do projeto
```

---

## 🚀 Compilação e Execução do Código

### Configuração do Ambiente
1. Instale o SDK do **Raspberry Pi Pico** seguindo o guia oficial.
2. Configure a extensão CMake do Visual Studio Code.
3. Certifique-se de que o Pico está conectado via USB.

### Comandos para Compilar:
Execute os comandos abaixo no terminal:
```bash
mkdir build
cd build
cmake ..
make
```

### Upload para o Raspberry Pi Pico:
1. Após a compilação, será gerado um arquivo `.uf2` no diretório `build`.
2. Coloque o Pico no modo de bootloader (segure o botão BOOTSEL ao conectar via USB).
3. Copie o arquivo `.uf2` para o dispositivo detectado como drive USB.

---

## 🚀 Funcionamento

O semáforo funciona da seguinte forma:
1. O LED vermelho acende no início e permanece ligado por 3 segundos.
2. Após 3 segundos, o LED amarelo acende, e o vermelho apaga.
3. Passados mais 3 segundos, o LED verde acende, e o amarelo apaga.
4. Este ciclo continua indefinidamente.

O temporizador é implementado utilizando a função `add_repeating_timer_ms` da biblioteca padrão do Raspberry Pi Pico.

---

## 🐛 Debug

### Dicas para depuração:
1. **Monitor Serial**: Utilize o monitor serial para verificar mensagens de status:
   ```bash
   minicom -b 115200 -o -D /dev/ttyUSB0
   ```
2. **LEDs não acendem**:
   - Verifique as conexões físicas e os resistores dos LEDs.
   - Certifique-se de que o código foi carregado corretamente.
3. **Simulação no Wokwi**:
   - Configure o arquivo `diagram.json` para simular as conexões.

---

## 🗺️ Esquemático

Segue abaixo a pinagem dos LEDs para o Raspberry Pi Pico:





🔗 **Link do Vídeo de Funcionamento**: [Adicione aqui o link do vídeo]

📞 **Contato**:

👤 Autor: Jonas Souza

📧 E-mail: Jonassouza871@hotmail.com



