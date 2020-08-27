# lexer v0.2 

Trabajo de Lenguajes y Compiladores | Universidad EIA ![logo eia](https://github.com/EIA-University/LogosEIA/blob/master/assets/png/logo-eia-icon.png?raw=true)


## Comenzando :rocket:

### Pre-requisitos

* 

:heavy_exclamation_mark: ***NOTA: Para Windows, instalar la version de [pyenv-win](https://github.com/pyenv-win/pyenv-win#installation)***

### Importar Un Proyecto
para bajar el proyecto:
```
 git clone https://github.com/zulo30/lexer.git
```
para correr el proyecto:

1. bajar las dependecias de python con pipenv.
    ```
    comando 
    ```
2. bajar las depedencias de frontend con npm.
    ```
    npm install
    ```
4. crear sus variables de entorno. (en windows el comamndo `copy` y en unix-like es `cp`).
    ```
    cp .env.example .env
    ```
5. Generar la llave de encritapción. 
    ```
    openssl rand -base64 32
    ```
6. Configurar la BD local acorde a su entorno de desarrollo. (En el archico .env  cambiar las variables de entorno). para más información ver [video](https://www.youtube.com/watch?v=jzvsotmNrK8) o seguir [la guía para linux](https://support.rackspace.com/how-to/install-mysql-server-on-the-ubuntu-operating-system/)

    ```
    .....

    ENV=dev
    DEBUG=on
    SECRET_KEY=my-secret-key
    DATABASE_URL=ATABASE_URL=mysql://<<username>>:<<username>>@127.0.0.1:3306/<<database>>
    
    ....
    ```


## Uso
 para correr el servidor: 
 ```
 pipenv run server
 ```

## Recursos

* 


## Contribuir:
Por favor lee el [CONTRIBUTING.md]() para detalles de nuestro código de conducta, y el proceso para enviarnos pull requests.
## Licencia:
Este proyecto está licenciado bajo la Licencia MIT License  - vea el archivo [LICENSE.md]() para más detalles

