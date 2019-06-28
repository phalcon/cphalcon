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
    'file' => '/app/phalcon/Logger/Item.zep',
    'line' => 11,
    'char' => 9,
  ),
  1 => 
  array (
    'type' => 'namespace',
    'name' => 'Phalcon\\Logger',
    'file' => '/app/phalcon/Logger/Item.zep',
    'line' => 18,
    'char' => 2,
  ),
  2 => 
  array (
    'type' => 'comment',
    'value' => '**
 * Phalcon\\Logger\\Item
 *
 * Represents each item in a logging transaction
 *
 *',
    'file' => '/app/phalcon/Logger/Item.zep',
    'line' => 19,
    'char' => 5,
  ),
  3 => 
  array (
    'type' => 'class',
    'name' => 'Item',
    'abstract' => 0,
    'final' => 0,
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
          'name' => 'context',
          'shortcuts' => 
          array (
            0 => 
            array (
              'type' => 'shortcut',
              'name' => 'get',
              'file' => '/app/phalcon/Logger/Item.zep',
              'line' => 21,
              'char' => 29,
            ),
          ),
          'file' => '/app/phalcon/Logger/Item.zep',
          'line' => 27,
          'char' => 6,
        ),
        1 => 
        array (
          'visibility' => 
          array (
            0 => 'protected',
          ),
          'type' => 'property',
          'name' => 'message',
          'docblock' => '**
     * Log message
     *
     * @var string
     *',
          'shortcuts' => 
          array (
            0 => 
            array (
              'type' => 'shortcut',
              'name' => 'get',
              'file' => '/app/phalcon/Logger/Item.zep',
              'line' => 28,
              'char' => 29,
            ),
          ),
          'file' => '/app/phalcon/Logger/Item.zep',
          'line' => 34,
          'char' => 6,
        ),
        2 => 
        array (
          'visibility' => 
          array (
            0 => 'protected',
          ),
          'type' => 'property',
          'name' => 'name',
          'docblock' => '**
     * Log message
     *
     * @var string
     *',
          'shortcuts' => 
          array (
            0 => 
            array (
              'type' => 'shortcut',
              'name' => 'get',
              'file' => '/app/phalcon/Logger/Item.zep',
              'line' => 35,
              'char' => 26,
            ),
          ),
          'file' => '/app/phalcon/Logger/Item.zep',
          'line' => 41,
          'char' => 6,
        ),
        3 => 
        array (
          'visibility' => 
          array (
            0 => 'protected',
          ),
          'type' => 'property',
          'name' => 'time',
          'docblock' => '**
     * Log timestamp
     *
     * @var integer
     *',
          'shortcuts' => 
          array (
            0 => 
            array (
              'type' => 'shortcut',
              'name' => 'get',
              'file' => '/app/phalcon/Logger/Item.zep',
              'line' => 42,
              'char' => 26,
            ),
          ),
          'file' => '/app/phalcon/Logger/Item.zep',
          'line' => 48,
          'char' => 6,
        ),
        4 => 
        array (
          'visibility' => 
          array (
            0 => 'protected',
          ),
          'type' => 'property',
          'name' => 'type',
          'docblock' => '**
     * Log type
     *
     * @var integer
     *',
          'shortcuts' => 
          array (
            0 => 
            array (
              'type' => 'shortcut',
              'name' => 'get',
              'file' => '/app/phalcon/Logger/Item.zep',
              'line' => 49,
              'char' => 26,
            ),
          ),
          'file' => '/app/phalcon/Logger/Item.zep',
          'line' => 53,
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
              'name' => 'message',
              'const' => 0,
              'data-type' => 'string',
              'mandatory' => 0,
              'reference' => 0,
              'file' => '/app/phalcon/Logger/Item.zep',
              'line' => 54,
              'char' => 47,
            ),
            1 => 
            array (
              'type' => 'parameter',
              'name' => 'name',
              'const' => 0,
              'data-type' => 'string',
              'mandatory' => 0,
              'reference' => 0,
              'file' => '/app/phalcon/Logger/Item.zep',
              'line' => 54,
              'char' => 60,
            ),
            2 => 
            array (
              'type' => 'parameter',
              'name' => 'type',
              'const' => 0,
              'data-type' => 'int',
              'mandatory' => 0,
              'reference' => 0,
              'file' => '/app/phalcon/Logger/Item.zep',
              'line' => 54,
              'char' => 70,
            ),
            3 => 
            array (
              'type' => 'parameter',
              'name' => 'time',
              'const' => 0,
              'data-type' => 'int',
              'mandatory' => 0,
              'default' => 
              array (
                'type' => 'int',
                'value' => '0',
                'file' => '/app/phalcon/Logger/Item.zep',
                'line' => 54,
                'char' => 84,
              ),
              'reference' => 0,
              'file' => '/app/phalcon/Logger/Item.zep',
              'line' => 54,
              'char' => 84,
            ),
            4 => 
            array (
              'type' => 'parameter',
              'name' => 'context',
              'const' => 0,
              'data-type' => 'variable',
              'mandatory' => 0,
              'default' => 
              array (
                'type' => 'empty-array',
                'file' => '/app/phalcon/Logger/Item.zep',
                'line' => 54,
                'char' => 102,
              ),
              'reference' => 0,
              'file' => '/app/phalcon/Logger/Item.zep',
              'line' => 54,
              'char' => 102,
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
                  'property' => 'message',
                  'expr' => 
                  array (
                    'type' => 'variable',
                    'value' => 'message',
                    'file' => '/app/phalcon/Logger/Item.zep',
                    'line' => 56,
                    'char' => 36,
                  ),
                  'file' => '/app/phalcon/Logger/Item.zep',
                  'line' => 56,
                  'char' => 36,
                ),
                1 => 
                array (
                  'assign-type' => 'object-property',
                  'operator' => 'assign',
                  'variable' => 'this',
                  'property' => 'name',
                  'expr' => 
                  array (
                    'type' => 'variable',
                    'value' => 'name',
                    'file' => '/app/phalcon/Logger/Item.zep',
                    'line' => 57,
                    'char' => 33,
                  ),
                  'file' => '/app/phalcon/Logger/Item.zep',
                  'line' => 57,
                  'char' => 33,
                ),
                2 => 
                array (
                  'assign-type' => 'object-property',
                  'operator' => 'assign',
                  'variable' => 'this',
                  'property' => 'type',
                  'expr' => 
                  array (
                    'type' => 'variable',
                    'value' => 'type',
                    'file' => '/app/phalcon/Logger/Item.zep',
                    'line' => 58,
                    'char' => 33,
                  ),
                  'file' => '/app/phalcon/Logger/Item.zep',
                  'line' => 58,
                  'char' => 33,
                ),
                3 => 
                array (
                  'assign-type' => 'object-property',
                  'operator' => 'assign',
                  'variable' => 'this',
                  'property' => 'time',
                  'expr' => 
                  array (
                    'type' => 'variable',
                    'value' => 'time',
                    'file' => '/app/phalcon/Logger/Item.zep',
                    'line' => 59,
                    'char' => 33,
                  ),
                  'file' => '/app/phalcon/Logger/Item.zep',
                  'line' => 59,
                  'char' => 33,
                ),
              ),
              'file' => '/app/phalcon/Logger/Item.zep',
              'line' => 61,
              'char' => 10,
            ),
            1 => 
            array (
              'type' => 'if',
              'expr' => 
              array (
                'type' => 'equals',
                'left' => 
                array (
                  'type' => 'typeof',
                  'left' => 
                  array (
                    'type' => 'variable',
                    'value' => 'context',
                    'file' => '/app/phalcon/Logger/Item.zep',
                    'line' => 61,
                    'char' => 28,
                  ),
                  'file' => '/app/phalcon/Logger/Item.zep',
                  'line' => 61,
                  'char' => 28,
                ),
                'right' => 
                array (
                  'type' => 'string',
                  'value' => 'array',
                  'file' => '/app/phalcon/Logger/Item.zep',
                  'line' => 61,
                  'char' => 36,
                ),
                'file' => '/app/phalcon/Logger/Item.zep',
                'line' => 61,
                'char' => 36,
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
                      'property' => 'context',
                      'expr' => 
                      array (
                        'type' => 'variable',
                        'value' => 'context',
                        'file' => '/app/phalcon/Logger/Item.zep',
                        'line' => 62,
                        'char' => 40,
                      ),
                      'file' => '/app/phalcon/Logger/Item.zep',
                      'line' => 62,
                      'char' => 40,
                    ),
                  ),
                  'file' => '/app/phalcon/Logger/Item.zep',
                  'line' => 63,
                  'char' => 9,
                ),
              ),
              'file' => '/app/phalcon/Logger/Item.zep',
              'line' => 64,
              'char' => 5,
            ),
          ),
          'docblock' => '**
     * Phalcon\\Logger\\Item constructor
     *',
          'file' => '/app/phalcon/Logger/Item.zep',
          'line' => 54,
          'last-line' => 65,
          'char' => 19,
        ),
      ),
      'file' => '/app/phalcon/Logger/Item.zep',
      'line' => 19,
      'char' => 5,
    ),
    'file' => '/app/phalcon/Logger/Item.zep',
    'line' => 19,
    'char' => 5,
  ),
);