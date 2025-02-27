cmake_minimum_required(VERSION 3.13)

set(CMAKE_C_STANDARD 11)
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

# Determina o diretório do usuário para a extensão do VS Code
if(WIN32)
    set(USERHOME $ENV{USERPROFILE})
else()
    set(USERHOME $ENV{HOME})
endif()

set(sdkVersion 2.1.1)
set(toolchainVersion 14_2_Rel1)
set(picotoolVersion 2.1.1)
set(picoVscode ${USERHOME}/.pico-sdk/cmake/pico-vscode.cmake)

if (EXISTS ${picoVscode})
    include(${picoVscode})
endif()

# Define a placa usada (pico ou pico_w)
set(PICO_BOARD pico_w CACHE STRING "Board type")

# Importa o Raspberry Pi Pico SDK
include(pico_sdk_import.cmake)

# Define o projeto
project(Temperatura C CXX ASM)

# Inicializa o SDK do Pico
pico_sdk_init()

# Cria o executável com o código-fonte principal
add_executable(Temperatura Temperatura.c)

# Define nome e versão do programa
pico_set_program_name(Temperatura "Temperatura")
pico_set_program_version(Temperatura "0.1")

# Configuração de entrada/saída padrão (habilitar UART e USB)
pico_enable_stdio_uart(Temperatura 1)
pico_enable_stdio_usb(Temperatura 1)

# Inclui diretórios necessários
target_include_directories(Temperatura PRIVATE
    ${CMAKE_CURRENT_LIST_DIR}
    ${CMAKE_CURRENT_LIST_DIR}/libs
)

# Se as bibliotecas possuem arquivos .c, adicione-as corretamente
add_subdirectory(libs/BitDogLab)
add_subdirectory(libs/DHT)

# Adiciona bibliotecas ao link
target_link_libraries(Temperatura 
    BitDogLab
    DHT
    pico_stdlib 
)

# Geração de arquivos extras (como UF2, BIN e HEX)
pico_add_extra_outputs(Temperatura)


