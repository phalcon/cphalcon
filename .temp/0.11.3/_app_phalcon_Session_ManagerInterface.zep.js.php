<?php return array (
  0 => 
  array (
    'type' => 'comment',
    'value' => '**
 * This file is part of the Phalcon.
 *
 * (c) Phalcon Team <team@phalcon.com>
 *
 * For the full copyright and license information, please view the LICENSE
 * file that was distributed with this source code.
 *',
    'file' => '/app/phalcon/Session/ManagerInterface.zep',
    'line' => 11,
    'char' => 9,
  ),
  1 => 
  array (
    'type' => 'namespace',
    'name' => 'Phalcon\\Session',
    'file' => '/app/phalcon/Session/ManagerInterface.zep',
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
        'name' => 'InvalidArgumentException',
        'file' => '/app/phalcon/Session/ManagerInterface.zep',
        'line' => 13,
        'char' => 29,
      ),
    ),
    'file' => '/app/phalcon/Session/ManagerInterface.zep',
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
        'name' => 'RuntimeException',
        'file' => '/app/phalcon/Session/ManagerInterface.zep',
        'line' => 14,
        'char' => 21,
      ),
    ),
    'file' => '/app/phalcon/Session/ManagerInterface.zep',
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
        'name' => 'SessionHandlerInterface',
        'file' => '/app/phalcon/Session/ManagerInterface.zep',
        'line' => 15,
        'char' => 28,
      ),
    ),
    'file' => '/app/phalcon/Session/ManagerInterface.zep',
    'line' => 21,
    'char' => 2,
  ),
  5 => 
  array (
    'type' => 'comment',
    'value' => '**
 * Phalcon\\Session
 *
 * Interface for the Phalcon\\Session\\Manager
 *',
    'file' => '/app/phalcon/Session/ManagerInterface.zep',
    'line' => 22,
    'char' => 9,
  ),
  6 => 
  array (
    'type' => 'interface',
    'name' => 'ManagerInterface',
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
          'name' => '__get',
          'parameters' => 
          array (
            0 => 
            array (
              'type' => 'parameter',
              'name' => 'key',
              'const' => 0,
              'data-type' => 'string',
              'mandatory' => 0,
              'reference' => 0,
              'file' => '/app/phalcon/Session/ManagerInterface.zep',
              'line' => 31,
              'char' => 37,
            ),
          ),
          'docblock' => '**
     * Alias: Gets a session variable from an application context
     *',
          'return-type' => 
          array (
            'type' => 'return-type',
            'void' => 1,
            'file' => '/app/phalcon/Session/ManagerInterface.zep',
            'line' => 31,
            'char' => 46,
          ),
          'file' => '/app/phalcon/Session/ManagerInterface.zep',
          'line' => 31,
          'last-line' => 35,
          'char' => 19,
        ),
        1 => 
        array (
          'visibility' => 
          array (
            0 => 'public',
          ),
          'type' => 'method',
          'name' => '__isset',
          'parameters' => 
          array (
            0 => 
            array (
              'type' => 'parameter',
              'name' => 'key',
              'const' => 0,
              'data-type' => 'string',
              'mandatory' => 0,
              'reference' => 0,
              'file' => '/app/phalcon/Session/ManagerInterface.zep',
              'line' => 36,
              'char' => 39,
            ),
          ),
          'docblock' => '**
     * Alias: Check whether a session variable is set in an application context
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
                'file' => '/app/phalcon/Session/ManagerInterface.zep',
                'line' => 36,
                'char' => 48,
              ),
            ),
            'void' => 0,
            'file' => '/app/phalcon/Session/ManagerInterface.zep',
            'line' => 36,
            'char' => 48,
          ),
          'file' => '/app/phalcon/Session/ManagerInterface.zep',
          'line' => 36,
          'last-line' => 40,
          'char' => 19,
        ),
        2 => 
        array (
          'visibility' => 
          array (
            0 => 'public',
          ),
          'type' => 'method',
          'name' => '__set',
          'parameters' => 
          array (
            0 => 
            array (
              'type' => 'parameter',
              'name' => 'key',
              'const' => 0,
              'data-type' => 'string',
              'mandatory' => 0,
              'reference' => 0,
              'file' => '/app/phalcon/Session/ManagerInterface.zep',
              'line' => 41,
              'char' => 37,
            ),
            1 => 
            array (
              'type' => 'parameter',
              'name' => 'value',
              'const' => 0,
              'data-type' => 'variable',
              'mandatory' => 0,
              'reference' => 0,
              'file' => '/app/phalcon/Session/ManagerInterface.zep',
              'line' => 41,
              'char' => 48,
            ),
          ),
          'docblock' => '**
     * Alias: Sets a session variable in an application context
     *',
          'return-type' => 
          array (
            'type' => 'return-type',
            'void' => 1,
            'file' => '/app/phalcon/Session/ManagerInterface.zep',
            'line' => 41,
            'char' => 57,
          ),
          'file' => '/app/phalcon/Session/ManagerInterface.zep',
          'line' => 41,
          'last-line' => 45,
          'char' => 19,
        ),
        3 => 
        array (
          'visibility' => 
          array (
            0 => 'public',
          ),
          'type' => 'method',
          'name' => '__unset',
          'parameters' => 
          array (
            0 => 
            array (
              'type' => 'parameter',
              'name' => 'key',
              'const' => 0,
              'data-type' => 'string',
              'mandatory' => 0,
              'reference' => 0,
              'file' => '/app/phalcon/Session/ManagerInterface.zep',
              'line' => 46,
              'char' => 39,
            ),
          ),
          'docblock' => '**
     * Alias: Removes a session variable from an application context
     *',
          'return-type' => 
          array (
            'type' => 'return-type',
            'void' => 1,
            'file' => '/app/phalcon/Session/ManagerInterface.zep',
            'line' => 46,
            'char' => 48,
          ),
          'file' => '/app/phalcon/Session/ManagerInterface.zep',
          'line' => 46,
          'last-line' => 50,
          'char' => 19,
        ),
        4 => 
        array (
          'visibility' => 
          array (
            0 => 'public',
          ),
          'type' => 'method',
          'name' => 'exists',
          'docblock' => '**
     * Check whether the session has been started
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
                'file' => '/app/phalcon/Session/ManagerInterface.zep',
                'line' => 51,
                'char' => 37,
              ),
            ),
            'void' => 0,
            'file' => '/app/phalcon/Session/ManagerInterface.zep',
            'line' => 51,
            'char' => 37,
          ),
          'file' => '/app/phalcon/Session/ManagerInterface.zep',
          'line' => 51,
          'last-line' => 55,
          'char' => 19,
        ),
        5 => 
        array (
          'visibility' => 
          array (
            0 => 'public',
          ),
          'type' => 'method',
          'name' => 'destroy',
          'docblock' => '**
     * Destroy/end a session
     *',
          'return-type' => 
          array (
            'type' => 'return-type',
            'void' => 1,
            'file' => '/app/phalcon/Session/ManagerInterface.zep',
            'line' => 56,
            'char' => 38,
          ),
          'file' => '/app/phalcon/Session/ManagerInterface.zep',
          'line' => 56,
          'last-line' => 60,
          'char' => 19,
        ),
        6 => 
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
              'name' => 'key',
              'const' => 0,
              'data-type' => 'string',
              'mandatory' => 0,
              'reference' => 0,
              'file' => '/app/phalcon/Session/ManagerInterface.zep',
              'line' => 61,
              'char' => 35,
            ),
            1 => 
            array (
              'type' => 'parameter',
              'name' => 'defaultValue',
              'const' => 0,
              'data-type' => 'variable',
              'mandatory' => 0,
              'default' => 
              array (
                'type' => 'null',
                'file' => '/app/phalcon/Session/ManagerInterface.zep',
                'line' => 61,
                'char' => 60,
              ),
              'reference' => 0,
              'file' => '/app/phalcon/Session/ManagerInterface.zep',
              'line' => 61,
              'char' => 60,
            ),
            2 => 
            array (
              'type' => 'parameter',
              'name' => 'remove',
              'const' => 0,
              'data-type' => 'bool',
              'mandatory' => 0,
              'default' => 
              array (
                'type' => 'bool',
                'value' => 'false',
                'file' => '/app/phalcon/Session/ManagerInterface.zep',
                'line' => 61,
                'char' => 81,
              ),
              'reference' => 0,
              'file' => '/app/phalcon/Session/ManagerInterface.zep',
              'line' => 61,
              'char' => 81,
            ),
          ),
          'docblock' => '**
     * Gets a session variable from an application context
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
                'file' => '/app/phalcon/Session/ManagerInterface.zep',
                'line' => 61,
                'char' => 89,
              ),
            ),
            'void' => 0,
            'file' => '/app/phalcon/Session/ManagerInterface.zep',
            'line' => 61,
            'char' => 89,
          ),
          'file' => '/app/phalcon/Session/ManagerInterface.zep',
          'line' => 61,
          'last-line' => 65,
          'char' => 19,
        ),
        7 => 
        array (
          'visibility' => 
          array (
            0 => 'public',
          ),
          'type' => 'method',
          'name' => 'getId',
          'docblock' => '**
     * Returns the session id
     *',
          'return-type' => 
          array (
            'type' => 'return-type',
            'list' => 
            array (
              0 => 
              array (
                'type' => 'return-type-parameter',
                'data-type' => 'string',
                'mandatory' => 0,
                'file' => '/app/phalcon/Session/ManagerInterface.zep',
                'line' => 66,
                'char' => 38,
              ),
            ),
            'void' => 0,
            'file' => '/app/phalcon/Session/ManagerInterface.zep',
            'line' => 66,
            'char' => 38,
          ),
          'file' => '/app/phalcon/Session/ManagerInterface.zep',
          'line' => 66,
          'last-line' => 70,
          'char' => 19,
        ),
        8 => 
        array (
          'visibility' => 
          array (
            0 => 'public',
          ),
          'type' => 'method',
          'name' => 'getHandler',
          'docblock' => '**
     * Returns the stored session handler
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
                  'value' => 'SessionHandlerInterface',
                  'file' => '/app/phalcon/Session/ManagerInterface.zep',
                  'line' => 71,
                  'char' => 62,
                ),
                'collection' => 0,
                'file' => '/app/phalcon/Session/ManagerInterface.zep',
                'line' => 71,
                'char' => 62,
              ),
            ),
            'void' => 0,
            'file' => '/app/phalcon/Session/ManagerInterface.zep',
            'line' => 71,
            'char' => 62,
          ),
          'file' => '/app/phalcon/Session/ManagerInterface.zep',
          'line' => 71,
          'last-line' => 75,
          'char' => 19,
        ),
        9 => 
        array (
          'visibility' => 
          array (
            0 => 'public',
          ),
          'type' => 'method',
          'name' => 'getName',
          'docblock' => '**
     * Returns the name of the session
     *',
          'return-type' => 
          array (
            'type' => 'return-type',
            'list' => 
            array (
              0 => 
              array (
                'type' => 'return-type-parameter',
                'data-type' => 'string',
                'mandatory' => 0,
                'file' => '/app/phalcon/Session/ManagerInterface.zep',
                'line' => 76,
                'char' => 40,
              ),
            ),
            'void' => 0,
            'file' => '/app/phalcon/Session/ManagerInterface.zep',
            'line' => 76,
            'char' => 40,
          ),
          'file' => '/app/phalcon/Session/ManagerInterface.zep',
          'line' => 76,
          'last-line' => 80,
          'char' => 19,
        ),
        10 => 
        array (
          'visibility' => 
          array (
            0 => 'public',
          ),
          'type' => 'method',
          'name' => 'getOptions',
          'docblock' => '**
     * Get internal options
     *',
          'return-type' => 
          array (
            'type' => 'return-type',
            'list' => 
            array (
              0 => 
              array (
                'type' => 'return-type-parameter',
                'data-type' => 'array',
                'mandatory' => 0,
                'file' => '/app/phalcon/Session/ManagerInterface.zep',
                'line' => 81,
                'char' => 42,
              ),
            ),
            'void' => 0,
            'file' => '/app/phalcon/Session/ManagerInterface.zep',
            'line' => 81,
            'char' => 42,
          ),
          'file' => '/app/phalcon/Session/ManagerInterface.zep',
          'line' => 81,
          'last-line' => 85,
          'char' => 19,
        ),
        11 => 
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
              'name' => 'key',
              'const' => 0,
              'data-type' => 'string',
              'mandatory' => 0,
              'reference' => 0,
              'file' => '/app/phalcon/Session/ManagerInterface.zep',
              'line' => 86,
              'char' => 35,
            ),
          ),
          'docblock' => '**
     * Check whether a session variable is set in an application context
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
                'file' => '/app/phalcon/Session/ManagerInterface.zep',
                'line' => 86,
                'char' => 44,
              ),
            ),
            'void' => 0,
            'file' => '/app/phalcon/Session/ManagerInterface.zep',
            'line' => 86,
            'char' => 44,
          ),
          'file' => '/app/phalcon/Session/ManagerInterface.zep',
          'line' => 86,
          'last-line' => 90,
          'char' => 19,
        ),
        12 => 
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
              'name' => 'key',
              'const' => 0,
              'data-type' => 'string',
              'mandatory' => 0,
              'reference' => 0,
              'file' => '/app/phalcon/Session/ManagerInterface.zep',
              'line' => 91,
              'char' => 38,
            ),
          ),
          'docblock' => '**
     * Removes a session variable from an application context
     *',
          'return-type' => 
          array (
            'type' => 'return-type',
            'void' => 1,
            'file' => '/app/phalcon/Session/ManagerInterface.zep',
            'line' => 91,
            'char' => 47,
          ),
          'file' => '/app/phalcon/Session/ManagerInterface.zep',
          'line' => 91,
          'last-line' => 95,
          'char' => 19,
        ),
        13 => 
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
              'name' => 'key',
              'const' => 0,
              'data-type' => 'string',
              'mandatory' => 0,
              'reference' => 0,
              'file' => '/app/phalcon/Session/ManagerInterface.zep',
              'line' => 96,
              'char' => 35,
            ),
            1 => 
            array (
              'type' => 'parameter',
              'name' => 'value',
              'const' => 0,
              'data-type' => 'variable',
              'mandatory' => 0,
              'reference' => 0,
              'file' => '/app/phalcon/Session/ManagerInterface.zep',
              'line' => 96,
              'char' => 46,
            ),
          ),
          'docblock' => '**
     * Sets a session variable in an application context
     *',
          'return-type' => 
          array (
            'type' => 'return-type',
            'void' => 1,
            'file' => '/app/phalcon/Session/ManagerInterface.zep',
            'line' => 96,
            'char' => 55,
          ),
          'file' => '/app/phalcon/Session/ManagerInterface.zep',
          'line' => 96,
          'last-line' => 100,
          'char' => 19,
        ),
        14 => 
        array (
          'visibility' => 
          array (
            0 => 'public',
          ),
          'type' => 'method',
          'name' => 'setHandler',
          'parameters' => 
          array (
            0 => 
            array (
              'type' => 'parameter',
              'name' => 'handler',
              'const' => 0,
              'data-type' => 'variable',
              'mandatory' => 0,
              'cast' => 
              array (
                'type' => 'variable',
                'value' => 'SessionHandlerInterface',
                'file' => '/app/phalcon/Session/ManagerInterface.zep',
                'line' => 101,
                'char' => 64,
              ),
              'reference' => 0,
              'file' => '/app/phalcon/Session/ManagerInterface.zep',
              'line' => 101,
              'char' => 65,
            ),
          ),
          'docblock' => '**
     * Set the handler for the session
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
                  'value' => 'ManagerInterface',
                  'file' => '/app/phalcon/Session/ManagerInterface.zep',
                  'line' => 101,
                  'char' => 88,
                ),
                'collection' => 0,
                'file' => '/app/phalcon/Session/ManagerInterface.zep',
                'line' => 101,
                'char' => 88,
              ),
            ),
            'void' => 0,
            'file' => '/app/phalcon/Session/ManagerInterface.zep',
            'line' => 101,
            'char' => 88,
          ),
          'file' => '/app/phalcon/Session/ManagerInterface.zep',
          'line' => 101,
          'last-line' => 105,
          'char' => 19,
        ),
        15 => 
        array (
          'visibility' => 
          array (
            0 => 'public',
          ),
          'type' => 'method',
          'name' => 'setId',
          'parameters' => 
          array (
            0 => 
            array (
              'type' => 'parameter',
              'name' => 'id',
              'const' => 0,
              'data-type' => 'string',
              'mandatory' => 0,
              'reference' => 0,
              'file' => '/app/phalcon/Session/ManagerInterface.zep',
              'line' => 106,
              'char' => 36,
            ),
          ),
          'docblock' => '**
     * Set session Id
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
                  'value' => 'ManagerInterface',
                  'file' => '/app/phalcon/Session/ManagerInterface.zep',
                  'line' => 106,
                  'char' => 59,
                ),
                'collection' => 0,
                'file' => '/app/phalcon/Session/ManagerInterface.zep',
                'line' => 106,
                'char' => 59,
              ),
            ),
            'void' => 0,
            'file' => '/app/phalcon/Session/ManagerInterface.zep',
            'line' => 106,
            'char' => 59,
          ),
          'file' => '/app/phalcon/Session/ManagerInterface.zep',
          'line' => 106,
          'last-line' => 113,
          'char' => 19,
        ),
        16 => 
        array (
          'visibility' => 
          array (
            0 => 'public',
          ),
          'type' => 'method',
          'name' => 'setName',
          'parameters' => 
          array (
            0 => 
            array (
              'type' => 'parameter',
              'name' => 'name',
              'const' => 0,
              'data-type' => 'string',
              'mandatory' => 0,
              'reference' => 0,
              'file' => '/app/phalcon/Session/ManagerInterface.zep',
              'line' => 114,
              'char' => 40,
            ),
          ),
          'docblock' => '**
     * Set the session name. Throw exception if the session has started
     * and do not allow poop names
     *
     * @throws InvalidArgumentException
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
                  'value' => 'ManagerInterface',
                  'file' => '/app/phalcon/Session/ManagerInterface.zep',
                  'line' => 114,
                  'char' => 63,
                ),
                'collection' => 0,
                'file' => '/app/phalcon/Session/ManagerInterface.zep',
                'line' => 114,
                'char' => 63,
              ),
            ),
            'void' => 0,
            'file' => '/app/phalcon/Session/ManagerInterface.zep',
            'line' => 114,
            'char' => 63,
          ),
          'file' => '/app/phalcon/Session/ManagerInterface.zep',
          'line' => 114,
          'last-line' => 118,
          'char' => 19,
        ),
        17 => 
        array (
          'visibility' => 
          array (
            0 => 'public',
          ),
          'type' => 'method',
          'name' => 'setOptions',
          'parameters' => 
          array (
            0 => 
            array (
              'type' => 'parameter',
              'name' => 'options',
              'const' => 0,
              'data-type' => 'array',
              'mandatory' => 0,
              'reference' => 0,
              'file' => '/app/phalcon/Session/ManagerInterface.zep',
              'line' => 119,
              'char' => 45,
            ),
          ),
          'docblock' => '**
     * Sets session\'s options
     *',
          'return-type' => 
          array (
            'type' => 'return-type',
            'void' => 1,
            'file' => '/app/phalcon/Session/ManagerInterface.zep',
            'line' => 119,
            'char' => 54,
          ),
          'file' => '/app/phalcon/Session/ManagerInterface.zep',
          'line' => 119,
          'last-line' => 123,
          'char' => 19,
        ),
        18 => 
        array (
          'visibility' => 
          array (
            0 => 'public',
          ),
          'type' => 'method',
          'name' => 'status',
          'docblock' => '**
     * Returns the status of the current session.
     *',
          'return-type' => 
          array (
            'type' => 'return-type',
            'list' => 
            array (
              0 => 
              array (
                'type' => 'return-type-parameter',
                'data-type' => 'int',
                'mandatory' => 0,
                'file' => '/app/phalcon/Session/ManagerInterface.zep',
                'line' => 124,
                'char' => 36,
              ),
            ),
            'void' => 0,
            'file' => '/app/phalcon/Session/ManagerInterface.zep',
            'line' => 124,
            'char' => 36,
          ),
          'file' => '/app/phalcon/Session/ManagerInterface.zep',
          'line' => 124,
          'last-line' => 129,
          'char' => 19,
        ),
        19 => 
        array (
          'visibility' => 
          array (
            0 => 'public',
          ),
          'type' => 'method',
          'name' => 'start',
          'docblock' => '**
     * Starts the session (if headers are already sent the session will not be
     * started)
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
                'file' => '/app/phalcon/Session/ManagerInterface.zep',
                'line' => 130,
                'char' => 36,
              ),
            ),
            'void' => 0,
            'file' => '/app/phalcon/Session/ManagerInterface.zep',
            'line' => 130,
            'char' => 36,
          ),
          'file' => '/app/phalcon/Session/ManagerInterface.zep',
          'line' => 130,
          'last-line' => 134,
          'char' => 19,
        ),
        20 => 
        array (
          'visibility' => 
          array (
            0 => 'public',
          ),
          'type' => 'method',
          'name' => 'regenerateId',
          'parameters' => 
          array (
            0 => 
            array (
              'type' => 'parameter',
              'name' => 'deleteOldSession',
              'const' => 0,
              'data-type' => 'variable',
              'mandatory' => 0,
              'default' => 
              array (
                'type' => 'bool',
                'value' => 'true',
                'file' => '/app/phalcon/Session/ManagerInterface.zep',
                'line' => 135,
                'char' => 57,
              ),
              'reference' => 0,
              'file' => '/app/phalcon/Session/ManagerInterface.zep',
              'line' => 135,
              'char' => 57,
            ),
          ),
          'docblock' => '**
     * Regenerates the session id using the handler.
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
                  'value' => 'ManagerInterface',
                  'file' => '/app/phalcon/Session/ManagerInterface.zep',
                  'line' => 135,
                  'char' => 80,
                ),
                'collection' => 0,
                'file' => '/app/phalcon/Session/ManagerInterface.zep',
                'line' => 135,
                'char' => 80,
              ),
            ),
            'void' => 0,
            'file' => '/app/phalcon/Session/ManagerInterface.zep',
            'line' => 135,
            'char' => 80,
          ),
          'file' => '/app/phalcon/Session/ManagerInterface.zep',
          'line' => 135,
          'last-line' => 139,
          'char' => 19,
        ),
        21 => 
        array (
          'visibility' => 
          array (
            0 => 'public',
          ),
          'type' => 'method',
          'name' => 'registerHandler',
          'parameters' => 
          array (
            0 => 
            array (
              'type' => 'parameter',
              'name' => 'handler',
              'const' => 0,
              'data-type' => 'variable',
              'mandatory' => 0,
              'cast' => 
              array (
                'type' => 'variable',
                'value' => 'SessionHandlerInterface',
                'file' => '/app/phalcon/Session/ManagerInterface.zep',
                'line' => 140,
                'char' => 69,
              ),
              'reference' => 0,
              'file' => '/app/phalcon/Session/ManagerInterface.zep',
              'line' => 140,
              'char' => 70,
            ),
          ),
          'docblock' => '**
     * Registers a handler with the session
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
                'file' => '/app/phalcon/Session/ManagerInterface.zep',
                'line' => 140,
                'char' => 79,
              ),
            ),
            'void' => 0,
            'file' => '/app/phalcon/Session/ManagerInterface.zep',
            'line' => 140,
            'char' => 79,
          ),
          'file' => '/app/phalcon/Session/ManagerInterface.zep',
          'line' => 140,
          'last-line' => 141,
          'char' => 19,
        ),
      ),
      'constants' => 
      array (
        0 => 
        array (
          'type' => 'const',
          'name' => 'SESSION_ACTIVE',
          'default' => 
          array (
            'type' => 'int',
            'value' => '2',
            'file' => '/app/phalcon/Session/ManagerInterface.zep',
            'line' => 24,
            'char' => 31,
          ),
          'file' => '/app/phalcon/Session/ManagerInterface.zep',
          'line' => 25,
          'char' => 9,
        ),
        1 => 
        array (
          'type' => 'const',
          'name' => 'SESSION_DISABLED',
          'default' => 
          array (
            'type' => 'int',
            'value' => '0',
            'file' => '/app/phalcon/Session/ManagerInterface.zep',
            'line' => 25,
            'char' => 31,
          ),
          'file' => '/app/phalcon/Session/ManagerInterface.zep',
          'line' => 26,
          'char' => 9,
        ),
        2 => 
        array (
          'type' => 'const',
          'name' => 'SESSION_NONE',
          'default' => 
          array (
            'type' => 'int',
            'value' => '1',
            'file' => '/app/phalcon/Session/ManagerInterface.zep',
            'line' => 26,
            'char' => 31,
          ),
          'file' => '/app/phalcon/Session/ManagerInterface.zep',
          'line' => 30,
          'char' => 6,
        ),
      ),
      'file' => '/app/phalcon/Session/ManagerInterface.zep',
      'line' => 141,
      'char' => 1,
    ),
    'file' => '/app/phalcon/Session/ManagerInterface.zep',
    'line' => 0,
    'char' => 0,
  ),
);