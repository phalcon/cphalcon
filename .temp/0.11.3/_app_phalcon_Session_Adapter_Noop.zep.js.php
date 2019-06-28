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
    'file' => '/app/phalcon/Session/Adapter/Noop.zep',
    'line' => 11,
    'char' => 9,
  ),
  1 => 
  array (
    'type' => 'namespace',
    'name' => 'Phalcon\\Session\\Adapter',
    'file' => '/app/phalcon/Session/Adapter/Noop.zep',
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
        'name' => 'SessionHandlerInterface',
        'file' => '/app/phalcon/Session/Adapter/Noop.zep',
        'line' => 13,
        'char' => 28,
      ),
    ),
    'file' => '/app/phalcon/Session/Adapter/Noop.zep',
    'line' => 30,
    'char' => 2,
  ),
  3 => 
  array (
    'type' => 'comment',
    'value' => '**
 * Phalcon\\Session\\Adapter\\Noop
 *
 * This is an "empty" or null adapter. It can be used for testing or any
 * other purpose that no session needs to be invoked
 *
 * ```php
 * <?php
 *
 * use Phalcon\\Session\\Manager;
 * use Phalcon\\Session\\Adapter\\Noop;
 *
 * $session = new Manager();
 * $session->setHandler(new Noop());
 * ```
 *',
    'file' => '/app/phalcon/Session/Adapter/Noop.zep',
    'line' => 31,
    'char' => 5,
  ),
  4 => 
  array (
    'type' => 'class',
    'name' => 'Noop',
    'abstract' => 0,
    'final' => 0,
    'implements' => 
    array (
      0 => 
      array (
        'type' => 'variable',
        'value' => 'SessionHandlerInterface',
        'file' => '/app/phalcon/Session/Adapter/Noop.zep',
        'line' => 32,
        'char' => 1,
      ),
    ),
    'definition' => 
    array (
      'properties' => 
      array (
        0 => 
        array (
          'visibility' => 
          array (
            0 => 'protected',
          ),
          'type' => 'property',
          'name' => 'connection',
          'docblock' => '**
     * The connection of some adapters
     *',
          'file' => '/app/phalcon/Session/Adapter/Noop.zep',
          'line' => 42,
          'char' => 6,
        ),
        1 => 
        array (
          'visibility' => 
          array (
            0 => 'protected',
          ),
          'type' => 'property',
          'name' => 'options',
          'default' => 
          array (
            'type' => 'empty-array',
            'file' => '/app/phalcon/Session/Adapter/Noop.zep',
            'line' => 43,
            'char' => 27,
          ),
          'docblock' => '**
     * Session options
     *
     * @var array
     *',
          'file' => '/app/phalcon/Session/Adapter/Noop.zep',
          'line' => 49,
          'char' => 6,
        ),
        2 => 
        array (
          'visibility' => 
          array (
            0 => 'protected',
          ),
          'type' => 'property',
          'name' => 'prefix',
          'default' => 
          array (
            'type' => 'string',
            'value' => '',
            'file' => '/app/phalcon/Session/Adapter/Noop.zep',
            'line' => 50,
            'char' => 24,
          ),
          'docblock' => '**
     * Session prefix
     *
     * @var string
     *',
          'file' => '/app/phalcon/Session/Adapter/Noop.zep',
          'line' => 56,
          'char' => 6,
        ),
        3 => 
        array (
          'visibility' => 
          array (
            0 => 'protected',
          ),
          'type' => 'property',
          'name' => 'ttl',
          'default' => 
          array (
            'type' => 'int',
            'value' => '8600',
            'file' => '/app/phalcon/Session/Adapter/Noop.zep',
            'line' => 57,
            'char' => 25,
          ),
          'docblock' => '**
     * Time To Live
     *
     * @var int
     *',
          'file' => '/app/phalcon/Session/Adapter/Noop.zep',
          'line' => 61,
          'char' => 6,
        ),
      ),
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
              'name' => 'options',
              'const' => 0,
              'data-type' => 'array',
              'mandatory' => 1,
              'default' => 
              array (
                'type' => 'empty-array',
                'file' => '/app/phalcon/Session/Adapter/Noop.zep',
                'line' => 62,
                'char' => 52,
              ),
              'reference' => 0,
              'file' => '/app/phalcon/Session/Adapter/Noop.zep',
              'line' => 62,
              'char' => 52,
            ),
          ),
          'statements' => 
          array (
            0 => 
            array (
              'type' => 'declare',
              'data-type' => 'variable',
              'variables' => 
              array (
                0 => 
                array (
                  'variable' => 'prefix',
                  'file' => '/app/phalcon/Session/Adapter/Noop.zep',
                  'line' => 64,
                  'char' => 19,
                ),
              ),
              'file' => '/app/phalcon/Session/Adapter/Noop.zep',
              'line' => 66,
              'char' => 10,
            ),
            1 => 
            array (
              'type' => 'if',
              'expr' => 
              array (
                'type' => 'not',
                'left' => 
                array (
                  'type' => 'fetch',
                  'left' => 
                  array (
                    'type' => 'variable',
                    'value' => 'prefix',
                    'file' => '/app/phalcon/Session/Adapter/Noop.zep',
                    'line' => 66,
                    'char' => 43,
                  ),
                  'right' => 
                  array (
                    'type' => 'array-access',
                    'left' => 
                    array (
                      'type' => 'variable',
                      'value' => 'options',
                      'file' => '/app/phalcon/Session/Adapter/Noop.zep',
                      'line' => 66,
                      'char' => 34,
                    ),
                    'right' => 
                    array (
                      'type' => 'string',
                      'value' => 'prefix',
                      'file' => '/app/phalcon/Session/Adapter/Noop.zep',
                      'line' => 66,
                      'char' => 41,
                    ),
                    'file' => '/app/phalcon/Session/Adapter/Noop.zep',
                    'line' => 66,
                    'char' => 43,
                  ),
                  'file' => '/app/phalcon/Session/Adapter/Noop.zep',
                  'line' => 66,
                  'char' => 43,
                ),
                'file' => '/app/phalcon/Session/Adapter/Noop.zep',
                'line' => 66,
                'char' => 43,
              ),
              'statements' => 
              array (
                0 => 
                array (
                  'type' => 'let',
                  'assignments' => 
                  array (
                    0 => 
                    array (
                      'assign-type' => 'variable',
                      'operator' => 'assign',
                      'variable' => 'prefix',
                      'expr' => 
                      array (
                        'type' => 'string',
                        'value' => '',
                        'file' => '/app/phalcon/Session/Adapter/Noop.zep',
                        'line' => 67,
                        'char' => 26,
                      ),
                      'file' => '/app/phalcon/Session/Adapter/Noop.zep',
                      'line' => 67,
                      'char' => 26,
                    ),
                  ),
                  'file' => '/app/phalcon/Session/Adapter/Noop.zep',
                  'line' => 68,
                  'char' => 9,
                ),
              ),
              'file' => '/app/phalcon/Session/Adapter/Noop.zep',
              'line' => 70,
              'char' => 11,
            ),
            2 => 
            array (
              'type' => 'let',
              'assignments' => 
              array (
                0 => 
                array (
                  'assign-type' => 'object-property',
                  'operator' => 'assign',
                  'variable' => 'this',
                  'property' => 'prefix',
                  'expr' => 
                  array (
                    'type' => 'variable',
                    'value' => 'prefix',
                    'file' => '/app/phalcon/Session/Adapter/Noop.zep',
                    'line' => 70,
                    'char' => 35,
                  ),
                  'file' => '/app/phalcon/Session/Adapter/Noop.zep',
                  'line' => 70,
                  'char' => 35,
                ),
                1 => 
                array (
                  'assign-type' => 'object-property',
                  'operator' => 'assign',
                  'variable' => 'this',
                  'property' => 'options',
                  'expr' => 
                  array (
                    'type' => 'variable',
                    'value' => 'options',
                    'file' => '/app/phalcon/Session/Adapter/Noop.zep',
                    'line' => 71,
                    'char' => 36,
                  ),
                  'file' => '/app/phalcon/Session/Adapter/Noop.zep',
                  'line' => 71,
                  'char' => 36,
                ),
              ),
              'file' => '/app/phalcon/Session/Adapter/Noop.zep',
              'line' => 72,
              'char' => 5,
            ),
          ),
          'docblock' => '**
     * Constructor
     *',
          'return-type' => 
          array (
            'type' => 'return-type',
            'void' => 1,
            'file' => '/app/phalcon/Session/Adapter/Noop.zep',
            'line' => 63,
            'char' => 5,
          ),
          'file' => '/app/phalcon/Session/Adapter/Noop.zep',
          'line' => 62,
          'last-line' => 76,
          'char' => 19,
        ),
        1 => 
        array (
          'visibility' => 
          array (
            0 => 'public',
          ),
          'type' => 'method',
          'name' => 'close',
          'statements' => 
          array (
            0 => 
            array (
              'type' => 'return',
              'expr' => 
              array (
                'type' => 'bool',
                'value' => 'true',
                'file' => '/app/phalcon/Session/Adapter/Noop.zep',
                'line' => 79,
                'char' => 20,
              ),
              'file' => '/app/phalcon/Session/Adapter/Noop.zep',
              'line' => 80,
              'char' => 5,
            ),
          ),
          'docblock' => '**
     * Close
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
                'file' => '/app/phalcon/Session/Adapter/Noop.zep',
                'line' => 78,
                'char' => 5,
              ),
            ),
            'void' => 0,
            'file' => '/app/phalcon/Session/Adapter/Noop.zep',
            'line' => 78,
            'char' => 5,
          ),
          'file' => '/app/phalcon/Session/Adapter/Noop.zep',
          'line' => 77,
          'last-line' => 84,
          'char' => 19,
        ),
        2 => 
        array (
          'visibility' => 
          array (
            0 => 'public',
          ),
          'type' => 'method',
          'name' => 'destroy',
          'parameters' => 
          array (
            0 => 
            array (
              'type' => 'parameter',
              'name' => 'id',
              'const' => 0,
              'data-type' => 'variable',
              'mandatory' => 0,
              'reference' => 0,
              'file' => '/app/phalcon/Session/Adapter/Noop.zep',
              'line' => 85,
              'char' => 35,
            ),
          ),
          'statements' => 
          array (
            0 => 
            array (
              'type' => 'return',
              'expr' => 
              array (
                'type' => 'bool',
                'value' => 'true',
                'file' => '/app/phalcon/Session/Adapter/Noop.zep',
                'line' => 87,
                'char' => 20,
              ),
              'file' => '/app/phalcon/Session/Adapter/Noop.zep',
              'line' => 88,
              'char' => 5,
            ),
          ),
          'docblock' => '**
     * Destroy
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
                'file' => '/app/phalcon/Session/Adapter/Noop.zep',
                'line' => 86,
                'char' => 5,
              ),
            ),
            'void' => 0,
            'file' => '/app/phalcon/Session/Adapter/Noop.zep',
            'line' => 86,
            'char' => 5,
          ),
          'file' => '/app/phalcon/Session/Adapter/Noop.zep',
          'line' => 85,
          'last-line' => 92,
          'char' => 19,
        ),
        3 => 
        array (
          'visibility' => 
          array (
            0 => 'public',
          ),
          'type' => 'method',
          'name' => 'gc',
          'parameters' => 
          array (
            0 => 
            array (
              'type' => 'parameter',
              'name' => 'maxlifetime',
              'const' => 0,
              'data-type' => 'variable',
              'mandatory' => 0,
              'reference' => 0,
              'file' => '/app/phalcon/Session/Adapter/Noop.zep',
              'line' => 93,
              'char' => 39,
            ),
          ),
          'statements' => 
          array (
            0 => 
            array (
              'type' => 'return',
              'expr' => 
              array (
                'type' => 'bool',
                'value' => 'true',
                'file' => '/app/phalcon/Session/Adapter/Noop.zep',
                'line' => 95,
                'char' => 20,
              ),
              'file' => '/app/phalcon/Session/Adapter/Noop.zep',
              'line' => 96,
              'char' => 5,
            ),
          ),
          'docblock' => '**
     * Garbage Collector
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
                'file' => '/app/phalcon/Session/Adapter/Noop.zep',
                'line' => 94,
                'char' => 5,
              ),
            ),
            'void' => 0,
            'file' => '/app/phalcon/Session/Adapter/Noop.zep',
            'line' => 94,
            'char' => 5,
          ),
          'file' => '/app/phalcon/Session/Adapter/Noop.zep',
          'line' => 93,
          'last-line' => 100,
          'char' => 19,
        ),
        4 => 
        array (
          'visibility' => 
          array (
            0 => 'public',
          ),
          'type' => 'method',
          'name' => 'read',
          'parameters' => 
          array (
            0 => 
            array (
              'type' => 'parameter',
              'name' => 'id',
              'const' => 0,
              'data-type' => 'variable',
              'mandatory' => 0,
              'reference' => 0,
              'file' => '/app/phalcon/Session/Adapter/Noop.zep',
              'line' => 101,
              'char' => 32,
            ),
          ),
          'statements' => 
          array (
            0 => 
            array (
              'type' => 'return',
              'expr' => 
              array (
                'type' => 'string',
                'value' => '',
                'file' => '/app/phalcon/Session/Adapter/Noop.zep',
                'line' => 103,
                'char' => 16,
              ),
              'file' => '/app/phalcon/Session/Adapter/Noop.zep',
              'line' => 104,
              'char' => 5,
            ),
          ),
          'docblock' => '**
     * Read
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
                'file' => '/app/phalcon/Session/Adapter/Noop.zep',
                'line' => 102,
                'char' => 5,
              ),
            ),
            'void' => 0,
            'file' => '/app/phalcon/Session/Adapter/Noop.zep',
            'line' => 102,
            'char' => 5,
          ),
          'file' => '/app/phalcon/Session/Adapter/Noop.zep',
          'line' => 101,
          'last-line' => 108,
          'char' => 19,
        ),
        5 => 
        array (
          'visibility' => 
          array (
            0 => 'public',
          ),
          'type' => 'method',
          'name' => 'open',
          'parameters' => 
          array (
            0 => 
            array (
              'type' => 'parameter',
              'name' => 'savePath',
              'const' => 0,
              'data-type' => 'variable',
              'mandatory' => 0,
              'reference' => 0,
              'file' => '/app/phalcon/Session/Adapter/Noop.zep',
              'line' => 109,
              'char' => 38,
            ),
            1 => 
            array (
              'type' => 'parameter',
              'name' => 'sessionName',
              'const' => 0,
              'data-type' => 'variable',
              'mandatory' => 0,
              'reference' => 0,
              'file' => '/app/phalcon/Session/Adapter/Noop.zep',
              'line' => 109,
              'char' => 55,
            ),
          ),
          'statements' => 
          array (
            0 => 
            array (
              'type' => 'return',
              'expr' => 
              array (
                'type' => 'bool',
                'value' => 'true',
                'file' => '/app/phalcon/Session/Adapter/Noop.zep',
                'line' => 111,
                'char' => 20,
              ),
              'file' => '/app/phalcon/Session/Adapter/Noop.zep',
              'line' => 112,
              'char' => 5,
            ),
          ),
          'docblock' => '**
     * Open
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
                'file' => '/app/phalcon/Session/Adapter/Noop.zep',
                'line' => 110,
                'char' => 5,
              ),
            ),
            'void' => 0,
            'file' => '/app/phalcon/Session/Adapter/Noop.zep',
            'line' => 110,
            'char' => 5,
          ),
          'file' => '/app/phalcon/Session/Adapter/Noop.zep',
          'line' => 109,
          'last-line' => 116,
          'char' => 19,
        ),
        6 => 
        array (
          'visibility' => 
          array (
            0 => 'public',
          ),
          'type' => 'method',
          'name' => 'write',
          'parameters' => 
          array (
            0 => 
            array (
              'type' => 'parameter',
              'name' => 'id',
              'const' => 0,
              'data-type' => 'variable',
              'mandatory' => 0,
              'reference' => 0,
              'file' => '/app/phalcon/Session/Adapter/Noop.zep',
              'line' => 117,
              'char' => 33,
            ),
            1 => 
            array (
              'type' => 'parameter',
              'name' => 'data',
              'const' => 0,
              'data-type' => 'variable',
              'mandatory' => 0,
              'reference' => 0,
              'file' => '/app/phalcon/Session/Adapter/Noop.zep',
              'line' => 117,
              'char' => 43,
            ),
          ),
          'statements' => 
          array (
            0 => 
            array (
              'type' => 'return',
              'expr' => 
              array (
                'type' => 'bool',
                'value' => 'true',
                'file' => '/app/phalcon/Session/Adapter/Noop.zep',
                'line' => 119,
                'char' => 20,
              ),
              'file' => '/app/phalcon/Session/Adapter/Noop.zep',
              'line' => 120,
              'char' => 5,
            ),
          ),
          'docblock' => '**
     * Write
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
                'file' => '/app/phalcon/Session/Adapter/Noop.zep',
                'line' => 118,
                'char' => 5,
              ),
            ),
            'void' => 0,
            'file' => '/app/phalcon/Session/Adapter/Noop.zep',
            'line' => 118,
            'char' => 5,
          ),
          'file' => '/app/phalcon/Session/Adapter/Noop.zep',
          'line' => 117,
          'last-line' => 124,
          'char' => 19,
        ),
        7 => 
        array (
          'visibility' => 
          array (
            0 => 'protected',
          ),
          'type' => 'method',
          'name' => 'getPrefixedName',
          'parameters' => 
          array (
            0 => 
            array (
              'type' => 'parameter',
              'name' => 'name',
              'const' => 0,
              'data-type' => 'variable',
              'mandatory' => 0,
              'reference' => 0,
              'file' => '/app/phalcon/Session/Adapter/Noop.zep',
              'line' => 125,
              'char' => 48,
            ),
          ),
          'statements' => 
          array (
            0 => 
            array (
              'type' => 'let',
              'assignments' => 
              array (
                0 => 
                array (
                  'assign-type' => 'variable',
                  'operator' => 'assign',
                  'variable' => 'name',
                  'expr' => 
                  array (
                    'type' => 'cast',
                    'left' => 'string',
                    'right' => 
                    array (
                      'type' => 'variable',
                      'value' => 'name',
                      'file' => '/app/phalcon/Session/Adapter/Noop.zep',
                      'line' => 127,
                      'char' => 33,
                    ),
                    'file' => '/app/phalcon/Session/Adapter/Noop.zep',
                    'line' => 127,
                    'char' => 33,
                  ),
                  'file' => '/app/phalcon/Session/Adapter/Noop.zep',
                  'line' => 127,
                  'char' => 33,
                ),
              ),
              'file' => '/app/phalcon/Session/Adapter/Noop.zep',
              'line' => 129,
              'char' => 14,
            ),
            1 => 
            array (
              'type' => 'return',
              'expr' => 
              array (
                'type' => 'concat',
                'left' => 
                array (
                  'type' => 'property-access',
                  'left' => 
                  array (
                    'type' => 'variable',
                    'value' => 'this',
                    'file' => '/app/phalcon/Session/Adapter/Noop.zep',
                    'line' => 129,
                    'char' => 21,
                  ),
                  'right' => 
                  array (
                    'type' => 'variable',
                    'value' => 'prefix',
                    'file' => '/app/phalcon/Session/Adapter/Noop.zep',
                    'line' => 129,
                    'char' => 29,
                  ),
                  'file' => '/app/phalcon/Session/Adapter/Noop.zep',
                  'line' => 129,
                  'char' => 29,
                ),
                'right' => 
                array (
                  'type' => 'variable',
                  'value' => 'name',
                  'file' => '/app/phalcon/Session/Adapter/Noop.zep',
                  'line' => 129,
                  'char' => 35,
                ),
                'file' => '/app/phalcon/Session/Adapter/Noop.zep',
                'line' => 129,
                'char' => 35,
              ),
              'file' => '/app/phalcon/Session/Adapter/Noop.zep',
              'line' => 130,
              'char' => 5,
            ),
          ),
          'docblock' => '**
     * Helper method to get the name prefixed
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
                'file' => '/app/phalcon/Session/Adapter/Noop.zep',
                'line' => 126,
                'char' => 5,
              ),
            ),
            'void' => 0,
            'file' => '/app/phalcon/Session/Adapter/Noop.zep',
            'line' => 126,
            'char' => 5,
          ),
          'file' => '/app/phalcon/Session/Adapter/Noop.zep',
          'line' => 125,
          'last-line' => 131,
          'char' => 22,
        ),
      ),
      'file' => '/app/phalcon/Session/Adapter/Noop.zep',
      'line' => 31,
      'char' => 5,
    ),
    'file' => '/app/phalcon/Session/Adapter/Noop.zep',
    'line' => 31,
    'char' => 5,
  ),
);