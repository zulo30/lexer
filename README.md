# lexer V0.2 

Trabajo de Lenguajes y Compiladores | Universidad EIA ![logo eia](https://github.com/EIA-University/LogosEIA/blob/master/assets/png/logo-eia-icon.png?raw=true)

Lexer es una herramienta del linea de comando que Analiza sintaticamente un archivo.

## Comenzando :rocket:

### Pre-requisitos

* pyenv | [https://github.com/pyenv/pyenv](https://github.com/pyenv/pyenv)
* pipenv | [https://pipenv-es.readthedocs.io/es/latest/](https://pipenv-es.readthedocs.io/es/latest/)

* Django | [https://docs.djangoproject.com/](https://docs.djangoproject.com/)
* Keras | [https://keras.io](https://keras.io)
* Mysql Workbench | [https://www.mysql.com/products/workbench/](https://www.mysql.com/products/workbench/)
* Sequel Pro |   [https://www.sequelpro.com](https://www.sequelpro.com)

:heavy_exclamation_mark: ***NOTA: Para Windows, instalar la version de [pyenv-win](https://github.com/pyenv-win/pyenv-win#installation)***

### Importar Un Proyecto
para bajar el proyecto:
```
 git clone https://github.com/zulo30/grabus-app.git backend
```
para correr el proyecto:

1. bajar las dependecias de python con pipenv.
    ```
    pipenv install
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
    
    :heavy_exclamation_mark: ***NOTA: Para MacOS, seguir la guía de [instalación](https://ruddra.com/posts/install-mysqlclient-macos/)***


7. Migrar la base de datos 
    ```
    pipenv run migrate
    ```

## Uso
 para correr el servidor: 
 ```
 pipenv run server
 ```

## Recursos

* django docs | [https://docs.djangoproject.com/](https://docs.djangoproject.com/)
* setting up django prject like a pro | [https://medium.com/@fceruti/](https://medium.com/@fceruti/setting-up-a-django-project-like-a-pro-a847a9867f9d)
* django-vue integration tutorial | [https://github.com/michaelbukachi/django-vuejs-tutorial/](https://github.com/michaelbukachi/django-vuejs-tutorial/wiki/Django-Vue.js-Integration-Tutorial)
* integrating django and vue using webpack | [https://medium.com/@rodrigosmaniotto/](https://medium.com/@rodrigosmaniotto/integrating-django-and-vuejs-with-vue-cli-3-and-webpack-loader-145c3b98501a)
* django webpack loader | [https://github.com/owais/django-webpack-loader](https://github.com/owais/django-webpack-loader)
* mysqlclient on macos | [https://ruddra.com/posts/install-mysqlclient-macos/](https://ruddra.com/posts/install-mysqlclient-macos/) 


## Contribuir:
Por favor lee el [CONTRIBUTING.md]() para detalles de nuestro código de conducta, y el proceso para enviarnos pull requests.
## Licencia:
Este proyecto está licenciado bajo la Licencia MIT License  - vea el archivo [LICENSE.md]() para más detalles

