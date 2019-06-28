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
    'file' => '/app/phalcon/Db/RawValue.zep',
    'line' => 11,
    'char' => 9,
  ),
  1 => 
  array (
    'type' => 'namespace',
    'name' => 'Phalcon\\Db',
    'file' => '/app/phalcon/Db/RawValue.zep',
    'line' => 26,
    'char' => 2,
  ),
  2 => 
  array (
    'type' => 'comment',
    'value' => '**
 * This class allows to insert/update raw data without quoting or formatting.
 *
 * The next example shows how to use the MySQL now() function as a field value.
 *
 *```php
 * $subscriber = new Subscribers();
 *
 * $subscriber->email     = "andres@phalconphp.com";
 * $subscriber->createdAt = new \\Phalcon\\Db\\RawValue("now()");
 *
 * $subscriber->save();
 *```
 *',
    'file' => '/app/phalcon/Db/RawValue.zep',
    'line' => 27,
    'char' => 5,
  ),
  3 => 
  array (
    'type' => 'class',
    'name' => 'RawValue',
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
          'name' => 'value',
          'docblock' => '**
     * Raw value without quoting or formatting
     *
     * @var string
     *',
          'shortcuts' => 
          array (
            0 => 
            array (
              'type' => 'shortcut',
              'name' => 'get',
              'file' => '/app/phalcon/Db/RawValue.zep',
              'line' => 34,
              'char' => 26,
            ),
            1 => 
            array (
              'type' => 'shortcut',
              'name' => '__toString',
              'file' => '/app/phalcon/Db/RawValue.zep',
              'line' => 34,
              'char' => 39,
            ),
          ),
          'file' => '/app/phalcon/Db/RawValue.zep',
          'line' => 38,
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
              'name' => 'value',
              'const' => 0,
              'data-type' => 'variable',
              'mandatory' => 0,
              'reference' => 0,
              'file' => '/app/phalcon/Db/RawValue.zep',
              'line' => 39,
              'char' => 42,
            ),
          ),
          'statements' => 
          array (
            0 => 
            array (
              'type' => 'if',
              'expr' => 
              array (
                'type' => 'identical',
                'left' => 
                array (
                  'type' => 'variable',
                  'value' => 'value',
                  'file' => '/app/phalcon/Db/RawValue.zep',
                  'line' => 41,
                  'char' => 20,
                ),
                'right' => 
                array (
                  'type' => 'string',
                  'value' => '',
                  'file' => '/app/phalcon/Db/RawValue.zep',
                  'line' => 41,
                  'char' => 23,
                ),
                'file' => '/app/phalcon/Db/RawValue.zep',
                'line' => 41,
                'char' => 23,
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
                      'property' => 'value',
                      'expr' => 
                      array (
                        'type' => 'string',
                        'value' => '\'\'',
                        'file' => '/app/phalcon/Db/RawValue.zep',
                        'line' => 42,
                        'char' => 33,
                      ),
                      'file' => '/app/phalcon/Db/RawValue.zep',
                      'line' => 42,
                      'char' => 33,
                    ),
                  ),
                  'file' => '/app/phalcon/Db/RawValue.zep',
                  'line' => 43,
                  'char' => 9,
                ),
              ),
              'elseif_statements' => 
              array (
                0 => 
                array (
                  'type' => 'if',
                  'expr' => 
                  array (
                    'type' => 'identical',
                    'left' => 
                    array (
                      'type' => 'variable',
                      'value' => 'value',
                      'file' => '/app/phalcon/Db/RawValue.zep',
                      'line' => 43,
                      'char' => 26,
                    ),
                    'right' => 
                    array (
                      'type' => 'null',
                      'file' => '/app/phalcon/Db/RawValue.zep',
                      'line' => 43,
                      'char' => 33,
                    ),
                    'file' => '/app/phalcon/Db/RawValue.zep',
                    'line' => 43,
                    'char' => 33,
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
                          'property' => 'value',
                          'expr' => 
                          array (
                            'type' => 'string',
                            'value' => 'NULL',
                            'file' => '/app/phalcon/Db/RawValue.zep',
                            'line' => 44,
                            'char' => 35,
                          ),
                          'file' => '/app/phalcon/Db/RawValue.zep',
                          'line' => 44,
                          'char' => 35,
                        ),
                      ),
                      'file' => '/app/phalcon/Db/RawValue.zep',
                      'line' => 45,
                      'char' => 9,
                    ),
                  ),
                  'file' => '/app/phalcon/Db/RawValue.zep',
                  'line' => 45,
                  'char' => 14,
                ),
              ),
              'else_statements' => 
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
                      'property' => 'value',
                      'expr' => 
                      array (
                        'type' => 'cast',
                        'left' => 'string',
                        'right' => 
                        array (
                          'type' => 'variable',
                          'value' => 'value',
                          'file' => '/app/phalcon/Db/RawValue.zep',
                          'line' => 46,
                          'char' => 45,
                        ),
                        'file' => '/app/phalcon/Db/RawValue.zep',
                        'line' => 46,
                        'char' => 45,
                      ),
                      'file' => '/app/phalcon/Db/RawValue.zep',
                      'line' => 46,
                      'char' => 45,
                    ),
                  ),
                  'file' => '/app/phalcon/Db/RawValue.zep',
                  'line' => 47,
                  'char' => 9,
                ),
              ),
              'file' => '/app/phalcon/Db/RawValue.zep',
              'line' => 48,
              'char' => 5,
            ),
          ),
          'docblock' => '**
     * Phalcon\\Db\\RawValue constructor
     *',
          'return-type' => 
          array (
            'type' => 'return-type',
            'void' => 1,
            'file' => '/app/phalcon/Db/RawValue.zep',
            'line' => 40,
            'char' => 5,
          ),
          'file' => '/app/phalcon/Db/RawValue.zep',
          'line' => 39,
          'last-line' => 49,
          'char' => 19,
        ),
      ),
      'file' => '/app/phalcon/Db/RawValue.zep',
      'line' => 27,
      'char' => 5,
    ),
    'file' => '/app/phalcon/Db/RawValue.zep',
    'line' => 27,
    'char' => 5,
  ),
);