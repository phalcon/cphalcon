<?php return array (
  0 => 
  array (
    'type' => 'comment',
    'value' => '**
 * This file is part of the Phalcon Framework.
 *
 * (c) Phalcon Team <team@phalconphp.com>
 *
 * For the full copyright and license information, please view the LICENSE.txt
 * file that was distributed with this source code.
 *',
    'file' => '/app/phalcon/Config/Adapter/Php.zep',
    'line' => 11,
    'char' => 9,
  ),
  1 => 
  array (
    'type' => 'namespace',
    'name' => 'Phalcon\\Config\\Adapter',
    'file' => '/app/phalcon/Config/Adapter/Php.zep',
    'line' => 13,
    'char' => 3,
  ),
  2 => 
  array (
    'type' => 'use',
    'aliases' => 
    array (
      0 => 
      array (
        'name' => 'Phalcon\\Config\\Config',
        'file' => '/app/phalcon/Config/Adapter/Php.zep',
        'line' => 13,
        'char' => 26,
      ),
    ),
    'file' => '/app/phalcon/Config/Adapter/Php.zep',
    'line' => 49,
    'char' => 2,
  ),
  3 => 
  array (
    'type' => 'comment',
    'value' => '**
 * Reads php files and converts them to Phalcon\\Config objects.
 *
 * Given the next configuration file:
 *
 *```php
 * <?php
 *
 * return [
 *     "database" => [
 *         "adapter"  => "Mysql",
 *         "host"     => "localhost",
 *         "username" => "scott",
 *         "password" => "cheetah",
 *         "dbname"   => "test_db",
 *     ],
 *     "phalcon" => [
 *         "controllersDir" => "../app/controllers/",
 *         "modelsDir"      => "../app/models/",
 *         "viewsDir"       => "../app/views/",
 *     ],
 * ];
 *```
 *
 * You can read it as follows:
 *
 *```php
 * use Phalcon\\Config\\Adapter\\Php;
 *
 * $config = new Php("path/config.php");
 *
 * echo $config->phalcon->controllersDir;
 * echo $config->database->username;
 *```
 *',
    'file' => '/app/phalcon/Config/Adapter/Php.zep',
    'line' => 50,
    'char' => 5,
  ),
  4 => 
  array (
    'type' => 'class',
    'name' => 'Php',
    'abstract' => 0,
    'final' => 0,
    'extends' => 'Config',
    'definition' => 
    array (
      'methods' => 
      array (
        0 => 
        array (
          'visibility' => 
          array (
            0 => 'public',
          ),
          'type' => 'method',
          'name' => '__construct',
          'parameters' => 
          array (
            0 => 
            array (
              'type' => 'parameter',
              'name' => 'filePath',
              'const' => 0,
              'data-type' => 'string',
              'mandatory' => 1,
              'reference' => 0,
              'file' => '/app/phalcon/Config/Adapter/Php.zep',
              'line' => 55,
              'char' => 49,
            ),
          ),
          'statements' => 
          array (
            0 => 
            array (
              'type' => 'scall',
              'expr' => 
              array (
                'type' => 'scall',
                'dynamic-class' => 0,
                'class' => 'parent',
                'dynamic' => 0,
                'name' => '__construct',
                'parameters' => 
                array (
                  0 => 
                  array (
                    'parameter' => 
                    array (
                      'type' => 'require',
                      'left' => 
                      array (
                        'type' => 'variable',
                        'value' => 'filePath',
                        'file' => '/app/phalcon/Config/Adapter/Php.zep',
                        'line' => 59,
                        'char' => 9,
                      ),
                      'file' => '/app/phalcon/Config/Adapter/Php.zep',
                      'line' => 59,
                      'char' => 9,
                    ),
                    'file' => '/app/phalcon/Config/Adapter/Php.zep',
                    'line' => 59,
                    'char' => 9,
                  ),
                ),
                'file' => '/app/phalcon/Config/Adapter/Php.zep',
                'line' => 59,
                'char' => 10,
              ),
              'file' => '/app/phalcon/Config/Adapter/Php.zep',
              'line' => 60,
              'char' => 5,
            ),
          ),
          'docblock' => '**
     * Phalcon\\Config\\Adapter\\Php constructor
     *',
          'return-type' => 
          array (
            'type' => 'return-type',
            'void' => 1,
            'file' => '/app/phalcon/Config/Adapter/Php.zep',
            'line' => 56,
            'char' => 5,
          ),
          'file' => '/app/phalcon/Config/Adapter/Php.zep',
          'line' => 55,
          'last-line' => 61,
          'char' => 19,
        ),
      ),
      'file' => '/app/phalcon/Config/Adapter/Php.zep',
      'line' => 50,
      'char' => 5,
    ),
    'file' => '/app/phalcon/Config/Adapter/Php.zep',
    'line' => 50,
    'char' => 5,
  ),
);