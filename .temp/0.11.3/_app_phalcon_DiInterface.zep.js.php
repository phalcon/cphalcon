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
    'file' => '/app/phalcon/DiInterface.zep',
    'line' => 11,
    'char' => 9,
  ),
  1 => 
  array (
    'type' => 'namespace',
    'name' => 'Phalcon',
    'file' => '/app/phalcon/DiInterface.zep',
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
        'name' => 'ArrayAccess',
        'file' => '/app/phalcon/DiInterface.zep',
        'line' => 13,
        'char' => 16,
      ),
    ),
    'file' => '/app/phalcon/DiInterface.zep',
    'line' => 14,
    'char' => 3,
  ),
  3 => 
  array (
    'type' => 'use',
    'aliases' => 
    array (
      0 => 
      array (
        'name' => 'Phalcon\\DiInterface',
        'file' => '/app/phalcon/DiInterface.zep',
        'line' => 14,
        'char' => 24,
      ),
    ),
    'file' => '/app/phalcon/DiInterface.zep',
    'line' => 15,
    'char' => 3,
  ),
  4 => 
  array (
    'type' => 'use',
    'aliases' => 
    array (
      0 => 
      array (
        'name' => 'Phalcon\\Di\\ServiceInterface',
        'file' => '/app/phalcon/DiInterface.zep',
        'line' => 15,
        'char' => 32,
      ),
    ),
    'file' => '/app/phalcon/DiInterface.zep',
    'line' => 19,
    'char' => 2,
  ),
  5 => 
  array (
    'type' => 'comment',
    'value' => '**
 * Interface for Phalcon\\Di
 *',
    'file' => '/app/phalcon/DiInterface.zep',
    'line' => 20,
    'char' => 9,
  ),
  6 => 
  array (
    'type' => 'interface',
    'name' => 'DiInterface',
    'extends' => 
    array (
      0 => 
      array (
        'type' => 'variable',
        'value' => 'ArrayAccess',
        'file' => '/app/phalcon/DiInterface.zep',
        'line' => 21,
        'char' => 1,
      ),
    ),
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
          'name' => 'attempt',
          'parameters' => 
          array (
            0 => 
            array (
              'type' => 'parameter',
              'name' => 'name',
              'const' => 0,
              'data-type' => 'string',
              'mandatory' => 1,
              'reference' => 0,
              'file' => '/app/phalcon/DiInterface.zep',
              'line' => 29,
              'char' => 41,
            ),
            1 => 
            array (
              'type' => 'parameter',
              'name' => 'definition',
              'const' => 0,
              'data-type' => 'variable',
              'mandatory' => 0,
              'reference' => 0,
              'file' => '/app/phalcon/DiInterface.zep',
              'line' => 29,
              'char' => 53,
            ),
            2 => 
            array (
              'type' => 'parameter',
              'name' => 'shared',
              'const' => 0,
              'data-type' => 'bool',
              'mandatory' => 0,
              'default' => 
              array (
                'type' => 'bool',
                'value' => 'false',
                'file' => '/app/phalcon/DiInterface.zep',
                'line' => 29,
                'char' => 74,
              ),
              'reference' => 0,
              'file' => '/app/phalcon/DiInterface.zep',
              'line' => 29,
              'char' => 74,
            ),
          ),
          'docblock' => '**
     * Attempts to register a service in the services container
     * Only is successful if a service hasn\'t been registered previously
     * with the same name
     *
     * @param mixed definition
     *',
          'return-type' => 
          array (
            'type' => 'return-type',
            'list' => 
            array (
              0 => 
              array (
                'type' => 'return-type-parameter',
                'cast' => 
                array (
                  'type' => 'variable',
                  'value' => 'ServiceInterface',
                  'file' => '/app/phalcon/DiInterface.zep',
                  'line' => 29,
                  'char' => 98,
                ),
                'collection' => 0,
                'file' => '/app/phalcon/DiInterface.zep',
                'line' => 29,
                'char' => 98,
              ),
              1 => 
              array (
                'type' => 'return-type-parameter',
                'data-type' => 'bool',
                'mandatory' => 0,
                'file' => '/app/phalcon/DiInterface.zep',
                'line' => 29,
                'char' => 104,
              ),
            ),
            'void' => 0,
            'file' => '/app/phalcon/DiInterface.zep',
            'line' => 29,
            'char' => 104,
          ),
          'file' => '/app/phalcon/DiInterface.zep',
          'line' => 29,
          'last-line' => 33,
          'char' => 19,
        ),
        1 => 
        array (
          'visibility' => 
          array (
            0 => 'public',
          ),
          'type' => 'method',
          'name' => 'get',
          'parameters' => 
          array (
            0 => 
            array (
              'type' => 'parameter',
              'name' => 'name',
              'const' => 0,
              'data-type' => 'string',
              'mandatory' => 1,
              'reference' => 0,
              'file' => '/app/phalcon/DiInterface.zep',
              'line' => 34,
              'char' => 37,
            ),
            1 => 
            array (
              'type' => 'parameter',
              'name' => 'parameters',
              'const' => 0,
              'data-type' => 'variable',
              'mandatory' => 0,
              'default' => 
              array (
                'type' => 'null',
                'file' => '/app/phalcon/DiInterface.zep',
                'line' => 34,
                'char' => 56,
              ),
              'reference' => 0,
              'file' => '/app/phalcon/DiInterface.zep',
              'line' => 34,
              'char' => 56,
            ),
          ),
          'docblock' => '**
     * Resolves the service based on its configuration
     *',
          'return-type' => 
          array (
            'type' => 'return-type',
            'list' => 
            array (
              0 => 
              array (
                'type' => 'return-type-parameter',
                'data-type' => 'variable',
                'mandatory' => 0,
                'file' => '/app/phalcon/DiInterface.zep',
                'line' => 34,
                'char' => 64,
              ),
            ),
            'void' => 0,
            'file' => '/app/phalcon/DiInterface.zep',
            'line' => 34,
            'char' => 64,
          ),
          'file' => '/app/phalcon/DiInterface.zep',
          'line' => 34,
          'last-line' => 38,
          'char' => 19,
        ),
        2 => 
        array (
          'visibility' => 
          array (
            0 => 'public',
            1 => 'static',
          ),
          'type' => 'method',
          'name' => 'getDefault',
          'docblock' => '**
     * Return the last DI created
     *',
          'return-type' => 
          array (
            'type' => 'return-type',
            'list' => 
            array (
              0 => 
              array (
                'type' => 'return-type-parameter',
                'cast' => 
                array (
                  'type' => 'variable',
                  'value' => 'DiInterface',
                  'file' => '/app/phalcon/DiInterface.zep',
                  'line' => 39,
                  'char' => 58,
                ),
                'collection' => 0,
                'file' => '/app/phalcon/DiInterface.zep',
                'line' => 39,
                'char' => 58,
              ),
              1 => 
              array (
                'type' => 'return-type-parameter',
                'data-type' => 'null',
                'mandatory' => 0,
                'file' => '/app/phalcon/DiInterface.zep',
                'line' => 39,
                'char' => 64,
              ),
            ),
            'void' => 0,
            'file' => '/app/phalcon/DiInterface.zep',
            'line' => 39,
            'char' => 64,
          ),
          'file' => '/app/phalcon/DiInterface.zep',
          'line' => 39,
          'last-line' => 43,
          'char' => 26,
        ),
        3 => 
        array (
          'visibility' => 
          array (
            0 => 'public',
          ),
          'type' => 'method',
          'name' => 'getRaw',
          'parameters' => 
          array (
            0 => 
            array (
              'type' => 'parameter',
              'name' => 'name',
              'const' => 0,
              'data-type' => 'string',
              'mandatory' => 1,
              'reference' => 0,
              'file' => '/app/phalcon/DiInterface.zep',
              'line' => 44,
              'char' => 40,
            ),
          ),
          'docblock' => '**
     * Returns a service definition without resolving
     *',
          'return-type' => 
          array (
            'type' => 'return-type',
            'list' => 
            array (
              0 => 
              array (
                'type' => 'return-type-parameter',
                'data-type' => 'variable',
                'mandatory' => 0,
                'file' => '/app/phalcon/DiInterface.zep',
                'line' => 44,
                'char' => 48,
              ),
            ),
            'void' => 0,
            'file' => '/app/phalcon/DiInterface.zep',
            'line' => 44,
            'char' => 48,
          ),
          'file' => '/app/phalcon/DiInterface.zep',
          'line' => 44,
          'last-line' => 48,
          'char' => 19,
        ),
        4 => 
        array (
          'visibility' => 
          array (
            0 => 'public',
          ),
          'type' => 'method',
          'name' => 'getService',
          'parameters' => 
          array (
            0 => 
            array (
              'type' => 'parameter',
              'name' => 'name',
              'const' => 0,
              'data-type' => 'string',
              'mandatory' => 1,
              'reference' => 0,
              'file' => '/app/phalcon/DiInterface.zep',
              'line' => 49,
              'char' => 44,
            ),
          ),
          'docblock' => '**
     * Returns the corresponding Phalcon\\Di\\Service instance for a service
     *',
          'return-type' => 
          array (
            'type' => 'return-type',
            'list' => 
            array (
              0 => 
              array (
                'type' => 'return-type-parameter',
                'cast' => 
                array (
                  'type' => 'variable',
                  'value' => 'ServiceInterface',
                  'file' => '/app/phalcon/DiInterface.zep',
                  'line' => 49,
                  'char' => 67,
                ),
                'collection' => 0,
                'file' => '/app/phalcon/DiInterface.zep',
                'line' => 49,
                'char' => 67,
              ),
            ),
            'void' => 0,
            'file' => '/app/phalcon/DiInterface.zep',
            'line' => 49,
            'char' => 67,
          ),
          'file' => '/app/phalcon/DiInterface.zep',
          'line' => 49,
          'last-line' => 53,
          'char' => 19,
        ),
        5 => 
        array (
          'visibility' => 
          array (
            0 => 'public',
          ),
          'type' => 'method',
          'name' => 'getServices',
          'docblock' => '**
     * Return the services registered in the DI
     *',
          'return-type' => 
          array (
            'type' => 'return-type',
            'list' => 
            array (
              0 => 
              array (
                'type' => 'return-type-parameter',
                'cast' => 
                array (
                  'type' => 'variable',
                  'value' => 'ServiceInterface',
                  'file' => '/app/phalcon/DiInterface.zep',
                  'line' => 54,
                  'char' => 58,
                ),
                'collection' => 1,
                'file' => '/app/phalcon/DiInterface.zep',
                'line' => 54,
                'char' => 58,
              ),
            ),
            'void' => 0,
            'file' => '/app/phalcon/DiInterface.zep',
            'line' => 54,
            'char' => 58,
          ),
          'file' => '/app/phalcon/DiInterface.zep',
          'line' => 54,
          'last-line' => 58,
          'char' => 19,
        ),
        6 => 
        array (
          'visibility' => 
          array (
            0 => 'public',
          ),
          'type' => 'method',
          'name' => 'getShared',
          'parameters' => 
          array (
            0 => 
            array (
              'type' => 'parameter',
              'name' => 'name',
              'const' => 0,
              'data-type' => 'string',
              'mandatory' => 1,
              'reference' => 0,
              'file' => '/app/phalcon/DiInterface.zep',
              'line' => 59,
              'char' => 43,
            ),
            1 => 
            array (
              'type' => 'parameter',
              'name' => 'parameters',
              'const' => 0,
              'data-type' => 'variable',
              'mandatory' => 0,
              'default' => 
              array (
                'type' => 'null',
                'file' => '/app/phalcon/DiInterface.zep',
                'line' => 59,
                'char' => 62,
              ),
              'reference' => 0,
              'file' => '/app/phalcon/DiInterface.zep',
              'line' => 59,
              'char' => 62,
            ),
          ),
          'docblock' => '**
     * Returns a shared service based on their configuration
     *',
          'return-type' => 
          array (
            'type' => 'return-type',
            'list' => 
            array (
              0 => 
              array (
                'type' => 'return-type-parameter',
                'data-type' => 'variable',
                'mandatory' => 0,
                'file' => '/app/phalcon/DiInterface.zep',
                'line' => 59,
                'char' => 70,
              ),
            ),
            'void' => 0,
            'file' => '/app/phalcon/DiInterface.zep',
            'line' => 59,
            'char' => 70,
          ),
          'file' => '/app/phalcon/DiInterface.zep',
          'line' => 59,
          'last-line' => 63,
          'char' => 19,
        ),
        7 => 
        array (
          'visibility' => 
          array (
            0 => 'public',
          ),
          'type' => 'method',
          'name' => 'has',
          'parameters' => 
          array (
            0 => 
            array (
              'type' => 'parameter',
              'name' => 'name',
              'const' => 0,
              'data-type' => 'string',
              'mandatory' => 1,
              'reference' => 0,
              'file' => '/app/phalcon/DiInterface.zep',
              'line' => 64,
              'char' => 37,
            ),
          ),
          'docblock' => '**
     * Check whether the DI contains a service by a name
     *',
          'return-type' => 
          array (
            'type' => 'return-type',
            'list' => 
            array (
              0 => 
              array (
                'type' => 'return-type-parameter',
                'data-type' => 'bool',
                'mandatory' => 0,
                'file' => '/app/phalcon/DiInterface.zep',
                'line' => 64,
                'char' => 46,
              ),
            ),
            'void' => 0,
            'file' => '/app/phalcon/DiInterface.zep',
            'line' => 64,
            'char' => 46,
          ),
          'file' => '/app/phalcon/DiInterface.zep',
          'line' => 64,
          'last-line' => 68,
          'char' => 19,
        ),
        8 => 
        array (
          'visibility' => 
          array (
            0 => 'public',
          ),
          'type' => 'method',
          'name' => 'remove',
          'parameters' => 
          array (
            0 => 
            array (
              'type' => 'parameter',
              'name' => 'name',
              'const' => 0,
              'data-type' => 'string',
              'mandatory' => 1,
              'reference' => 0,
              'file' => '/app/phalcon/DiInterface.zep',
              'line' => 69,
              'char' => 40,
            ),
          ),
          'docblock' => '**
     * Removes a service in the services container
     *',
          'return-type' => 
          array (
            'type' => 'return-type',
            'void' => 1,
            'file' => '/app/phalcon/DiInterface.zep',
            'line' => 69,
            'char' => 49,
          ),
          'file' => '/app/phalcon/DiInterface.zep',
          'line' => 69,
          'last-line' => 73,
          'char' => 19,
        ),
        9 => 
        array (
          'visibility' => 
          array (
            0 => 'public',
            1 => 'static',
          ),
          'type' => 'method',
          'name' => 'reset',
          'docblock' => '**
     * Resets the internal default DI
     *',
          'return-type' => 
          array (
            'type' => 'return-type',
            'void' => 1,
            'file' => '/app/phalcon/DiInterface.zep',
            'line' => 74,
            'char' => 43,
          ),
          'file' => '/app/phalcon/DiInterface.zep',
          'line' => 74,
          'last-line' => 78,
          'char' => 26,
        ),
        10 => 
        array (
          'visibility' => 
          array (
            0 => 'public',
          ),
          'type' => 'method',
          'name' => 'set',
          'parameters' => 
          array (
            0 => 
            array (
              'type' => 'parameter',
              'name' => 'name',
              'const' => 0,
              'data-type' => 'string',
              'mandatory' => 1,
              'reference' => 0,
              'file' => '/app/phalcon/DiInterface.zep',
              'line' => 79,
              'char' => 37,
            ),
            1 => 
            array (
              'type' => 'parameter',
              'name' => 'definition',
              'const' => 0,
              'data-type' => 'variable',
              'mandatory' => 0,
              'reference' => 0,
              'file' => '/app/phalcon/DiInterface.zep',
              'line' => 79,
              'char' => 49,
            ),
            2 => 
            array (
              'type' => 'parameter',
              'name' => 'shared',
              'const' => 0,
              'data-type' => 'bool',
              'mandatory' => 0,
              'default' => 
              array (
                'type' => 'bool',
                'value' => 'false',
                'file' => '/app/phalcon/DiInterface.zep',
                'line' => 79,
                'char' => 70,
              ),
              'reference' => 0,
              'file' => '/app/phalcon/DiInterface.zep',
              'line' => 79,
              'char' => 70,
            ),
          ),
          'docblock' => '**
     * Registers a service in the services container
     *',
          'return-type' => 
          array (
            'type' => 'return-type',
            'list' => 
            array (
              0 => 
              array (
                'type' => 'return-type-parameter',
                'cast' => 
                array (
                  'type' => 'variable',
                  'value' => 'ServiceInterface',
                  'file' => '/app/phalcon/DiInterface.zep',
                  'line' => 79,
                  'char' => 93,
                ),
                'collection' => 0,
                'file' => '/app/phalcon/DiInterface.zep',
                'line' => 79,
                'char' => 93,
              ),
            ),
            'void' => 0,
            'file' => '/app/phalcon/DiInterface.zep',
            'line' => 79,
            'char' => 93,
          ),
          'file' => '/app/phalcon/DiInterface.zep',
          'line' => 79,
          'last-line' => 84,
          'char' => 19,
        ),
        11 => 
        array (
          'visibility' => 
          array (
            0 => 'public',
            1 => 'static',
          ),
          'type' => 'method',
          'name' => 'setDefault',
          'parameters' => 
          array (
            0 => 
            array (
              'type' => 'parameter',
              'name' => 'container',
              'const' => 0,
              'data-type' => 'variable',
              'mandatory' => 0,
              'cast' => 
              array (
                'type' => 'variable',
                'value' => 'DiInterface',
                'file' => '/app/phalcon/DiInterface.zep',
                'line' => 85,
                'char' => 61,
              ),
              'reference' => 0,
              'file' => '/app/phalcon/DiInterface.zep',
              'line' => 85,
              'char' => 62,
            ),
          ),
          'docblock' => '**
     * Set a default dependency injection container to be obtained into static
     * methods
     *',
          'return-type' => 
          array (
            'type' => 'return-type',
            'void' => 1,
            'file' => '/app/phalcon/DiInterface.zep',
            'line' => 85,
            'char' => 71,
          ),
          'file' => '/app/phalcon/DiInterface.zep',
          'line' => 85,
          'last-line' => 89,
          'char' => 26,
        ),
        12 => 
        array (
          'visibility' => 
          array (
            0 => 'public',
          ),
          'type' => 'method',
          'name' => 'setRaw',
          'parameters' => 
          array (
            0 => 
            array (
              'type' => 'parameter',
              'name' => 'name',
              'const' => 0,
              'data-type' => 'string',
              'mandatory' => 1,
              'reference' => 0,
              'file' => '/app/phalcon/DiInterface.zep',
              'line' => 90,
              'char' => 40,
            ),
            1 => 
            array (
              'type' => 'parameter',
              'name' => 'rawDefinition',
              'const' => 0,
              'data-type' => 'variable',
              'mandatory' => 0,
              'cast' => 
              array (
                'type' => 'variable',
                'value' => 'ServiceInterface',
                'file' => '/app/phalcon/DiInterface.zep',
                'line' => 90,
                'char' => 73,
              ),
              'reference' => 0,
              'file' => '/app/phalcon/DiInterface.zep',
              'line' => 90,
              'char' => 74,
            ),
          ),
          'docblock' => '**
     * Sets a service using a raw Phalcon\\Di\\Service definition
     *',
          'return-type' => 
          array (
            'type' => 'return-type',
            'list' => 
            array (
              0 => 
              array (
                'type' => 'return-type-parameter',
                'cast' => 
                array (
                  'type' => 'variable',
                  'value' => 'ServiceInterface',
                  'file' => '/app/phalcon/DiInterface.zep',
                  'line' => 90,
                  'char' => 97,
                ),
                'collection' => 0,
                'file' => '/app/phalcon/DiInterface.zep',
                'line' => 90,
                'char' => 97,
              ),
            ),
            'void' => 0,
            'file' => '/app/phalcon/DiInterface.zep',
            'line' => 90,
            'char' => 97,
          ),
          'file' => '/app/phalcon/DiInterface.zep',
          'line' => 90,
          'last-line' => 94,
          'char' => 19,
        ),
        13 => 
        array (
          'visibility' => 
          array (
            0 => 'public',
          ),
          'type' => 'method',
          'name' => 'setShared',
          'parameters' => 
          array (
            0 => 
            array (
              'type' => 'parameter',
              'name' => 'name',
              'const' => 0,
              'data-type' => 'string',
              'mandatory' => 1,
              'reference' => 0,
              'file' => '/app/phalcon/DiInterface.zep',
              'line' => 95,
              'char' => 43,
            ),
            1 => 
            array (
              'type' => 'parameter',
              'name' => 'definition',
              'const' => 0,
              'data-type' => 'variable',
              'mandatory' => 0,
              'reference' => 0,
              'file' => '/app/phalcon/DiInterface.zep',
              'line' => 95,
              'char' => 55,
            ),
          ),
          'docblock' => '**
     * Registers an "always shared" service in the services container
     *',
          'return-type' => 
          array (
            'type' => 'return-type',
            'list' => 
            array (
              0 => 
              array (
                'type' => 'return-type-parameter',
                'cast' => 
                array (
                  'type' => 'variable',
                  'value' => 'ServiceInterface',
                  'file' => '/app/phalcon/DiInterface.zep',
                  'line' => 95,
                  'char' => 78,
                ),
                'collection' => 0,
                'file' => '/app/phalcon/DiInterface.zep',
                'line' => 95,
                'char' => 78,
              ),
            ),
            'void' => 0,
            'file' => '/app/phalcon/DiInterface.zep',
            'line' => 95,
            'char' => 78,
          ),
          'file' => '/app/phalcon/DiInterface.zep',
          'line' => 95,
          'last-line' => 96,
          'char' => 19,
        ),
      ),
      'file' => '/app/phalcon/DiInterface.zep',
      'line' => 96,
      'char' => 1,
    ),
    'file' => '/app/phalcon/DiInterface.zep',
    'line' => 0,
    'char' => 0,
  ),
);