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
    'file' => '/app/phalcon/Logger/Adapter/AbstractAdapter.zep',
    'line' => 11,
    'char' => 9,
  ),
  1 => 
  array (
    'type' => 'namespace',
    'name' => 'Phalcon\\Logger\\Adapter',
    'file' => '/app/phalcon/Logger/Adapter/AbstractAdapter.zep',
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
        'name' => 'Phalcon\\Logger\\Logger',
        'file' => '/app/phalcon/Logger/Adapter/AbstractAdapter.zep',
        'line' => 13,
        'char' => 26,
      ),
    ),
    'file' => '/app/phalcon/Logger/Adapter/AbstractAdapter.zep',
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
        'name' => 'Phalcon\\Logger\\Adapter\\AdapterInterface',
        'file' => '/app/phalcon/Logger/Adapter/AbstractAdapter.zep',
        'line' => 14,
        'char' => 44,
      ),
    ),
    'file' => '/app/phalcon/Logger/Adapter/AbstractAdapter.zep',
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
        'name' => 'Phalcon\\Logger\\Exception',
        'file' => '/app/phalcon/Logger/Adapter/AbstractAdapter.zep',
        'line' => 15,
        'char' => 29,
      ),
    ),
    'file' => '/app/phalcon/Logger/Adapter/AbstractAdapter.zep',
    'line' => 16,
    'char' => 3,
  ),
  5 => 
  array (
    'type' => 'use',
    'aliases' => 
    array (
      0 => 
      array (
        'name' => 'Phalcon\\Logger\\Formatter\\FormatterInterface',
        'file' => '/app/phalcon/Logger/Adapter/AbstractAdapter.zep',
        'line' => 16,
        'char' => 48,
      ),
    ),
    'file' => '/app/phalcon/Logger/Adapter/AbstractAdapter.zep',
    'line' => 17,
    'char' => 3,
  ),
  6 => 
  array (
    'type' => 'use',
    'aliases' => 
    array (
      0 => 
      array (
        'name' => 'Phalcon\\Logger\\Item',
        'file' => '/app/phalcon/Logger/Adapter/AbstractAdapter.zep',
        'line' => 17,
        'char' => 24,
      ),
    ),
    'file' => '/app/phalcon/Logger/Adapter/AbstractAdapter.zep',
    'line' => 19,
    'char' => 8,
  ),
  7 => 
  array (
    'type' => 'class',
    'name' => 'AbstractAdapter',
    'abstract' => 1,
    'final' => 0,
    'implements' => 
    array (
      0 => 
      array (
        'type' => 'variable',
        'value' => 'AdapterInterface',
        'file' => '/app/phalcon/Logger/Adapter/AbstractAdapter.zep',
        'line' => 20,
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
          'name' => 'defaultFormatter',
          'default' => 
          array (
            'type' => 'string',
            'value' => 'Line',
            'file' => '/app/phalcon/Logger/Adapter/AbstractAdapter.zep',
            'line' => 26,
            'char' => 38,
          ),
          'docblock' => '**
     * Name of the default formatter class
     *
     * @var string
     *',
          'file' => '/app/phalcon/Logger/Adapter/AbstractAdapter.zep',
          'line' => 32,
          'char' => 6,
        ),
        1 => 
        array (
          'visibility' => 
          array (
            0 => 'protected',
          ),
          'type' => 'property',
          'name' => 'formatter',
          'docblock' => '**
     * Formatter
     *
     * @var <FormatterInterface>
     *',
          'file' => '/app/phalcon/Logger/Adapter/AbstractAdapter.zep',
          'line' => 39,
          'char' => 6,
        ),
        2 => 
        array (
          'visibility' => 
          array (
            0 => 'protected',
          ),
          'type' => 'property',
          'name' => 'inTransaction',
          'default' => 
          array (
            'type' => 'bool',
            'value' => 'false',
            'file' => '/app/phalcon/Logger/Adapter/AbstractAdapter.zep',
            'line' => 40,
            'char' => 36,
          ),
          'docblock' => '**
     * Tells if there is an active transaction or not
     *
     * @var bool
     *',
          'file' => '/app/phalcon/Logger/Adapter/AbstractAdapter.zep',
          'line' => 46,
          'char' => 6,
        ),
        3 => 
        array (
          'visibility' => 
          array (
            0 => 'protected',
          ),
          'type' => 'property',
          'name' => 'queue',
          'default' => 
          array (
            'type' => 'empty-array',
            'file' => '/app/phalcon/Logger/Adapter/AbstractAdapter.zep',
            'line' => 47,
            'char' => 25,
          ),
          'docblock' => '**
     * Array with messages queued in the transaction
     *
     * @var array
     *',
          'file' => '/app/phalcon/Logger/Adapter/AbstractAdapter.zep',
          'line' => 51,
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
          'name' => '__destruct',
          'statements' => 
          array (
            0 => 
            array (
              'type' => 'if',
              'expr' => 
              array (
                'type' => 'property-access',
                'left' => 
                array (
                  'type' => 'variable',
                  'value' => 'this',
                  'file' => '/app/phalcon/Logger/Adapter/AbstractAdapter.zep',
                  'line' => 54,
                  'char' => 17,
                ),
                'right' => 
                array (
                  'type' => 'variable',
                  'value' => 'inTransaction',
                  'file' => '/app/phalcon/Logger/Adapter/AbstractAdapter.zep',
                  'line' => 54,
                  'char' => 32,
                ),
                'file' => '/app/phalcon/Logger/Adapter/AbstractAdapter.zep',
                'line' => 54,
                'char' => 32,
              ),
              'statements' => 
              array (
                0 => 
                array (
                  'type' => 'mcall',
                  'expr' => 
                  array (
                    'type' => 'mcall',
                    'variable' => 
                    array (
                      'type' => 'variable',
                      'value' => 'this',
                      'file' => '/app/phalcon/Logger/Adapter/AbstractAdapter.zep',
                      'line' => 55,
                      'char' => 18,
                    ),
                    'name' => 'commit',
                    'call-type' => 1,
                    'file' => '/app/phalcon/Logger/Adapter/AbstractAdapter.zep',
                    'line' => 55,
                    'char' => 27,
                  ),
                  'file' => '/app/phalcon/Logger/Adapter/AbstractAdapter.zep',
                  'line' => 56,
                  'char' => 9,
                ),
              ),
              'file' => '/app/phalcon/Logger/Adapter/AbstractAdapter.zep',
              'line' => 58,
              'char' => 12,
            ),
            1 => 
            array (
              'type' => 'mcall',
              'expr' => 
              array (
                'type' => 'mcall',
                'variable' => 
                array (
                  'type' => 'variable',
                  'value' => 'this',
                  'file' => '/app/phalcon/Logger/Adapter/AbstractAdapter.zep',
                  'line' => 58,
                  'char' => 14,
                ),
                'name' => 'close',
                'call-type' => 1,
                'file' => '/app/phalcon/Logger/Adapter/AbstractAdapter.zep',
                'line' => 58,
                'char' => 22,
              ),
              'file' => '/app/phalcon/Logger/Adapter/AbstractAdapter.zep',
              'line' => 59,
              'char' => 5,
            ),
          ),
          'docblock' => '**
     * Destructor cleanup
     *',
          'file' => '/app/phalcon/Logger/Adapter/AbstractAdapter.zep',
          'line' => 52,
          'last-line' => 63,
          'char' => 19,
        ),
        1 => 
        array (
          'visibility' => 
          array (
            0 => 'public',
          ),
          'type' => 'method',
          'name' => 'add',
          'parameters' => 
          array (
            0 => 
            array (
              'type' => 'parameter',
              'name' => 'item',
              'const' => 0,
              'data-type' => 'variable',
              'mandatory' => 0,
              'cast' => 
              array (
                'type' => 'variable',
                'value' => 'Item',
                'file' => '/app/phalcon/Logger/Adapter/AbstractAdapter.zep',
                'line' => 64,
                'char' => 35,
              ),
              'reference' => 0,
              'file' => '/app/phalcon/Logger/Adapter/AbstractAdapter.zep',
              'line' => 64,
              'char' => 36,
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
                  'assign-type' => 'object-property-append',
                  'operator' => 'assign',
                  'variable' => 'this',
                  'property' => 'queue',
                  'expr' => 
                  array (
                    'type' => 'variable',
                    'value' => 'item',
                    'file' => '/app/phalcon/Logger/Adapter/AbstractAdapter.zep',
                    'line' => 66,
                    'char' => 33,
                  ),
                  'file' => '/app/phalcon/Logger/Adapter/AbstractAdapter.zep',
                  'line' => 66,
                  'char' => 33,
                ),
              ),
              'file' => '/app/phalcon/Logger/Adapter/AbstractAdapter.zep',
              'line' => 68,
              'char' => 14,
            ),
            1 => 
            array (
              'type' => 'return',
              'expr' => 
              array (
                'type' => 'variable',
                'value' => 'this',
                'file' => '/app/phalcon/Logger/Adapter/AbstractAdapter.zep',
                'line' => 68,
                'char' => 20,
              ),
              'file' => '/app/phalcon/Logger/Adapter/AbstractAdapter.zep',
              'line' => 69,
              'char' => 5,
            ),
          ),
          'docblock' => '**
     * Adds a message to the queue
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
                  'value' => 'AdapterInterface',
                  'file' => '/app/phalcon/Logger/Adapter/AbstractAdapter.zep',
                  'line' => 65,
                  'char' => 5,
                ),
                'collection' => 0,
                'file' => '/app/phalcon/Logger/Adapter/AbstractAdapter.zep',
                'line' => 65,
                'char' => 5,
              ),
            ),
            'void' => 0,
            'file' => '/app/phalcon/Logger/Adapter/AbstractAdapter.zep',
            'line' => 65,
            'char' => 5,
          ),
          'file' => '/app/phalcon/Logger/Adapter/AbstractAdapter.zep',
          'line' => 64,
          'last-line' => 73,
          'char' => 19,
        ),
        2 => 
        array (
          'visibility' => 
          array (
            0 => 'public',
          ),
          'type' => 'method',
          'name' => 'begin',
          'statements' => 
          array (
            0 => 
            array (
              'type' => 'let',
              'assignments' => 
              array (
                0 => 
                array (
                  'assign-type' => 'object-property',
                  'operator' => 'assign',
                  'variable' => 'this',
                  'property' => 'inTransaction',
                  'expr' => 
                  array (
                    'type' => 'bool',
                    'value' => 'true',
                    'file' => '/app/phalcon/Logger/Adapter/AbstractAdapter.zep',
                    'line' => 76,
                    'char' => 39,
                  ),
                  'file' => '/app/phalcon/Logger/Adapter/AbstractAdapter.zep',
                  'line' => 76,
                  'char' => 39,
                ),
              ),
              'file' => '/app/phalcon/Logger/Adapter/AbstractAdapter.zep',
              'line' => 78,
              'char' => 14,
            ),
            1 => 
            array (
              'type' => 'return',
              'expr' => 
              array (
                'type' => 'variable',
                'value' => 'this',
                'file' => '/app/phalcon/Logger/Adapter/AbstractAdapter.zep',
                'line' => 78,
                'char' => 20,
              ),
              'file' => '/app/phalcon/Logger/Adapter/AbstractAdapter.zep',
              'line' => 79,
              'char' => 5,
            ),
          ),
          'docblock' => '**
     * Starts a transaction
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
                  'value' => 'AdapterInterface',
                  'file' => '/app/phalcon/Logger/Adapter/AbstractAdapter.zep',
                  'line' => 75,
                  'char' => 5,
                ),
                'collection' => 0,
                'file' => '/app/phalcon/Logger/Adapter/AbstractAdapter.zep',
                'line' => 75,
                'char' => 5,
              ),
            ),
            'void' => 0,
            'file' => '/app/phalcon/Logger/Adapter/AbstractAdapter.zep',
            'line' => 75,
            'char' => 5,
          ),
          'file' => '/app/phalcon/Logger/Adapter/AbstractAdapter.zep',
          'line' => 74,
          'last-line' => 83,
          'char' => 19,
        ),
        3 => 
        array (
          'visibility' => 
          array (
            0 => 'public',
          ),
          'type' => 'method',
          'name' => 'commit',
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
                  'variable' => 'inTransaction',
                  'file' => '/app/phalcon/Logger/Adapter/AbstractAdapter.zep',
                  'line' => 86,
                  'char' => 26,
                ),
                1 => 
                array (
                  'variable' => 'item',
                  'file' => '/app/phalcon/Logger/Adapter/AbstractAdapter.zep',
                  'line' => 86,
                  'char' => 32,
                ),
                2 => 
                array (
                  'variable' => 'queue',
                  'file' => '/app/phalcon/Logger/Adapter/AbstractAdapter.zep',
                  'line' => 86,
                  'char' => 39,
                ),
              ),
              'file' => '/app/phalcon/Logger/Adapter/AbstractAdapter.zep',
              'line' => 88,
              'char' => 11,
            ),
            1 => 
            array (
              'type' => 'let',
              'assignments' => 
              array (
                0 => 
                array (
                  'assign-type' => 'variable',
                  'operator' => 'assign',
                  'variable' => 'inTransaction',
                  'expr' => 
                  array (
                    'type' => 'property-access',
                    'left' => 
                    array (
                      'type' => 'variable',
                      'value' => 'this',
                      'file' => '/app/phalcon/Logger/Adapter/AbstractAdapter.zep',
                      'line' => 88,
                      'char' => 34,
                    ),
                    'right' => 
                    array (
                      'type' => 'variable',
                      'value' => 'inTransaction',
                      'file' => '/app/phalcon/Logger/Adapter/AbstractAdapter.zep',
                      'line' => 88,
                      'char' => 48,
                    ),
                    'file' => '/app/phalcon/Logger/Adapter/AbstractAdapter.zep',
                    'line' => 88,
                    'char' => 48,
                  ),
                  'file' => '/app/phalcon/Logger/Adapter/AbstractAdapter.zep',
                  'line' => 88,
                  'char' => 48,
                ),
                1 => 
                array (
                  'assign-type' => 'variable',
                  'operator' => 'assign',
                  'variable' => 'queue',
                  'expr' => 
                  array (
                    'type' => 'property-access',
                    'left' => 
                    array (
                      'type' => 'variable',
                      'value' => 'this',
                      'file' => '/app/phalcon/Logger/Adapter/AbstractAdapter.zep',
                      'line' => 89,
                      'char' => 34,
                    ),
                    'right' => 
                    array (
                      'type' => 'variable',
                      'value' => 'queue',
                      'file' => '/app/phalcon/Logger/Adapter/AbstractAdapter.zep',
                      'line' => 89,
                      'char' => 40,
                    ),
                    'file' => '/app/phalcon/Logger/Adapter/AbstractAdapter.zep',
                    'line' => 89,
                    'char' => 40,
                  ),
                  'file' => '/app/phalcon/Logger/Adapter/AbstractAdapter.zep',
                  'line' => 89,
                  'char' => 40,
                ),
              ),
              'file' => '/app/phalcon/Logger/Adapter/AbstractAdapter.zep',
              'line' => 91,
              'char' => 10,
            ),
            2 => 
            array (
              'type' => 'if',
              'expr' => 
              array (
                'type' => 'not',
                'left' => 
                array (
                  'type' => 'variable',
                  'value' => 'inTransaction',
                  'file' => '/app/phalcon/Logger/Adapter/AbstractAdapter.zep',
                  'line' => 91,
                  'char' => 27,
                ),
                'file' => '/app/phalcon/Logger/Adapter/AbstractAdapter.zep',
                'line' => 91,
                'char' => 27,
              ),
              'statements' => 
              array (
                0 => 
                array (
                  'type' => 'throw',
                  'expr' => 
                  array (
                    'type' => 'new',
                    'class' => 'Exception',
                    'dynamic' => 0,
                    'parameters' => 
                    array (
                      0 => 
                      array (
                        'parameter' => 
                        array (
                          'type' => 'string',
                          'value' => 'There is no active transaction',
                          'file' => '/app/phalcon/Logger/Adapter/AbstractAdapter.zep',
                          'line' => 92,
                          'char' => 63,
                        ),
                        'file' => '/app/phalcon/Logger/Adapter/AbstractAdapter.zep',
                        'line' => 92,
                        'char' => 63,
                      ),
                    ),
                    'file' => '/app/phalcon/Logger/Adapter/AbstractAdapter.zep',
                    'line' => 92,
                    'char' => 64,
                  ),
                  'file' => '/app/phalcon/Logger/Adapter/AbstractAdapter.zep',
                  'line' => 93,
                  'char' => 9,
                ),
              ),
              'file' => '/app/phalcon/Logger/Adapter/AbstractAdapter.zep',
              'line' => 98,
              'char' => 11,
            ),
            3 => 
            array (
              'type' => 'for',
              'expr' => 
              array (
                'type' => 'variable',
                'value' => 'queue',
                'file' => '/app/phalcon/Logger/Adapter/AbstractAdapter.zep',
                'line' => 98,
                'char' => 27,
              ),
              'value' => 'item',
              'reverse' => 0,
              'statements' => 
              array (
                0 => 
                array (
                  'type' => 'mcall',
                  'expr' => 
                  array (
                    'type' => 'mcall',
                    'variable' => 
                    array (
                      'type' => 'variable',
                      'value' => 'this',
                      'file' => '/app/phalcon/Logger/Adapter/AbstractAdapter.zep',
                      'line' => 99,
                      'char' => 18,
                    ),
                    'name' => 'process',
                    'call-type' => 1,
                    'parameters' => 
                    array (
                      0 => 
                      array (
                        'parameter' => 
                        array (
                          'type' => 'variable',
                          'value' => 'item',
                          'file' => '/app/phalcon/Logger/Adapter/AbstractAdapter.zep',
                          'line' => 99,
                          'char' => 31,
                        ),
                        'file' => '/app/phalcon/Logger/Adapter/AbstractAdapter.zep',
                        'line' => 99,
                        'char' => 31,
                      ),
                    ),
                    'file' => '/app/phalcon/Logger/Adapter/AbstractAdapter.zep',
                    'line' => 99,
                    'char' => 32,
                  ),
                  'file' => '/app/phalcon/Logger/Adapter/AbstractAdapter.zep',
                  'line' => 100,
                  'char' => 9,
                ),
              ),
              'file' => '/app/phalcon/Logger/Adapter/AbstractAdapter.zep',
              'line' => 103,
              'char' => 11,
            ),
            4 => 
            array (
              'type' => 'let',
              'assignments' => 
              array (
                0 => 
                array (
                  'assign-type' => 'variable',
                  'operator' => 'assign',
                  'variable' => 'inTransaction',
                  'expr' => 
                  array (
                    'type' => 'bool',
                    'value' => 'false',
                    'file' => '/app/phalcon/Logger/Adapter/AbstractAdapter.zep',
                    'line' => 103,
                    'char' => 34,
                  ),
                  'file' => '/app/phalcon/Logger/Adapter/AbstractAdapter.zep',
                  'line' => 103,
                  'char' => 34,
                ),
                1 => 
                array (
                  'assign-type' => 'object-property',
                  'operator' => 'assign',
                  'variable' => 'this',
                  'property' => 'queue',
                  'expr' => 
                  array (
                    'type' => 'empty-array',
                    'file' => '/app/phalcon/Logger/Adapter/AbstractAdapter.zep',
                    'line' => 104,
                    'char' => 29,
                  ),
                  'file' => '/app/phalcon/Logger/Adapter/AbstractAdapter.zep',
                  'line' => 104,
                  'char' => 29,
                ),
                2 => 
                array (
                  'assign-type' => 'object-property',
                  'operator' => 'assign',
                  'variable' => 'this',
                  'property' => 'inTransaction',
                  'expr' => 
                  array (
                    'type' => 'variable',
                    'value' => 'inTransaction',
                    'file' => '/app/phalcon/Logger/Adapter/AbstractAdapter.zep',
                    'line' => 105,
                    'char' => 48,
                  ),
                  'file' => '/app/phalcon/Logger/Adapter/AbstractAdapter.zep',
                  'line' => 105,
                  'char' => 48,
                ),
              ),
              'file' => '/app/phalcon/Logger/Adapter/AbstractAdapter.zep',
              'line' => 107,
              'char' => 14,
            ),
            5 => 
            array (
              'type' => 'return',
              'expr' => 
              array (
                'type' => 'variable',
                'value' => 'this',
                'file' => '/app/phalcon/Logger/Adapter/AbstractAdapter.zep',
                'line' => 107,
                'char' => 20,
              ),
              'file' => '/app/phalcon/Logger/Adapter/AbstractAdapter.zep',
              'line' => 108,
              'char' => 5,
            ),
          ),
          'docblock' => '**
     * Commits the internal transaction
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
                  'value' => 'AdapterInterface',
                  'file' => '/app/phalcon/Logger/Adapter/AbstractAdapter.zep',
                  'line' => 85,
                  'char' => 5,
                ),
                'collection' => 0,
                'file' => '/app/phalcon/Logger/Adapter/AbstractAdapter.zep',
                'line' => 85,
                'char' => 5,
              ),
            ),
            'void' => 0,
            'file' => '/app/phalcon/Logger/Adapter/AbstractAdapter.zep',
            'line' => 85,
            'char' => 5,
          ),
          'file' => '/app/phalcon/Logger/Adapter/AbstractAdapter.zep',
          'line' => 84,
          'last-line' => 110,
          'char' => 19,
        ),
        4 => 
        array (
          'visibility' => 
          array (
            0 => 'public',
          ),
          'type' => 'method',
          'name' => 'getFormatter',
          'statements' => 
          array (
            0 => 
            array (
              'type' => 'declare',
              'data-type' => 'string',
              'variables' => 
              array (
                0 => 
                array (
                  'variable' => 'className',
                  'file' => '/app/phalcon/Logger/Adapter/AbstractAdapter.zep',
                  'line' => 112,
                  'char' => 25,
                ),
              ),
              'file' => '/app/phalcon/Logger/Adapter/AbstractAdapter.zep',
              'line' => 114,
              'char' => 10,
            ),
            1 => 
            array (
              'type' => 'if',
              'expr' => 
              array (
                'type' => 'not-identical',
                'left' => 
                array (
                  'type' => 'typeof',
                  'left' => 
                  array (
                    'type' => 'property-access',
                    'left' => 
                    array (
                      'type' => 'variable',
                      'value' => 'this',
                      'file' => '/app/phalcon/Logger/Adapter/AbstractAdapter.zep',
                      'line' => 114,
                      'char' => 24,
                    ),
                    'right' => 
                    array (
                      'type' => 'variable',
                      'value' => 'formatter',
                      'file' => '/app/phalcon/Logger/Adapter/AbstractAdapter.zep',
                      'line' => 114,
                      'char' => 37,
                    ),
                    'file' => '/app/phalcon/Logger/Adapter/AbstractAdapter.zep',
                    'line' => 114,
                    'char' => 37,
                  ),
                  'file' => '/app/phalcon/Logger/Adapter/AbstractAdapter.zep',
                  'line' => 114,
                  'char' => 37,
                ),
                'right' => 
                array (
                  'type' => 'string',
                  'value' => 'object',
                  'file' => '/app/phalcon/Logger/Adapter/AbstractAdapter.zep',
                  'line' => 114,
                  'char' => 46,
                ),
                'file' => '/app/phalcon/Logger/Adapter/AbstractAdapter.zep',
                'line' => 114,
                'char' => 46,
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
                      'variable' => 'className',
                      'expr' => 
                      array (
                        'type' => 'concat',
                        'left' => 
                        array (
                          'type' => 'string',
                          'value' => 'Phalcon\\\\Logger\\\\Formatter\\\\',
                          'file' => '/app/phalcon/Logger/Adapter/AbstractAdapter.zep',
                          'line' => 115,
                          'char' => 58,
                        ),
                        'right' => 
                        array (
                          'type' => 'property-access',
                          'left' => 
                          array (
                            'type' => 'variable',
                            'value' => 'this',
                            'file' => '/app/phalcon/Logger/Adapter/AbstractAdapter.zep',
                            'line' => 115,
                            'char' => 65,
                          ),
                          'right' => 
                          array (
                            'type' => 'variable',
                            'value' => 'defaultFormatter',
                            'file' => '/app/phalcon/Logger/Adapter/AbstractAdapter.zep',
                            'line' => 115,
                            'char' => 82,
                          ),
                          'file' => '/app/phalcon/Logger/Adapter/AbstractAdapter.zep',
                          'line' => 115,
                          'char' => 82,
                        ),
                        'file' => '/app/phalcon/Logger/Adapter/AbstractAdapter.zep',
                        'line' => 115,
                        'char' => 82,
                      ),
                      'file' => '/app/phalcon/Logger/Adapter/AbstractAdapter.zep',
                      'line' => 115,
                      'char' => 82,
                    ),
                  ),
                  'file' => '/app/phalcon/Logger/Adapter/AbstractAdapter.zep',
                  'line' => 117,
                  'char' => 15,
                ),
                1 => 
                array (
                  'type' => 'let',
                  'assignments' => 
                  array (
                    0 => 
                    array (
                      'assign-type' => 'object-property',
                      'operator' => 'assign',
                      'variable' => 'this',
                      'property' => 'formatter',
                      'expr' => 
                      array (
                        'type' => 'new',
                        'class' => 'className',
                        'dynamic' => 1,
                        'file' => '/app/phalcon/Logger/Adapter/AbstractAdapter.zep',
                        'line' => 117,
                        'char' => 52,
                      ),
                      'file' => '/app/phalcon/Logger/Adapter/AbstractAdapter.zep',
                      'line' => 117,
                      'char' => 52,
                    ),
                  ),
                  'file' => '/app/phalcon/Logger/Adapter/AbstractAdapter.zep',
                  'line' => 118,
                  'char' => 9,
                ),
              ),
              'file' => '/app/phalcon/Logger/Adapter/AbstractAdapter.zep',
              'line' => 120,
              'char' => 14,
            ),
            2 => 
            array (
              'type' => 'return',
              'expr' => 
              array (
                'type' => 'property-access',
                'left' => 
                array (
                  'type' => 'variable',
                  'value' => 'this',
                  'file' => '/app/phalcon/Logger/Adapter/AbstractAdapter.zep',
                  'line' => 120,
                  'char' => 21,
                ),
                'right' => 
                array (
                  'type' => 'variable',
                  'value' => 'formatter',
                  'file' => '/app/phalcon/Logger/Adapter/AbstractAdapter.zep',
                  'line' => 120,
                  'char' => 31,
                ),
                'file' => '/app/phalcon/Logger/Adapter/AbstractAdapter.zep',
                'line' => 120,
                'char' => 31,
              ),
              'file' => '/app/phalcon/Logger/Adapter/AbstractAdapter.zep',
              'line' => 121,
              'char' => 5,
            ),
          ),
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
                  'value' => 'FormatterInterface',
                  'file' => '/app/phalcon/Logger/Adapter/AbstractAdapter.zep',
                  'line' => 111,
                  'char' => 5,
                ),
                'collection' => 0,
                'file' => '/app/phalcon/Logger/Adapter/AbstractAdapter.zep',
                'line' => 111,
                'char' => 5,
              ),
            ),
            'void' => 0,
            'file' => '/app/phalcon/Logger/Adapter/AbstractAdapter.zep',
            'line' => 111,
            'char' => 5,
          ),
          'file' => '/app/phalcon/Logger/Adapter/AbstractAdapter.zep',
          'line' => 110,
          'last-line' => 125,
          'char' => 19,
        ),
        5 => 
        array (
          'visibility' => 
          array (
            0 => 'public',
          ),
          'type' => 'method',
          'name' => 'inTransaction',
          'statements' => 
          array (
            0 => 
            array (
              'type' => 'return',
              'expr' => 
              array (
                'type' => 'property-access',
                'left' => 
                array (
                  'type' => 'variable',
                  'value' => 'this',
                  'file' => '/app/phalcon/Logger/Adapter/AbstractAdapter.zep',
                  'line' => 128,
                  'char' => 21,
                ),
                'right' => 
                array (
                  'type' => 'variable',
                  'value' => 'inTransaction',
                  'file' => '/app/phalcon/Logger/Adapter/AbstractAdapter.zep',
                  'line' => 128,
                  'char' => 35,
                ),
                'file' => '/app/phalcon/Logger/Adapter/AbstractAdapter.zep',
                'line' => 128,
                'char' => 35,
              ),
              'file' => '/app/phalcon/Logger/Adapter/AbstractAdapter.zep',
              'line' => 129,
              'char' => 5,
            ),
          ),
          'docblock' => '**
     * Returns the whether the logger is currently in an active transaction or not
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
                'file' => '/app/phalcon/Logger/Adapter/AbstractAdapter.zep',
                'line' => 127,
                'char' => 5,
              ),
            ),
            'void' => 0,
            'file' => '/app/phalcon/Logger/Adapter/AbstractAdapter.zep',
            'line' => 127,
            'char' => 5,
          ),
          'file' => '/app/phalcon/Logger/Adapter/AbstractAdapter.zep',
          'line' => 126,
          'last-line' => 133,
          'char' => 19,
        ),
        6 => 
        array (
          'visibility' => 
          array (
            0 => 'abstract',
            1 => 'public',
          ),
          'type' => 'method',
          'name' => 'process',
          'parameters' => 
          array (
            0 => 
            array (
              'type' => 'parameter',
              'name' => 'item',
              'const' => 0,
              'data-type' => 'variable',
              'mandatory' => 0,
              'cast' => 
              array (
                'type' => 'variable',
                'value' => 'Item',
                'file' => '/app/phalcon/Logger/Adapter/AbstractAdapter.zep',
                'line' => 134,
                'char' => 48,
              ),
              'reference' => 0,
              'file' => '/app/phalcon/Logger/Adapter/AbstractAdapter.zep',
              'line' => 134,
              'char' => 49,
            ),
          ),
          'docblock' => '**
      * Processes the message in the adapter
      *',
          'return-type' => 
          array (
            'type' => 'return-type',
            'void' => 1,
            'file' => '/app/phalcon/Logger/Adapter/AbstractAdapter.zep',
            'line' => 134,
            'char' => 58,
          ),
          'file' => '/app/phalcon/Logger/Adapter/AbstractAdapter.zep',
          'line' => 134,
          'last-line' => 138,
          'char' => 28,
        ),
        7 => 
        array (
          'visibility' => 
          array (
            0 => 'public',
          ),
          'type' => 'method',
          'name' => 'rollback',
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
                  'variable' => 'inTransaction',
                  'file' => '/app/phalcon/Logger/Adapter/AbstractAdapter.zep',
                  'line' => 141,
                  'char' => 26,
                ),
              ),
              'file' => '/app/phalcon/Logger/Adapter/AbstractAdapter.zep',
              'line' => 143,
              'char' => 11,
            ),
            1 => 
            array (
              'type' => 'let',
              'assignments' => 
              array (
                0 => 
                array (
                  'assign-type' => 'variable',
                  'operator' => 'assign',
                  'variable' => 'inTransaction',
                  'expr' => 
                  array (
                    'type' => 'property-access',
                    'left' => 
                    array (
                      'type' => 'variable',
                      'value' => 'this',
                      'file' => '/app/phalcon/Logger/Adapter/AbstractAdapter.zep',
                      'line' => 143,
                      'char' => 34,
                    ),
                    'right' => 
                    array (
                      'type' => 'variable',
                      'value' => 'inTransaction',
                      'file' => '/app/phalcon/Logger/Adapter/AbstractAdapter.zep',
                      'line' => 143,
                      'char' => 48,
                    ),
                    'file' => '/app/phalcon/Logger/Adapter/AbstractAdapter.zep',
                    'line' => 143,
                    'char' => 48,
                  ),
                  'file' => '/app/phalcon/Logger/Adapter/AbstractAdapter.zep',
                  'line' => 143,
                  'char' => 48,
                ),
              ),
              'file' => '/app/phalcon/Logger/Adapter/AbstractAdapter.zep',
              'line' => 145,
              'char' => 10,
            ),
            2 => 
            array (
              'type' => 'if',
              'expr' => 
              array (
                'type' => 'not',
                'left' => 
                array (
                  'type' => 'variable',
                  'value' => 'inTransaction',
                  'file' => '/app/phalcon/Logger/Adapter/AbstractAdapter.zep',
                  'line' => 145,
                  'char' => 27,
                ),
                'file' => '/app/phalcon/Logger/Adapter/AbstractAdapter.zep',
                'line' => 145,
                'char' => 27,
              ),
              'statements' => 
              array (
                0 => 
                array (
                  'type' => 'throw',
                  'expr' => 
                  array (
                    'type' => 'new',
                    'class' => 'Exception',
                    'dynamic' => 0,
                    'parameters' => 
                    array (
                      0 => 
                      array (
                        'parameter' => 
                        array (
                          'type' => 'string',
                          'value' => 'There is no active transaction',
                          'file' => '/app/phalcon/Logger/Adapter/AbstractAdapter.zep',
                          'line' => 146,
                          'char' => 63,
                        ),
                        'file' => '/app/phalcon/Logger/Adapter/AbstractAdapter.zep',
                        'line' => 146,
                        'char' => 63,
                      ),
                    ),
                    'file' => '/app/phalcon/Logger/Adapter/AbstractAdapter.zep',
                    'line' => 146,
                    'char' => 64,
                  ),
                  'file' => '/app/phalcon/Logger/Adapter/AbstractAdapter.zep',
                  'line' => 147,
                  'char' => 9,
                ),
              ),
              'file' => '/app/phalcon/Logger/Adapter/AbstractAdapter.zep',
              'line' => 149,
              'char' => 11,
            ),
            3 => 
            array (
              'type' => 'let',
              'assignments' => 
              array (
                0 => 
                array (
                  'assign-type' => 'object-property',
                  'operator' => 'assign',
                  'variable' => 'this',
                  'property' => 'queue',
                  'expr' => 
                  array (
                    'type' => 'empty-array',
                    'file' => '/app/phalcon/Logger/Adapter/AbstractAdapter.zep',
                    'line' => 149,
                    'char' => 37,
                  ),
                  'file' => '/app/phalcon/Logger/Adapter/AbstractAdapter.zep',
                  'line' => 149,
                  'char' => 37,
                ),
                1 => 
                array (
                  'assign-type' => 'variable',
                  'operator' => 'assign',
                  'variable' => 'inTransaction',
                  'expr' => 
                  array (
                    'type' => 'bool',
                    'value' => 'false',
                    'file' => '/app/phalcon/Logger/Adapter/AbstractAdapter.zep',
                    'line' => 150,
                    'char' => 40,
                  ),
                  'file' => '/app/phalcon/Logger/Adapter/AbstractAdapter.zep',
                  'line' => 150,
                  'char' => 40,
                ),
                2 => 
                array (
                  'assign-type' => 'object-property',
                  'operator' => 'assign',
                  'variable' => 'this',
                  'property' => 'inTransaction',
                  'expr' => 
                  array (
                    'type' => 'variable',
                    'value' => 'inTransaction',
                    'file' => '/app/phalcon/Logger/Adapter/AbstractAdapter.zep',
                    'line' => 151,
                    'char' => 48,
                  ),
                  'file' => '/app/phalcon/Logger/Adapter/AbstractAdapter.zep',
                  'line' => 151,
                  'char' => 48,
                ),
              ),
              'file' => '/app/phalcon/Logger/Adapter/AbstractAdapter.zep',
              'line' => 153,
              'char' => 14,
            ),
            4 => 
            array (
              'type' => 'return',
              'expr' => 
              array (
                'type' => 'variable',
                'value' => 'this',
                'file' => '/app/phalcon/Logger/Adapter/AbstractAdapter.zep',
                'line' => 153,
                'char' => 20,
              ),
              'file' => '/app/phalcon/Logger/Adapter/AbstractAdapter.zep',
              'line' => 154,
              'char' => 5,
            ),
          ),
          'docblock' => '**
     * Rollbacks the internal transaction
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
                  'value' => 'AdapterInterface',
                  'file' => '/app/phalcon/Logger/Adapter/AbstractAdapter.zep',
                  'line' => 140,
                  'char' => 5,
                ),
                'collection' => 0,
                'file' => '/app/phalcon/Logger/Adapter/AbstractAdapter.zep',
                'line' => 140,
                'char' => 5,
              ),
            ),
            'void' => 0,
            'file' => '/app/phalcon/Logger/Adapter/AbstractAdapter.zep',
            'line' => 140,
            'char' => 5,
          ),
          'file' => '/app/phalcon/Logger/Adapter/AbstractAdapter.zep',
          'line' => 139,
          'last-line' => 158,
          'char' => 19,
        ),
        8 => 
        array (
          'visibility' => 
          array (
            0 => 'public',
          ),
          'type' => 'method',
          'name' => 'setFormatter',
          'parameters' => 
          array (
            0 => 
            array (
              'type' => 'parameter',
              'name' => 'formatter',
              'const' => 0,
              'data-type' => 'variable',
              'mandatory' => 0,
              'cast' => 
              array (
                'type' => 'variable',
                'value' => 'FormatterInterface',
                'file' => '/app/phalcon/Logger/Adapter/AbstractAdapter.zep',
                'line' => 159,
                'char' => 63,
              ),
              'reference' => 0,
              'file' => '/app/phalcon/Logger/Adapter/AbstractAdapter.zep',
              'line' => 159,
              'char' => 64,
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
                  'assign-type' => 'object-property',
                  'operator' => 'assign',
                  'variable' => 'this',
                  'property' => 'formatter',
                  'expr' => 
                  array (
                    'type' => 'variable',
                    'value' => 'formatter',
                    'file' => '/app/phalcon/Logger/Adapter/AbstractAdapter.zep',
                    'line' => 161,
                    'char' => 40,
                  ),
                  'file' => '/app/phalcon/Logger/Adapter/AbstractAdapter.zep',
                  'line' => 161,
                  'char' => 40,
                ),
              ),
              'file' => '/app/phalcon/Logger/Adapter/AbstractAdapter.zep',
              'line' => 163,
              'char' => 14,
            ),
            1 => 
            array (
              'type' => 'return',
              'expr' => 
              array (
                'type' => 'variable',
                'value' => 'this',
                'file' => '/app/phalcon/Logger/Adapter/AbstractAdapter.zep',
                'line' => 163,
                'char' => 20,
              ),
              'file' => '/app/phalcon/Logger/Adapter/AbstractAdapter.zep',
              'line' => 164,
              'char' => 5,
            ),
          ),
          'docblock' => '**
     * Sets the message formatter
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
                  'value' => 'AdapterInterface',
                  'file' => '/app/phalcon/Logger/Adapter/AbstractAdapter.zep',
                  'line' => 160,
                  'char' => 5,
                ),
                'collection' => 0,
                'file' => '/app/phalcon/Logger/Adapter/AbstractAdapter.zep',
                'line' => 160,
                'char' => 5,
              ),
            ),
            'void' => 0,
            'file' => '/app/phalcon/Logger/Adapter/AbstractAdapter.zep',
            'line' => 160,
            'char' => 5,
          ),
          'file' => '/app/phalcon/Logger/Adapter/AbstractAdapter.zep',
          'line' => 159,
          'last-line' => 165,
          'char' => 19,
        ),
      ),
      'file' => '/app/phalcon/Logger/Adapter/AbstractAdapter.zep',
      'line' => 19,
      'char' => 14,
    ),
    'file' => '/app/phalcon/Logger/Adapter/AbstractAdapter.zep',
    'line' => 19,
    'char' => 14,
  ),
);