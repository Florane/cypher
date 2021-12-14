# Hello Yes  
Шифратор и дешифратор на основе алгоритма AES-128.  
Может использовать 2 режима шифрования - CBC и CFB.  
Использует схему Шамира для разделения и реконструкции ключа.  
## Аргументы  
**-h** - выводит сообщение помощи  
### Режим работы  
**-e** - шифрование  
**-d** - дешифрование  
### Файлы  
**-i, --input *file*** - файл ввода  
**-o, --output *file*** - файл вывода  
### Режимы шифрования  
**--cbc** - использовать CBC  
**--cfb** - использовать CFB  
### Шифрование  
**-k, --key *file|key*** - ключ шифрования или файл с ключом шифрования  
**-t *number*** - общее число частей ключа  
**-m *number*** - минимальное число частей для восстановления ключа  
### Дешифрование  
**-s, --shares *files ...*** - файлы с частями ключа  
**-m *number*** - минимальное число частей для восстановления ключа  
**--save_key *file*** - сохранить ключ в файл  