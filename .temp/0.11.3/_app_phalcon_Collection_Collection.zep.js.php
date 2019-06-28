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
    'file' => '/app/phalcon/Collection/Collection.zep',
    'line' => 11,
    'char' => 9,
  ),
  1 => 
  array (
    'type' => 'namespace',
    'name' => 'Phalcon\\Collection',
    'file' => '/app/phalcon/Collection/Collection.zep',
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
        'file' => '/app/phalcon/Collection/Collection.zep',
        'line' => 13,
        'char' => 16,
      ),
    ),
    'file' => '/app/phalcon/Collection/Collection.zep',
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
        'name' => 'ArrayIterator',
        'file' => '/app/phalcon/Collection/Collection.zep',
        'line' => 14,
        'char' => 18,
      ),
    ),
    'file' => '/app/phalcon/Collection/Collection.zep',
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
        'name' => 'Countable',
        'file' => '/app/phalcon/Collection/Collection.zep',
        'line' => 15,
        'char' => 14,
      ),
    ),
    'file' => '/app/phalcon/Collection/Collection.zep',
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
        'name' => 'IteratorAggregate',
        'file' => '/app/phalcon/Collection/Collection.zep',
        'line' => 16,
        'char' => 22,
      ),
    ),
    'file' => '/app/phalcon/Collection/Collection.zep',
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
        'name' => 'JsonSerializable',
        'file' => '/app/phalcon/Collection/Collection.zep',
        'line' => 17,
        'char' => 21,
      ),
    ),
    'file' => '/app/phalcon/Collection/Collection.zep',
    'line' => 18,
    'char' => 3,
  ),
  7 => 
  array (
    'type' => 'use',
    'aliases' => 
    array (
      0 => 
      array (
        'name' => 'Serializable',
        'file' => '/app/phalcon/Collection/Collection.zep',
        'line' => 18,
        'char' => 17,
      ),
    ),
    'file' => '/app/phalcon/Collection/Collection.zep',
    'line' => 19,
    'char' => 3,
  ),
  8 => 
  array (
    'type' => 'use',
    'aliases' => 
    array (
      0 => 
      array (
        'name' => 'Traversable',
        'file' => '/app/phalcon/Collection/Collection.zep',
        'line' => 19,
        'char' => 16,
      ),
    ),
    'file' => '/app/phalcon/Collection/Collection.zep',
    'line' => 27,
    'char' => 2,
  ),
  9 => 
  array (
    'type' => 'comment',
    'value' => '**
 * `Phalcon\\Collection\\Collection` is a supercharged object oriented array. It implements [ArrayAccess](https://www.php.net/manual/en/class.arrayaccess.php), [Countable](https://www.php.net/manual/en/class.countable.php), [IteratorAggregate](https://www.php.net/manual/en/class.iteratoraggregate.php), [JsonSerializable](https://www.php.net/manual/en/class.jsonserializable.php), [Serializable](https://www.php.net/manual/en/class.serializable.php)
 *
 * It can be used in any part of the application that needs collection of data
 * Such implementations are for instance accessing globals `$_GET`, `$_POST`
 * etc.
 *',
    'file' => '/app/phalcon/Collection/Collection.zep',
    'line' => 28,
    'char' => 5,
  ),
  10 => 
  array (
    'type' => 'class',
    'name' => 'Collection',
    'abstract' => 0,
    'final' => 0,
    'implements' => 
    array (
      0 => 
      array (
        'type' => 'variable',
        'value' => 'ArrayAccess',
        'file' => '/app/phalcon/Collection/Collection.zep',
        'line' => 29,
        'char' => 16,
      ),
      1 => 
      array (
        'type' => 'variable',
        'value' => 'Countable',
        'file' => '/app/phalcon/Collection/Collection.zep',
        'line' => 30,
        'char' => 14,
      ),
      2 => 
      array (
        'type' => 'variable',
        'value' => 'IteratorAggregate',
        'file' => '/app/phalcon/Collection/Collection.zep',
        'line' => 31,
        'char' => 22,
      ),
      3 => 
      array (
        'type' => 'variable',
        'value' => 'JsonSerializable',
        'file' => '/app/phalcon/Collection/Collection.zep',
        'line' => 32,
        'char' => 21,
      ),
      4 => 
      array (
        'type' => 'variable',
        'value' => 'Serializable',
        'file' => '/app/phalcon/Collection/Collection.zep',
        'line' => 34,
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
          'name' => 'data',
          'default' => 
          array (
            'type' => 'empty-array',
            'file' => '/app/phalcon/Collection/Collection.zep',
            'line' => 38,
            'char' => 24,
          ),
          'docblock' => '**
     * @var array
     *',
          'file' => '/app/phalcon/Collection/Collection.zep',
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
          'name' => 'insensitive',
          'default' => 
          array (
            'type' => 'bool',
            'value' => 'true',
            'file' => '/app/phalcon/Collection/Collection.zep',
            'line' => 43,
            'char' => 33,
          ),
          'docblock' => '**
     * @var bool
     *',
          'file' => '/app/phalcon/Collection/Collection.zep',
          'line' => 47,
          'char' => 6,
        ),
        2 => 
        array (
          'visibility' => 
          array (
            0 => 'protected',
          ),
          'type' => 'property',
          'name' => 'lowerKeys',
          'default' => 
          array (
            'type' => 'empty-array',
            'file' => '/app/phalcon/Collection/Collection.zep',
            'line' => 48,
            'char' => 29,
          ),
          'docblock' => '**
     * @var array
     *',
          'file' => '/app/phalcon/Collection/Collection.zep',
          'line' => 52,
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
              'name' => 'data',
              'const' => 0,
              'data-type' => 'array',
              'mandatory' => 0,
              'default' => 
              array (
                'type' => 'empty-array',
                'file' => '/app/phalcon/Collection/Collection.zep',
                'line' => 53,
                'char' => 48,
              ),
              'reference' => 0,
              'file' => '/app/phalcon/Collection/Collection.zep',
              'line' => 53,
              'char' => 48,
            ),
            1 => 
            array (
              'type' => 'parameter',
              'name' => 'insensitive',
              'const' => 0,
              'data-type' => 'bool',
              'mandatory' => 0,
              'default' => 
              array (
                'type' => 'bool',
                'value' => 'true',
                'file' => '/app/phalcon/Collection/Collection.zep',
                'line' => 53,
                'char' => 73,
              ),
              'reference' => 0,
              'file' => '/app/phalcon/Collection/Collection.zep',
              'line' => 53,
              'char' => 73,
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
                  'property' => 'insensitive',
                  'expr' => 
                  array (
                    'type' => 'variable',
                    'value' => 'insensitive',
                    'file' => '/app/phalcon/Collection/Collection.zep',
                    'line' => 55,
                    'char' => 44,
                  ),
                  'file' => '/app/phalcon/Collection/Collection.zep',
                  'line' => 55,
                  'char' => 44,
                ),
              ),
              'file' => '/app/phalcon/Collection/Collection.zep',
              'line' => 56,
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
                  'file' => '/app/phalcon/Collection/Collection.zep',
                  'line' => 56,
                  'char' => 14,
                ),
                'name' => 'init',
                'call-type' => 1,
                'parameters' => 
                array (
                  0 => 
                  array (
                    'parameter' => 
                    array (
                      'type' => 'variable',
                      'value' => 'data',
                      'file' => '/app/phalcon/Collection/Collection.zep',
                      'line' => 56,
                      'char' => 24,
                    ),
                    'file' => '/app/phalcon/Collection/Collection.zep',
                    'line' => 56,
                    'char' => 24,
                  ),
                ),
                'file' => '/app/phalcon/Collection/Collection.zep',
                'line' => 56,
                'char' => 25,
              ),
              'file' => '/app/phalcon/Collection/Collection.zep',
              'line' => 57,
              'char' => 5,
            ),
          ),
          'docblock' => '**
     * Collection constructor.
     *',
          'file' => '/app/phalcon/Collection/Collection.zep',
          'line' => 53,
          'last-line' => 61,
          'char' => 19,
        ),
        1 => 
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
              'name' => 'element',
              'const' => 0,
              'data-type' => 'string',
              'mandatory' => 0,
              'reference' => 0,
              'file' => '/app/phalcon/Collection/Collection.zep',
              'line' => 62,
              'char' => 41,
            ),
          ),
          'statements' => 
          array (
            0 => 
            array (
              'type' => 'return',
              'expr' => 
              array (
                'type' => 'mcall',
                'variable' => 
                array (
                  'type' => 'variable',
                  'value' => 'this',
                  'file' => '/app/phalcon/Collection/Collection.zep',
                  'line' => 64,
                  'char' => 21,
                ),
                'name' => 'get',
                'call-type' => 1,
                'parameters' => 
                array (
                  0 => 
                  array (
                    'parameter' => 
                    array (
                      'type' => 'variable',
                      'value' => 'element',
                      'file' => '/app/phalcon/Collection/Collection.zep',
                      'line' => 64,
                      'char' => 33,
                    ),
                    'file' => '/app/phalcon/Collection/Collection.zep',
                    'line' => 64,
                    'char' => 33,
                  ),
                ),
                'file' => '/app/phalcon/Collection/Collection.zep',
                'line' => 64,
                'char' => 34,
              ),
              'file' => '/app/phalcon/Collection/Collection.zep',
              'line' => 65,
              'char' => 5,
            ),
          ),
          'docblock' => '**
     * Magic getter to get an element from the collection
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
                'file' => '/app/phalcon/Collection/Collection.zep',
                'line' => 63,
                'char' => 5,
              ),
            ),
            'void' => 0,
            'file' => '/app/phalcon/Collection/Collection.zep',
            'line' => 63,
            'char' => 5,
          ),
          'file' => '/app/phalcon/Collection/Collection.zep',
          'line' => 62,
          'last-line' => 69,
          'char' => 19,
        ),
        2 => 
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
              'name' => 'element',
              'const' => 0,
              'data-type' => 'string',
              'mandatory' => 0,
              'reference' => 0,
              'file' => '/app/phalcon/Collection/Collection.zep',
              'line' => 70,
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
                'type' => 'mcall',
                'variable' => 
                array (
                  'type' => 'variable',
                  'value' => 'this',
                  'file' => '/app/phalcon/Collection/Collection.zep',
                  'line' => 72,
                  'char' => 21,
                ),
                'name' => 'has',
                'call-type' => 1,
                'parameters' => 
                array (
                  0 => 
                  array (
                    'parameter' => 
                    array (
                      'type' => 'variable',
                      'value' => 'element',
                      'file' => '/app/phalcon/Collection/Collection.zep',
                      'line' => 72,
                      'char' => 33,
                    ),
                    'file' => '/app/phalcon/Collection/Collection.zep',
                    'line' => 72,
                    'char' => 33,
                  ),
                ),
                'file' => '/app/phalcon/Collection/Collection.zep',
                'line' => 72,
                'char' => 34,
              ),
              'file' => '/app/phalcon/Collection/Collection.zep',
              'line' => 73,
              'char' => 5,
            ),
          ),
          'docblock' => '**
     * Magic isset to check whether an element exists or not
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
                'file' => '/app/phalcon/Collection/Collection.zep',
                'line' => 71,
                'char' => 5,
              ),
            ),
            'void' => 0,
            'file' => '/app/phalcon/Collection/Collection.zep',
            'line' => 71,
            'char' => 5,
          ),
          'file' => '/app/phalcon/Collection/Collection.zep',
          'line' => 70,
          'last-line' => 77,
          'char' => 19,
        ),
        3 => 
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
              'name' => 'element',
              'const' => 0,
              'data-type' => 'string',
              'mandatory' => 0,
              'reference' => 0,
              'file' => '/app/phalcon/Collection/Collection.zep',
              'line' => 78,
              'char' => 41,
            ),
            1 => 
            array (
              'type' => 'parameter',
              'name' => 'value',
              'const' => 0,
              'data-type' => 'variable',
              'mandatory' => 0,
              'reference' => 0,
              'file' => '/app/phalcon/Collection/Collection.zep',
              'line' => 78,
              'char' => 48,
            ),
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
                  'file' => '/app/phalcon/Collection/Collection.zep',
                  'line' => 80,
                  'char' => 14,
                ),
                'name' => 'set',
                'call-type' => 1,
                'parameters' => 
                array (
                  0 => 
                  array (
                    'parameter' => 
                    array (
                      'type' => 'variable',
                      'value' => 'element',
                      'file' => '/app/phalcon/Collection/Collection.zep',
                      'line' => 80,
                      'char' => 26,
                    ),
                    'file' => '/app/phalcon/Collection/Collection.zep',
                    'line' => 80,
                    'char' => 26,
                  ),
                  1 => 
                  array (
                    'parameter' => 
                    array (
                      'type' => 'variable',
                      'value' => 'value',
                      'file' => '/app/phalcon/Collection/Collection.zep',
                      'line' => 80,
                      'char' => 33,
                    ),
                    'file' => '/app/phalcon/Collection/Collection.zep',
                    'line' => 80,
                    'char' => 33,
                  ),
                ),
                'file' => '/app/phalcon/Collection/Collection.zep',
                'line' => 80,
                'char' => 34,
              ),
              'file' => '/app/phalcon/Collection/Collection.zep',
              'line' => 81,
              'char' => 5,
            ),
          ),
          'docblock' => '**
     * Magic setter to assign values to an element
     *',
          'return-type' => 
          array (
            'type' => 'return-type',
            'void' => 1,
            'file' => '/app/phalcon/Collection/Collection.zep',
            'line' => 79,
            'char' => 5,
          ),
          'file' => '/app/phalcon/Collection/Collection.zep',
          'line' => 78,
          'last-line' => 85,
          'char' => 19,
        ),
        4 => 
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
              'name' => 'element',
              'const' => 0,
              'data-type' => 'string',
              'mandatory' => 0,
              'reference' => 0,
              'file' => '/app/phalcon/Collection/Collection.zep',
              'line' => 86,
              'char' => 43,
            ),
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
                  'file' => '/app/phalcon/Collection/Collection.zep',
                  'line' => 88,
                  'char' => 14,
                ),
                'name' => 'remove',
                'call-type' => 1,
                'parameters' => 
                array (
                  0 => 
                  array (
                    'parameter' => 
                    array (
                      'type' => 'variable',
                      'value' => 'element',
                      'file' => '/app/phalcon/Collection/Collection.zep',
                      'line' => 88,
                      'char' => 29,
                    ),
                    'file' => '/app/phalcon/Collection/Collection.zep',
                    'line' => 88,
                    'char' => 29,
                  ),
                ),
                'file' => '/app/phalcon/Collection/Collection.zep',
                'line' => 88,
                'char' => 30,
              ),
              'file' => '/app/phalcon/Collection/Collection.zep',
              'line' => 89,
              'char' => 5,
            ),
          ),
          'docblock' => '**
     * Magic unset to remove an element from the collection
     *',
          'return-type' => 
          array (
            'type' => 'return-type',
            'void' => 1,
            'file' => '/app/phalcon/Collection/Collection.zep',
            'line' => 87,
            'char' => 5,
          ),
          'file' => '/app/phalcon/Collection/Collection.zep',
          'line' => 86,
          'last-line' => 93,
          'char' => 19,
        ),
        5 => 
        array (
          'visibility' => 
          array (
            0 => 'public',
          ),
          'type' => 'method',
          'name' => 'clear',
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
                  'property' => 'data',
                  'expr' => 
                  array (
                    'type' => 'empty-array',
                    'file' => '/app/phalcon/Collection/Collection.zep',
                    'line' => 96,
                    'char' => 33,
                  ),
                  'file' => '/app/phalcon/Collection/Collection.zep',
                  'line' => 96,
                  'char' => 33,
                ),
                1 => 
                array (
                  'assign-type' => 'object-property',
                  'operator' => 'assign',
                  'variable' => 'this',
                  'property' => 'lowerKeys',
                  'expr' => 
                  array (
                    'type' => 'empty-array',
                    'file' => '/app/phalcon/Collection/Collection.zep',
                    'line' => 97,
                    'char' => 33,
                  ),
                  'file' => '/app/phalcon/Collection/Collection.zep',
                  'line' => 97,
                  'char' => 33,
                ),
              ),
              'file' => '/app/phalcon/Collection/Collection.zep',
              'line' => 98,
              'char' => 5,
            ),
          ),
          'docblock' => '**
     * Clears the internal collection
     *',
          'return-type' => 
          array (
            'type' => 'return-type',
            'void' => 1,
            'file' => '/app/phalcon/Collection/Collection.zep',
            'line' => 95,
            'char' => 5,
          ),
          'file' => '/app/phalcon/Collection/Collection.zep',
          'line' => 94,
          'last-line' => 103,
          'char' => 19,
        ),
        6 => 
        array (
          'visibility' => 
          array (
            0 => 'public',
          ),
          'type' => 'method',
          'name' => 'count',
          'statements' => 
          array (
            0 => 
            array (
              'type' => 'return',
              'expr' => 
              array (
                'type' => 'fcall',
                'name' => 'count',
                'call-type' => 1,
                'parameters' => 
                array (
                  0 => 
                  array (
                    'parameter' => 
                    array (
                      'type' => 'property-access',
                      'left' => 
                      array (
                        'type' => 'variable',
                        'value' => 'this',
                        'file' => '/app/phalcon/Collection/Collection.zep',
                        'line' => 106,
                        'char' => 27,
                      ),
                      'right' => 
                      array (
                        'type' => 'variable',
                        'value' => 'data',
                        'file' => '/app/phalcon/Collection/Collection.zep',
                        'line' => 106,
                        'char' => 32,
                      ),
                      'file' => '/app/phalcon/Collection/Collection.zep',
                      'line' => 106,
                      'char' => 32,
                    ),
                    'file' => '/app/phalcon/Collection/Collection.zep',
                    'line' => 106,
                    'char' => 32,
                  ),
                ),
                'file' => '/app/phalcon/Collection/Collection.zep',
                'line' => 106,
                'char' => 33,
              ),
              'file' => '/app/phalcon/Collection/Collection.zep',
              'line' => 107,
              'char' => 5,
            ),
          ),
          'docblock' => '**
     * Count elements of an object.
     * See [count](https://php.net/manual/en/countable.count.php)
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
                'file' => '/app/phalcon/Collection/Collection.zep',
                'line' => 105,
                'char' => 5,
              ),
            ),
            'void' => 0,
            'file' => '/app/phalcon/Collection/Collection.zep',
            'line' => 105,
            'char' => 5,
          ),
          'file' => '/app/phalcon/Collection/Collection.zep',
          'line' => 104,
          'last-line' => 111,
          'char' => 19,
        ),
        7 => 
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
              'name' => 'element',
              'const' => 0,
              'data-type' => 'string',
              'mandatory' => 0,
              'reference' => 0,
              'file' => '/app/phalcon/Collection/Collection.zep',
              'line' => 112,
              'char' => 39,
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
                'file' => '/app/phalcon/Collection/Collection.zep',
                'line' => 112,
                'char' => 60,
              ),
              'reference' => 0,
              'file' => '/app/phalcon/Collection/Collection.zep',
              'line' => 112,
              'char' => 60,
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
                  'variable' => 'key',
                  'file' => '/app/phalcon/Collection/Collection.zep',
                  'line' => 114,
                  'char' => 16,
                ),
              ),
              'file' => '/app/phalcon/Collection/Collection.zep',
              'line' => 116,
              'char' => 10,
            ),
            1 => 
            array (
              'type' => 'if',
              'expr' => 
              array (
                'type' => 'likely',
                'left' => 
                array (
                  'type' => 'property-access',
                  'left' => 
                  array (
                    'type' => 'variable',
                    'value' => 'this',
                    'file' => '/app/phalcon/Collection/Collection.zep',
                    'line' => 116,
                    'char' => 24,
                  ),
                  'right' => 
                  array (
                    'type' => 'variable',
                    'value' => 'insensitive',
                    'file' => '/app/phalcon/Collection/Collection.zep',
                    'line' => 116,
                    'char' => 37,
                  ),
                  'file' => '/app/phalcon/Collection/Collection.zep',
                  'line' => 116,
                  'char' => 37,
                ),
                'file' => '/app/phalcon/Collection/Collection.zep',
                'line' => 116,
                'char' => 37,
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
                      'variable' => 'element',
                      'expr' => 
                      array (
                        'type' => 'mcall',
                        'variable' => 
                        array (
                          'type' => 'variable',
                          'value' => 'element',
                          'file' => '/app/phalcon/Collection/Collection.zep',
                          'line' => 117,
                          'char' => 35,
                        ),
                        'name' => 'lower',
                        'call-type' => 1,
                        'file' => '/app/phalcon/Collection/Collection.zep',
                        'line' => 117,
                        'char' => 43,
                      ),
                      'file' => '/app/phalcon/Collection/Collection.zep',
                      'line' => 117,
                      'char' => 43,
                    ),
                  ),
                  'file' => '/app/phalcon/Collection/Collection.zep',
                  'line' => 118,
                  'char' => 9,
                ),
              ),
              'file' => '/app/phalcon/Collection/Collection.zep',
              'line' => 120,
              'char' => 10,
            ),
            2 => 
            array (
              'type' => 'if',
              'expr' => 
              array (
                'type' => 'likely',
                'left' => 
                array (
                  'type' => 'isset',
                  'left' => 
                  array (
                    'type' => 'array-access',
                    'left' => 
                    array (
                      'type' => 'property-access',
                      'left' => 
                      array (
                        'type' => 'variable',
                        'value' => 'this',
                        'file' => '/app/phalcon/Collection/Collection.zep',
                        'line' => 120,
                        'char' => 30,
                      ),
                      'right' => 
                      array (
                        'type' => 'variable',
                        'value' => 'lowerKeys',
                        'file' => '/app/phalcon/Collection/Collection.zep',
                        'line' => 120,
                        'char' => 40,
                      ),
                      'file' => '/app/phalcon/Collection/Collection.zep',
                      'line' => 120,
                      'char' => 40,
                    ),
                    'right' => 
                    array (
                      'type' => 'variable',
                      'value' => 'element',
                      'file' => '/app/phalcon/Collection/Collection.zep',
                      'line' => 120,
                      'char' => 48,
                    ),
                    'file' => '/app/phalcon/Collection/Collection.zep',
                    'line' => 120,
                    'char' => 50,
                  ),
                  'file' => '/app/phalcon/Collection/Collection.zep',
                  'line' => 120,
                  'char' => 50,
                ),
                'file' => '/app/phalcon/Collection/Collection.zep',
                'line' => 120,
                'char' => 50,
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
                      'variable' => 'key',
                      'expr' => 
                      array (
                        'type' => 'array-access',
                        'left' => 
                        array (
                          'type' => 'property-access',
                          'left' => 
                          array (
                            'type' => 'variable',
                            'value' => 'this',
                            'file' => '/app/phalcon/Collection/Collection.zep',
                            'line' => 121,
                            'char' => 28,
                          ),
                          'right' => 
                          array (
                            'type' => 'variable',
                            'value' => 'lowerKeys',
                            'file' => '/app/phalcon/Collection/Collection.zep',
                            'line' => 121,
                            'char' => 38,
                          ),
                          'file' => '/app/phalcon/Collection/Collection.zep',
                          'line' => 121,
                          'char' => 38,
                        ),
                        'right' => 
                        array (
                          'type' => 'variable',
                          'value' => 'element',
                          'file' => '/app/phalcon/Collection/Collection.zep',
                          'line' => 121,
                          'char' => 46,
                        ),
                        'file' => '/app/phalcon/Collection/Collection.zep',
                        'line' => 121,
                        'char' => 47,
                      ),
                      'file' => '/app/phalcon/Collection/Collection.zep',
                      'line' => 121,
                      'char' => 47,
                    ),
                  ),
                  'file' => '/app/phalcon/Collection/Collection.zep',
                  'line' => 123,
                  'char' => 18,
                ),
                1 => 
                array (
                  'type' => 'return',
                  'expr' => 
                  array (
                    'type' => 'array-access',
                    'left' => 
                    array (
                      'type' => 'property-access',
                      'left' => 
                      array (
                        'type' => 'variable',
                        'value' => 'this',
                        'file' => '/app/phalcon/Collection/Collection.zep',
                        'line' => 123,
                        'char' => 25,
                      ),
                      'right' => 
                      array (
                        'type' => 'variable',
                        'value' => 'data',
                        'file' => '/app/phalcon/Collection/Collection.zep',
                        'line' => 123,
                        'char' => 30,
                      ),
                      'file' => '/app/phalcon/Collection/Collection.zep',
                      'line' => 123,
                      'char' => 30,
                    ),
                    'right' => 
                    array (
                      'type' => 'variable',
                      'value' => 'key',
                      'file' => '/app/phalcon/Collection/Collection.zep',
                      'line' => 123,
                      'char' => 34,
                    ),
                    'file' => '/app/phalcon/Collection/Collection.zep',
                    'line' => 123,
                    'char' => 35,
                  ),
                  'file' => '/app/phalcon/Collection/Collection.zep',
                  'line' => 124,
                  'char' => 9,
                ),
              ),
              'file' => '/app/phalcon/Collection/Collection.zep',
              'line' => 126,
              'char' => 14,
            ),
            3 => 
            array (
              'type' => 'return',
              'expr' => 
              array (
                'type' => 'variable',
                'value' => 'defaultValue',
                'file' => '/app/phalcon/Collection/Collection.zep',
                'line' => 126,
                'char' => 28,
              ),
              'file' => '/app/phalcon/Collection/Collection.zep',
              'line' => 127,
              'char' => 5,
            ),
          ),
          'docblock' => '**
     * Get the element from the collection
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
                'file' => '/app/phalcon/Collection/Collection.zep',
                'line' => 113,
                'char' => 5,
              ),
            ),
            'void' => 0,
            'file' => '/app/phalcon/Collection/Collection.zep',
            'line' => 113,
            'char' => 5,
          ),
          'file' => '/app/phalcon/Collection/Collection.zep',
          'line' => 112,
          'last-line' => 131,
          'char' => 19,
        ),
        8 => 
        array (
          'visibility' => 
          array (
            0 => 'public',
          ),
          'type' => 'method',
          'name' => 'getIterator',
          'statements' => 
          array (
            0 => 
            array (
              'type' => 'return',
              'expr' => 
              array (
                'type' => 'new',
                'class' => 'ArrayIterator',
                'dynamic' => 0,
                'parameters' => 
                array (
                  0 => 
                  array (
                    'parameter' => 
                    array (
                      'type' => 'property-access',
                      'left' => 
                      array (
                        'type' => 'variable',
                        'value' => 'this',
                        'file' => '/app/phalcon/Collection/Collection.zep',
                        'line' => 134,
                        'char' => 39,
                      ),
                      'right' => 
                      array (
                        'type' => 'variable',
                        'value' => 'data',
                        'file' => '/app/phalcon/Collection/Collection.zep',
                        'line' => 134,
                        'char' => 44,
                      ),
                      'file' => '/app/phalcon/Collection/Collection.zep',
                      'line' => 134,
                      'char' => 44,
                    ),
                    'file' => '/app/phalcon/Collection/Collection.zep',
                    'line' => 134,
                    'char' => 44,
                  ),
                ),
                'file' => '/app/phalcon/Collection/Collection.zep',
                'line' => 134,
                'char' => 45,
              ),
              'file' => '/app/phalcon/Collection/Collection.zep',
              'line' => 135,
              'char' => 5,
            ),
          ),
          'docblock' => '**
     * Returns the iterator of the class
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
                  'value' => 'Traversable',
                  'file' => '/app/phalcon/Collection/Collection.zep',
                  'line' => 133,
                  'char' => 5,
                ),
                'collection' => 0,
                'file' => '/app/phalcon/Collection/Collection.zep',
                'line' => 133,
                'char' => 5,
              ),
            ),
            'void' => 0,
            'file' => '/app/phalcon/Collection/Collection.zep',
            'line' => 133,
            'char' => 5,
          ),
          'file' => '/app/phalcon/Collection/Collection.zep',
          'line' => 132,
          'last-line' => 139,
          'char' => 19,
        ),
        9 => 
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
              'name' => 'element',
              'const' => 0,
              'data-type' => 'string',
              'mandatory' => 0,
              'reference' => 0,
              'file' => '/app/phalcon/Collection/Collection.zep',
              'line' => 140,
              'char' => 39,
            ),
          ),
          'statements' => 
          array (
            0 => 
            array (
              'type' => 'if',
              'expr' => 
              array (
                'type' => 'likely',
                'left' => 
                array (
                  'type' => 'property-access',
                  'left' => 
                  array (
                    'type' => 'variable',
                    'value' => 'this',
                    'file' => '/app/phalcon/Collection/Collection.zep',
                    'line' => 142,
                    'char' => 24,
                  ),
                  'right' => 
                  array (
                    'type' => 'variable',
                    'value' => 'insensitive',
                    'file' => '/app/phalcon/Collection/Collection.zep',
                    'line' => 142,
                    'char' => 37,
                  ),
                  'file' => '/app/phalcon/Collection/Collection.zep',
                  'line' => 142,
                  'char' => 37,
                ),
                'file' => '/app/phalcon/Collection/Collection.zep',
                'line' => 142,
                'char' => 37,
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
                      'variable' => 'element',
                      'expr' => 
                      array (
                        'type' => 'mcall',
                        'variable' => 
                        array (
                          'type' => 'variable',
                          'value' => 'element',
                          'file' => '/app/phalcon/Collection/Collection.zep',
                          'line' => 143,
                          'char' => 35,
                        ),
                        'name' => 'lower',
                        'call-type' => 1,
                        'file' => '/app/phalcon/Collection/Collection.zep',
                        'line' => 143,
                        'char' => 43,
                      ),
                      'file' => '/app/phalcon/Collection/Collection.zep',
                      'line' => 143,
                      'char' => 43,
                    ),
                  ),
                  'file' => '/app/phalcon/Collection/Collection.zep',
                  'line' => 144,
                  'char' => 9,
                ),
              ),
              'file' => '/app/phalcon/Collection/Collection.zep',
              'line' => 146,
              'char' => 14,
            ),
            1 => 
            array (
              'type' => 'return',
              'expr' => 
              array (
                'type' => 'isset',
                'left' => 
                array (
                  'type' => 'array-access',
                  'left' => 
                  array (
                    'type' => 'property-access',
                    'left' => 
                    array (
                      'type' => 'variable',
                      'value' => 'this',
                      'file' => '/app/phalcon/Collection/Collection.zep',
                      'line' => 146,
                      'char' => 27,
                    ),
                    'right' => 
                    array (
                      'type' => 'variable',
                      'value' => 'lowerKeys',
                      'file' => '/app/phalcon/Collection/Collection.zep',
                      'line' => 146,
                      'char' => 37,
                    ),
                    'file' => '/app/phalcon/Collection/Collection.zep',
                    'line' => 146,
                    'char' => 37,
                  ),
                  'right' => 
                  array (
                    'type' => 'variable',
                    'value' => 'element',
                    'file' => '/app/phalcon/Collection/Collection.zep',
                    'line' => 146,
                    'char' => 45,
                  ),
                  'file' => '/app/phalcon/Collection/Collection.zep',
                  'line' => 146,
                  'char' => 46,
                ),
                'file' => '/app/phalcon/Collection/Collection.zep',
                'line' => 146,
                'char' => 46,
              ),
              'file' => '/app/phalcon/Collection/Collection.zep',
              'line' => 147,
              'char' => 5,
            ),
          ),
          'docblock' => '**
     * Get the element from the collection
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
                'file' => '/app/phalcon/Collection/Collection.zep',
                'line' => 141,
                'char' => 5,
              ),
            ),
            'void' => 0,
            'file' => '/app/phalcon/Collection/Collection.zep',
            'line' => 141,
            'char' => 5,
          ),
          'file' => '/app/phalcon/Collection/Collection.zep',
          'line' => 140,
          'last-line' => 151,
          'char' => 19,
        ),
        10 => 
        array (
          'visibility' => 
          array (
            0 => 'public',
          ),
          'type' => 'method',
          'name' => 'init',
          'parameters' => 
          array (
            0 => 
            array (
              'type' => 'parameter',
              'name' => 'data',
              'const' => 0,
              'data-type' => 'array',
              'mandatory' => 0,
              'default' => 
              array (
                'type' => 'empty-array',
                'file' => '/app/phalcon/Collection/Collection.zep',
                'line' => 152,
                'char' => 41,
              ),
              'reference' => 0,
              'file' => '/app/phalcon/Collection/Collection.zep',
              'line' => 152,
              'char' => 41,
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
                  'variable' => 'key',
                  'file' => '/app/phalcon/Collection/Collection.zep',
                  'line' => 154,
                  'char' => 16,
                ),
                1 => 
                array (
                  'variable' => 'value',
                  'file' => '/app/phalcon/Collection/Collection.zep',
                  'line' => 154,
                  'char' => 23,
                ),
              ),
              'file' => '/app/phalcon/Collection/Collection.zep',
              'line' => 156,
              'char' => 11,
            ),
            1 => 
            array (
              'type' => 'for',
              'expr' => 
              array (
                'type' => 'variable',
                'value' => 'data',
                'file' => '/app/phalcon/Collection/Collection.zep',
                'line' => 156,
                'char' => 32,
              ),
              'key' => 'key',
              'value' => 'value',
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
                      'file' => '/app/phalcon/Collection/Collection.zep',
                      'line' => 157,
                      'char' => 18,
                    ),
                    'name' => 'setData',
                    'call-type' => 1,
                    'parameters' => 
                    array (
                      0 => 
                      array (
                        'parameter' => 
                        array (
                          'type' => 'variable',
                          'value' => 'key',
                          'file' => '/app/phalcon/Collection/Collection.zep',
                          'line' => 157,
                          'char' => 30,
                        ),
                        'file' => '/app/phalcon/Collection/Collection.zep',
                        'line' => 157,
                        'char' => 30,
                      ),
                      1 => 
                      array (
                        'parameter' => 
                        array (
                          'type' => 'variable',
                          'value' => 'value',
                          'file' => '/app/phalcon/Collection/Collection.zep',
                          'line' => 157,
                          'char' => 37,
                        ),
                        'file' => '/app/phalcon/Collection/Collection.zep',
                        'line' => 157,
                        'char' => 37,
                      ),
                    ),
                    'file' => '/app/phalcon/Collection/Collection.zep',
                    'line' => 157,
                    'char' => 38,
                  ),
                  'file' => '/app/phalcon/Collection/Collection.zep',
                  'line' => 158,
                  'char' => 9,
                ),
              ),
              'file' => '/app/phalcon/Collection/Collection.zep',
              'line' => 159,
              'char' => 5,
            ),
          ),
          'docblock' => '**
     * Initialize internal array
     *',
          'return-type' => 
          array (
            'type' => 'return-type',
            'void' => 1,
            'file' => '/app/phalcon/Collection/Collection.zep',
            'line' => 153,
            'char' => 5,
          ),
          'file' => '/app/phalcon/Collection/Collection.zep',
          'line' => 152,
          'last-line' => 164,
          'char' => 19,
        ),
        11 => 
        array (
          'visibility' => 
          array (
            0 => 'public',
          ),
          'type' => 'method',
          'name' => 'jsonSerialize',
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
                  'file' => '/app/phalcon/Collection/Collection.zep',
                  'line' => 167,
                  'char' => 21,
                ),
                'right' => 
                array (
                  'type' => 'variable',
                  'value' => 'data',
                  'file' => '/app/phalcon/Collection/Collection.zep',
                  'line' => 167,
                  'char' => 26,
                ),
                'file' => '/app/phalcon/Collection/Collection.zep',
                'line' => 167,
                'char' => 26,
              ),
              'file' => '/app/phalcon/Collection/Collection.zep',
              'line' => 168,
              'char' => 5,
            ),
          ),
          'docblock' => '**
     * Specify data which should be serialized to JSON
     * See [jsonSerialize](https://php.net/manual/en/jsonserializable.jsonserialize.php)
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
                'file' => '/app/phalcon/Collection/Collection.zep',
                'line' => 166,
                'char' => 5,
              ),
            ),
            'void' => 0,
            'file' => '/app/phalcon/Collection/Collection.zep',
            'line' => 166,
            'char' => 5,
          ),
          'file' => '/app/phalcon/Collection/Collection.zep',
          'line' => 165,
          'last-line' => 173,
          'char' => 19,
        ),
        12 => 
        array (
          'visibility' => 
          array (
            0 => 'public',
          ),
          'type' => 'method',
          'name' => 'offsetExists',
          'parameters' => 
          array (
            0 => 
            array (
              'type' => 'parameter',
              'name' => 'element',
              'const' => 0,
              'data-type' => 'variable',
              'mandatory' => 0,
              'reference' => 0,
              'file' => '/app/phalcon/Collection/Collection.zep',
              'line' => 174,
              'char' => 45,
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
                  'variable' => 'element',
                  'expr' => 
                  array (
                    'type' => 'cast',
                    'left' => 'string',
                    'right' => 
                    array (
                      'type' => 'variable',
                      'value' => 'element',
                      'file' => '/app/phalcon/Collection/Collection.zep',
                      'line' => 176,
                      'char' => 39,
                    ),
                    'file' => '/app/phalcon/Collection/Collection.zep',
                    'line' => 176,
                    'char' => 39,
                  ),
                  'file' => '/app/phalcon/Collection/Collection.zep',
                  'line' => 176,
                  'char' => 39,
                ),
              ),
              'file' => '/app/phalcon/Collection/Collection.zep',
              'line' => 178,
              'char' => 14,
            ),
            1 => 
            array (
              'type' => 'return',
              'expr' => 
              array (
                'type' => 'mcall',
                'variable' => 
                array (
                  'type' => 'variable',
                  'value' => 'this',
                  'file' => '/app/phalcon/Collection/Collection.zep',
                  'line' => 178,
                  'char' => 21,
                ),
                'name' => 'has',
                'call-type' => 1,
                'parameters' => 
                array (
                  0 => 
                  array (
                    'parameter' => 
                    array (
                      'type' => 'variable',
                      'value' => 'element',
                      'file' => '/app/phalcon/Collection/Collection.zep',
                      'line' => 178,
                      'char' => 33,
                    ),
                    'file' => '/app/phalcon/Collection/Collection.zep',
                    'line' => 178,
                    'char' => 33,
                  ),
                ),
                'file' => '/app/phalcon/Collection/Collection.zep',
                'line' => 178,
                'char' => 34,
              ),
              'file' => '/app/phalcon/Collection/Collection.zep',
              'line' => 179,
              'char' => 5,
            ),
          ),
          'docblock' => '**
     * Whether a offset exists
     * See [offsetExists](https://php.net/manual/en/arrayaccess.offsetexists.php)
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
                'file' => '/app/phalcon/Collection/Collection.zep',
                'line' => 175,
                'char' => 5,
              ),
            ),
            'void' => 0,
            'file' => '/app/phalcon/Collection/Collection.zep',
            'line' => 175,
            'char' => 5,
          ),
          'file' => '/app/phalcon/Collection/Collection.zep',
          'line' => 174,
          'last-line' => 184,
          'char' => 19,
        ),
        13 => 
        array (
          'visibility' => 
          array (
            0 => 'public',
          ),
          'type' => 'method',
          'name' => 'offsetGet',
          'parameters' => 
          array (
            0 => 
            array (
              'type' => 'parameter',
              'name' => 'element',
              'const' => 0,
              'data-type' => 'variable',
              'mandatory' => 0,
              'reference' => 0,
              'file' => '/app/phalcon/Collection/Collection.zep',
              'line' => 185,
              'char' => 42,
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
                  'variable' => 'element',
                  'expr' => 
                  array (
                    'type' => 'cast',
                    'left' => 'string',
                    'right' => 
                    array (
                      'type' => 'variable',
                      'value' => 'element',
                      'file' => '/app/phalcon/Collection/Collection.zep',
                      'line' => 187,
                      'char' => 39,
                    ),
                    'file' => '/app/phalcon/Collection/Collection.zep',
                    'line' => 187,
                    'char' => 39,
                  ),
                  'file' => '/app/phalcon/Collection/Collection.zep',
                  'line' => 187,
                  'char' => 39,
                ),
              ),
              'file' => '/app/phalcon/Collection/Collection.zep',
              'line' => 189,
              'char' => 14,
            ),
            1 => 
            array (
              'type' => 'return',
              'expr' => 
              array (
                'type' => 'mcall',
                'variable' => 
                array (
                  'type' => 'variable',
                  'value' => 'this',
                  'file' => '/app/phalcon/Collection/Collection.zep',
                  'line' => 189,
                  'char' => 21,
                ),
                'name' => 'get',
                'call-type' => 1,
                'parameters' => 
                array (
                  0 => 
                  array (
                    'parameter' => 
                    array (
                      'type' => 'variable',
                      'value' => 'element',
                      'file' => '/app/phalcon/Collection/Collection.zep',
                      'line' => 189,
                      'char' => 33,
                    ),
                    'file' => '/app/phalcon/Collection/Collection.zep',
                    'line' => 189,
                    'char' => 33,
                  ),
                ),
                'file' => '/app/phalcon/Collection/Collection.zep',
                'line' => 189,
                'char' => 34,
              ),
              'file' => '/app/phalcon/Collection/Collection.zep',
              'line' => 190,
              'char' => 5,
            ),
          ),
          'docblock' => '**
     * Offset to retrieve
     * See [offsetGet](https://php.net/manual/en/arrayaccess.offsetget.php)
     *',
          'file' => '/app/phalcon/Collection/Collection.zep',
          'line' => 185,
          'last-line' => 196,
          'char' => 19,
        ),
        14 => 
        array (
          'visibility' => 
          array (
            0 => 'public',
          ),
          'type' => 'method',
          'name' => 'offsetSet',
          'parameters' => 
          array (
            0 => 
            array (
              'type' => 'parameter',
              'name' => 'element',
              'const' => 0,
              'data-type' => 'variable',
              'mandatory' => 0,
              'reference' => 0,
              'file' => '/app/phalcon/Collection/Collection.zep',
              'line' => 197,
              'char' => 42,
            ),
            1 => 
            array (
              'type' => 'parameter',
              'name' => 'value',
              'const' => 0,
              'data-type' => 'variable',
              'mandatory' => 0,
              'reference' => 0,
              'file' => '/app/phalcon/Collection/Collection.zep',
              'line' => 197,
              'char' => 53,
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
                  'variable' => 'element',
                  'expr' => 
                  array (
                    'type' => 'cast',
                    'left' => 'string',
                    'right' => 
                    array (
                      'type' => 'variable',
                      'value' => 'element',
                      'file' => '/app/phalcon/Collection/Collection.zep',
                      'line' => 199,
                      'char' => 39,
                    ),
                    'file' => '/app/phalcon/Collection/Collection.zep',
                    'line' => 199,
                    'char' => 39,
                  ),
                  'file' => '/app/phalcon/Collection/Collection.zep',
                  'line' => 199,
                  'char' => 39,
                ),
              ),
              'file' => '/app/phalcon/Collection/Collection.zep',
              'line' => 201,
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
                  'file' => '/app/phalcon/Collection/Collection.zep',
                  'line' => 201,
                  'char' => 14,
                ),
                'name' => 'set',
                'call-type' => 1,
                'parameters' => 
                array (
                  0 => 
                  array (
                    'parameter' => 
                    array (
                      'type' => 'variable',
                      'value' => 'element',
                      'file' => '/app/phalcon/Collection/Collection.zep',
                      'line' => 201,
                      'char' => 26,
                    ),
                    'file' => '/app/phalcon/Collection/Collection.zep',
                    'line' => 201,
                    'char' => 26,
                  ),
                  1 => 
                  array (
                    'parameter' => 
                    array (
                      'type' => 'variable',
                      'value' => 'value',
                      'file' => '/app/phalcon/Collection/Collection.zep',
                      'line' => 201,
                      'char' => 33,
                    ),
                    'file' => '/app/phalcon/Collection/Collection.zep',
                    'line' => 201,
                    'char' => 33,
                  ),
                ),
                'file' => '/app/phalcon/Collection/Collection.zep',
                'line' => 201,
                'char' => 34,
              ),
              'file' => '/app/phalcon/Collection/Collection.zep',
              'line' => 202,
              'char' => 5,
            ),
          ),
          'docblock' => '**
     * Offset to set
     * See [offsetSet](
     * @link )https://php.net/manual/en/arrayaccess.offsetset.php)
     *',
          'return-type' => 
          array (
            'type' => 'return-type',
            'void' => 1,
            'file' => '/app/phalcon/Collection/Collection.zep',
            'line' => 198,
            'char' => 5,
          ),
          'file' => '/app/phalcon/Collection/Collection.zep',
          'line' => 197,
          'last-line' => 207,
          'char' => 19,
        ),
        15 => 
        array (
          'visibility' => 
          array (
            0 => 'public',
          ),
          'type' => 'method',
          'name' => 'offsetUnset',
          'parameters' => 
          array (
            0 => 
            array (
              'type' => 'parameter',
              'name' => 'element',
              'const' => 0,
              'data-type' => 'variable',
              'mandatory' => 0,
              'reference' => 0,
              'file' => '/app/phalcon/Collection/Collection.zep',
              'line' => 208,
              'char' => 44,
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
                  'variable' => 'element',
                  'expr' => 
                  array (
                    'type' => 'cast',
                    'left' => 'string',
                    'right' => 
                    array (
                      'type' => 'variable',
                      'value' => 'element',
                      'file' => '/app/phalcon/Collection/Collection.zep',
                      'line' => 210,
                      'char' => 39,
                    ),
                    'file' => '/app/phalcon/Collection/Collection.zep',
                    'line' => 210,
                    'char' => 39,
                  ),
                  'file' => '/app/phalcon/Collection/Collection.zep',
                  'line' => 210,
                  'char' => 39,
                ),
              ),
              'file' => '/app/phalcon/Collection/Collection.zep',
              'line' => 212,
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
                  'file' => '/app/phalcon/Collection/Collection.zep',
                  'line' => 212,
                  'char' => 14,
                ),
                'name' => 'remove',
                'call-type' => 1,
                'parameters' => 
                array (
                  0 => 
                  array (
                    'parameter' => 
                    array (
                      'type' => 'variable',
                      'value' => 'element',
                      'file' => '/app/phalcon/Collection/Collection.zep',
                      'line' => 212,
                      'char' => 29,
                    ),
                    'file' => '/app/phalcon/Collection/Collection.zep',
                    'line' => 212,
                    'char' => 29,
                  ),
                ),
                'file' => '/app/phalcon/Collection/Collection.zep',
                'line' => 212,
                'char' => 30,
              ),
              'file' => '/app/phalcon/Collection/Collection.zep',
              'line' => 213,
              'char' => 5,
            ),
          ),
          'docblock' => '**
     * Offset to unset
     * See [offsetUnset](https://php.net/manual/en/arrayaccess.offsetunset.php)
     *',
          'return-type' => 
          array (
            'type' => 'return-type',
            'void' => 1,
            'file' => '/app/phalcon/Collection/Collection.zep',
            'line' => 209,
            'char' => 5,
          ),
          'file' => '/app/phalcon/Collection/Collection.zep',
          'line' => 208,
          'last-line' => 217,
          'char' => 19,
        ),
        16 => 
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
              'name' => 'element',
              'const' => 0,
              'data-type' => 'string',
              'mandatory' => 0,
              'reference' => 0,
              'file' => '/app/phalcon/Collection/Collection.zep',
              'line' => 218,
              'char' => 42,
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
                  'variable' => 'key',
                  'file' => '/app/phalcon/Collection/Collection.zep',
                  'line' => 220,
                  'char' => 16,
                ),
              ),
              'file' => '/app/phalcon/Collection/Collection.zep',
              'line' => 221,
              'char' => 13,
            ),
            1 => 
            array (
              'type' => 'declare',
              'data-type' => 'array',
              'variables' => 
              array (
                0 => 
                array (
                  'variable' => 'lowerKeys',
                  'file' => '/app/phalcon/Collection/Collection.zep',
                  'line' => 221,
                  'char' => 24,
                ),
                1 => 
                array (
                  'variable' => 'data',
                  'file' => '/app/phalcon/Collection/Collection.zep',
                  'line' => 221,
                  'char' => 30,
                ),
              ),
              'file' => '/app/phalcon/Collection/Collection.zep',
              'line' => 223,
              'char' => 10,
            ),
            2 => 
            array (
              'type' => 'if',
              'expr' => 
              array (
                'type' => 'likely',
                'left' => 
                array (
                  'type' => 'mcall',
                  'variable' => 
                  array (
                    'type' => 'variable',
                    'value' => 'this',
                    'file' => '/app/phalcon/Collection/Collection.zep',
                    'line' => 223,
                    'char' => 24,
                  ),
                  'name' => 'has',
                  'call-type' => 1,
                  'parameters' => 
                  array (
                    0 => 
                    array (
                      'parameter' => 
                      array (
                        'type' => 'variable',
                        'value' => 'element',
                        'file' => '/app/phalcon/Collection/Collection.zep',
                        'line' => 223,
                        'char' => 36,
                      ),
                      'file' => '/app/phalcon/Collection/Collection.zep',
                      'line' => 223,
                      'char' => 36,
                    ),
                  ),
                  'file' => '/app/phalcon/Collection/Collection.zep',
                  'line' => 223,
                  'char' => 38,
                ),
                'file' => '/app/phalcon/Collection/Collection.zep',
                'line' => 223,
                'char' => 38,
              ),
              'statements' => 
              array (
                0 => 
                array (
                  'type' => 'if',
                  'expr' => 
                  array (
                    'type' => 'likely',
                    'left' => 
                    array (
                      'type' => 'property-access',
                      'left' => 
                      array (
                        'type' => 'variable',
                        'value' => 'this',
                        'file' => '/app/phalcon/Collection/Collection.zep',
                        'line' => 224,
                        'char' => 28,
                      ),
                      'right' => 
                      array (
                        'type' => 'variable',
                        'value' => 'insensitive',
                        'file' => '/app/phalcon/Collection/Collection.zep',
                        'line' => 224,
                        'char' => 41,
                      ),
                      'file' => '/app/phalcon/Collection/Collection.zep',
                      'line' => 224,
                      'char' => 41,
                    ),
                    'file' => '/app/phalcon/Collection/Collection.zep',
                    'line' => 224,
                    'char' => 41,
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
                          'variable' => 'element',
                          'expr' => 
                          array (
                            'type' => 'mcall',
                            'variable' => 
                            array (
                              'type' => 'variable',
                              'value' => 'element',
                              'file' => '/app/phalcon/Collection/Collection.zep',
                              'line' => 225,
                              'char' => 39,
                            ),
                            'name' => 'lower',
                            'call-type' => 1,
                            'file' => '/app/phalcon/Collection/Collection.zep',
                            'line' => 225,
                            'char' => 47,
                          ),
                          'file' => '/app/phalcon/Collection/Collection.zep',
                          'line' => 225,
                          'char' => 47,
                        ),
                      ),
                      'file' => '/app/phalcon/Collection/Collection.zep',
                      'line' => 226,
                      'char' => 13,
                    ),
                  ),
                  'file' => '/app/phalcon/Collection/Collection.zep',
                  'line' => 228,
                  'char' => 15,
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
                      'variable' => 'data',
                      'expr' => 
                      array (
                        'type' => 'property-access',
                        'left' => 
                        array (
                          'type' => 'variable',
                          'value' => 'this',
                          'file' => '/app/phalcon/Collection/Collection.zep',
                          'line' => 228,
                          'char' => 34,
                        ),
                        'right' => 
                        array (
                          'type' => 'variable',
                          'value' => 'data',
                          'file' => '/app/phalcon/Collection/Collection.zep',
                          'line' => 228,
                          'char' => 39,
                        ),
                        'file' => '/app/phalcon/Collection/Collection.zep',
                        'line' => 228,
                        'char' => 39,
                      ),
                      'file' => '/app/phalcon/Collection/Collection.zep',
                      'line' => 228,
                      'char' => 39,
                    ),
                    1 => 
                    array (
                      'assign-type' => 'variable',
                      'operator' => 'assign',
                      'variable' => 'lowerKeys',
                      'expr' => 
                      array (
                        'type' => 'property-access',
                        'left' => 
                        array (
                          'type' => 'variable',
                          'value' => 'this',
                          'file' => '/app/phalcon/Collection/Collection.zep',
                          'line' => 229,
                          'char' => 34,
                        ),
                        'right' => 
                        array (
                          'type' => 'variable',
                          'value' => 'lowerKeys',
                          'file' => '/app/phalcon/Collection/Collection.zep',
                          'line' => 229,
                          'char' => 44,
                        ),
                        'file' => '/app/phalcon/Collection/Collection.zep',
                        'line' => 229,
                        'char' => 44,
                      ),
                      'file' => '/app/phalcon/Collection/Collection.zep',
                      'line' => 229,
                      'char' => 44,
                    ),
                    2 => 
                    array (
                      'assign-type' => 'variable',
                      'operator' => 'assign',
                      'variable' => 'key',
                      'expr' => 
                      array (
                        'type' => 'array-access',
                        'left' => 
                        array (
                          'type' => 'variable',
                          'value' => 'lowerKeys',
                          'file' => '/app/phalcon/Collection/Collection.zep',
                          'line' => 230,
                          'char' => 38,
                        ),
                        'right' => 
                        array (
                          'type' => 'variable',
                          'value' => 'element',
                          'file' => '/app/phalcon/Collection/Collection.zep',
                          'line' => 230,
                          'char' => 46,
                        ),
                        'file' => '/app/phalcon/Collection/Collection.zep',
                        'line' => 230,
                        'char' => 47,
                      ),
                      'file' => '/app/phalcon/Collection/Collection.zep',
                      'line' => 230,
                      'char' => 47,
                    ),
                  ),
                  'file' => '/app/phalcon/Collection/Collection.zep',
                  'line' => 232,
                  'char' => 17,
                ),
                2 => 
                array (
                  'type' => 'unset',
                  'expr' => 
                  array (
                    'type' => 'array-access',
                    'left' => 
                    array (
                      'type' => 'variable',
                      'value' => 'lowerKeys',
                      'file' => '/app/phalcon/Collection/Collection.zep',
                      'line' => 232,
                      'char' => 28,
                    ),
                    'right' => 
                    array (
                      'type' => 'variable',
                      'value' => 'element',
                      'file' => '/app/phalcon/Collection/Collection.zep',
                      'line' => 232,
                      'char' => 36,
                    ),
                    'file' => '/app/phalcon/Collection/Collection.zep',
                    'line' => 232,
                    'char' => 37,
                  ),
                  'file' => '/app/phalcon/Collection/Collection.zep',
                  'line' => 233,
                  'char' => 17,
                ),
                3 => 
                array (
                  'type' => 'unset',
                  'expr' => 
                  array (
                    'type' => 'array-access',
                    'left' => 
                    array (
                      'type' => 'variable',
                      'value' => 'data',
                      'file' => '/app/phalcon/Collection/Collection.zep',
                      'line' => 233,
                      'char' => 23,
                    ),
                    'right' => 
                    array (
                      'type' => 'variable',
                      'value' => 'key',
                      'file' => '/app/phalcon/Collection/Collection.zep',
                      'line' => 233,
                      'char' => 27,
                    ),
                    'file' => '/app/phalcon/Collection/Collection.zep',
                    'line' => 233,
                    'char' => 28,
                  ),
                  'file' => '/app/phalcon/Collection/Collection.zep',
                  'line' => 235,
                  'char' => 15,
                ),
                4 => 
                array (
                  'type' => 'let',
                  'assignments' => 
                  array (
                    0 => 
                    array (
                      'assign-type' => 'object-property',
                      'operator' => 'assign',
                      'variable' => 'this',
                      'property' => 'data',
                      'expr' => 
                      array (
                        'type' => 'variable',
                        'value' => 'data',
                        'file' => '/app/phalcon/Collection/Collection.zep',
                        'line' => 235,
                        'char' => 39,
                      ),
                      'file' => '/app/phalcon/Collection/Collection.zep',
                      'line' => 235,
                      'char' => 39,
                    ),
                    1 => 
                    array (
                      'assign-type' => 'object-property',
                      'operator' => 'assign',
                      'variable' => 'this',
                      'property' => 'lowerKeys',
                      'expr' => 
                      array (
                        'type' => 'variable',
                        'value' => 'lowerKeys',
                        'file' => '/app/phalcon/Collection/Collection.zep',
                        'line' => 236,
                        'char' => 44,
                      ),
                      'file' => '/app/phalcon/Collection/Collection.zep',
                      'line' => 236,
                      'char' => 44,
                    ),
                  ),
                  'file' => '/app/phalcon/Collection/Collection.zep',
                  'line' => 237,
                  'char' => 9,
                ),
              ),
              'file' => '/app/phalcon/Collection/Collection.zep',
              'line' => 238,
              'char' => 5,
            ),
          ),
          'docblock' => '**
     * Delete the element from the collection
     *',
          'return-type' => 
          array (
            'type' => 'return-type',
            'void' => 1,
            'file' => '/app/phalcon/Collection/Collection.zep',
            'line' => 219,
            'char' => 5,
          ),
          'file' => '/app/phalcon/Collection/Collection.zep',
          'line' => 218,
          'last-line' => 242,
          'char' => 19,
        ),
        17 => 
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
              'name' => 'element',
              'const' => 0,
              'data-type' => 'string',
              'mandatory' => 0,
              'reference' => 0,
              'file' => '/app/phalcon/Collection/Collection.zep',
              'line' => 243,
              'char' => 39,
            ),
            1 => 
            array (
              'type' => 'parameter',
              'name' => 'value',
              'const' => 0,
              'data-type' => 'variable',
              'mandatory' => 0,
              'reference' => 0,
              'file' => '/app/phalcon/Collection/Collection.zep',
              'line' => 243,
              'char' => 50,
            ),
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
                  'file' => '/app/phalcon/Collection/Collection.zep',
                  'line' => 245,
                  'char' => 14,
                ),
                'name' => 'setData',
                'call-type' => 1,
                'parameters' => 
                array (
                  0 => 
                  array (
                    'parameter' => 
                    array (
                      'type' => 'variable',
                      'value' => 'element',
                      'file' => '/app/phalcon/Collection/Collection.zep',
                      'line' => 245,
                      'char' => 30,
                    ),
                    'file' => '/app/phalcon/Collection/Collection.zep',
                    'line' => 245,
                    'char' => 30,
                  ),
                  1 => 
                  array (
                    'parameter' => 
                    array (
                      'type' => 'variable',
                      'value' => 'value',
                      'file' => '/app/phalcon/Collection/Collection.zep',
                      'line' => 245,
                      'char' => 37,
                    ),
                    'file' => '/app/phalcon/Collection/Collection.zep',
                    'line' => 245,
                    'char' => 37,
                  ),
                ),
                'file' => '/app/phalcon/Collection/Collection.zep',
                'line' => 245,
                'char' => 38,
              ),
              'file' => '/app/phalcon/Collection/Collection.zep',
              'line' => 246,
              'char' => 5,
            ),
          ),
          'docblock' => '**
     * Set an element in the collection
     *',
          'return-type' => 
          array (
            'type' => 'return-type',
            'void' => 1,
            'file' => '/app/phalcon/Collection/Collection.zep',
            'line' => 244,
            'char' => 5,
          ),
          'file' => '/app/phalcon/Collection/Collection.zep',
          'line' => 243,
          'last-line' => 251,
          'char' => 19,
        ),
        18 => 
        array (
          'visibility' => 
          array (
            0 => 'public',
          ),
          'type' => 'method',
          'name' => 'serialize',
          'statements' => 
          array (
            0 => 
            array (
              'type' => 'return',
              'expr' => 
              array (
                'type' => 'fcall',
                'name' => 'serialize',
                'call-type' => 1,
                'parameters' => 
                array (
                  0 => 
                  array (
                    'parameter' => 
                    array (
                      'type' => 'mcall',
                      'variable' => 
                      array (
                        'type' => 'variable',
                        'value' => 'this',
                        'file' => '/app/phalcon/Collection/Collection.zep',
                        'line' => 254,
                        'char' => 31,
                      ),
                      'name' => 'toArray',
                      'call-type' => 1,
                      'file' => '/app/phalcon/Collection/Collection.zep',
                      'line' => 254,
                      'char' => 41,
                    ),
                    'file' => '/app/phalcon/Collection/Collection.zep',
                    'line' => 254,
                    'char' => 41,
                  ),
                ),
                'file' => '/app/phalcon/Collection/Collection.zep',
                'line' => 254,
                'char' => 42,
              ),
              'file' => '/app/phalcon/Collection/Collection.zep',
              'line' => 255,
              'char' => 5,
            ),
          ),
          'docblock' => '**
     * String representation of object
     * See [serialize](https://php.net/manual/en/serializable.serialize.php)
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
                'file' => '/app/phalcon/Collection/Collection.zep',
                'line' => 253,
                'char' => 5,
              ),
            ),
            'void' => 0,
            'file' => '/app/phalcon/Collection/Collection.zep',
            'line' => 253,
            'char' => 5,
          ),
          'file' => '/app/phalcon/Collection/Collection.zep',
          'line' => 252,
          'last-line' => 259,
          'char' => 19,
        ),
        19 => 
        array (
          'visibility' => 
          array (
            0 => 'public',
          ),
          'type' => 'method',
          'name' => 'toArray',
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
                  'file' => '/app/phalcon/Collection/Collection.zep',
                  'line' => 262,
                  'char' => 21,
                ),
                'right' => 
                array (
                  'type' => 'variable',
                  'value' => 'data',
                  'file' => '/app/phalcon/Collection/Collection.zep',
                  'line' => 262,
                  'char' => 26,
                ),
                'file' => '/app/phalcon/Collection/Collection.zep',
                'line' => 262,
                'char' => 26,
              ),
              'file' => '/app/phalcon/Collection/Collection.zep',
              'line' => 263,
              'char' => 5,
            ),
          ),
          'docblock' => '**
     * Returns the object in an array format
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
                'file' => '/app/phalcon/Collection/Collection.zep',
                'line' => 261,
                'char' => 5,
              ),
            ),
            'void' => 0,
            'file' => '/app/phalcon/Collection/Collection.zep',
            'line' => 261,
            'char' => 5,
          ),
          'file' => '/app/phalcon/Collection/Collection.zep',
          'line' => 260,
          'last-line' => 274,
          'char' => 19,
        ),
        20 => 
        array (
          'visibility' => 
          array (
            0 => 'public',
          ),
          'type' => 'method',
          'name' => 'toJson',
          'parameters' => 
          array (
            0 => 
            array (
              'type' => 'parameter',
              'name' => 'options',
              'const' => 0,
              'data-type' => 'int',
              'mandatory' => 0,
              'default' => 
              array (
                'type' => 'int',
                'value' => '79',
                'file' => '/app/phalcon/Collection/Collection.zep',
                'line' => 275,
                'char' => 44,
              ),
              'reference' => 0,
              'file' => '/app/phalcon/Collection/Collection.zep',
              'line' => 275,
              'char' => 44,
            ),
          ),
          'statements' => 
          array (
            0 => 
            array (
              'type' => 'return',
              'expr' => 
              array (
                'type' => 'fcall',
                'name' => 'json_encode',
                'call-type' => 1,
                'parameters' => 
                array (
                  0 => 
                  array (
                    'parameter' => 
                    array (
                      'type' => 'mcall',
                      'variable' => 
                      array (
                        'type' => 'variable',
                        'value' => 'this',
                        'file' => '/app/phalcon/Collection/Collection.zep',
                        'line' => 277,
                        'char' => 33,
                      ),
                      'name' => 'toArray',
                      'call-type' => 1,
                      'file' => '/app/phalcon/Collection/Collection.zep',
                      'line' => 277,
                      'char' => 43,
                    ),
                    'file' => '/app/phalcon/Collection/Collection.zep',
                    'line' => 277,
                    'char' => 43,
                  ),
                  1 => 
                  array (
                    'parameter' => 
                    array (
                      'type' => 'variable',
                      'value' => 'options',
                      'file' => '/app/phalcon/Collection/Collection.zep',
                      'line' => 277,
                      'char' => 52,
                    ),
                    'file' => '/app/phalcon/Collection/Collection.zep',
                    'line' => 277,
                    'char' => 52,
                  ),
                ),
                'file' => '/app/phalcon/Collection/Collection.zep',
                'line' => 277,
                'char' => 53,
              ),
              'file' => '/app/phalcon/Collection/Collection.zep',
              'line' => 278,
              'char' => 5,
            ),
          ),
          'docblock' => '**
     * Returns the object in a JSON format
     *
     * The default string uses the following options for json_encode
     *
     * `JSON_HEX_TAG`, `JSON_HEX_APOS`, `JSON_HEX_AMP`, `JSON_HEX_QUOT`,
     * `JSON_UNESCAPED_SLASHES`
     *
     * See [rfc4627](https://www.ietf.org/rfc/rfc4627.txt)
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
                'file' => '/app/phalcon/Collection/Collection.zep',
                'line' => 276,
                'char' => 5,
              ),
            ),
            'void' => 0,
            'file' => '/app/phalcon/Collection/Collection.zep',
            'line' => 276,
            'char' => 5,
          ),
          'file' => '/app/phalcon/Collection/Collection.zep',
          'line' => 275,
          'last-line' => 283,
          'char' => 19,
        ),
        21 => 
        array (
          'visibility' => 
          array (
            0 => 'public',
          ),
          'type' => 'method',
          'name' => 'unserialize',
          'parameters' => 
          array (
            0 => 
            array (
              'type' => 'parameter',
              'name' => 'serialized',
              'const' => 0,
              'data-type' => 'variable',
              'mandatory' => 0,
              'reference' => 0,
              'file' => '/app/phalcon/Collection/Collection.zep',
              'line' => 284,
              'char' => 47,
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
                  'variable' => 'data',
                  'file' => '/app/phalcon/Collection/Collection.zep',
                  'line' => 286,
                  'char' => 17,
                ),
              ),
              'file' => '/app/phalcon/Collection/Collection.zep',
              'line' => 288,
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
                  'variable' => 'serialized',
                  'expr' => 
                  array (
                    'type' => 'cast',
                    'left' => 'string',
                    'right' => 
                    array (
                      'type' => 'variable',
                      'value' => 'serialized',
                      'file' => '/app/phalcon/Collection/Collection.zep',
                      'line' => 288,
                      'char' => 45,
                    ),
                    'file' => '/app/phalcon/Collection/Collection.zep',
                    'line' => 288,
                    'char' => 45,
                  ),
                  'file' => '/app/phalcon/Collection/Collection.zep',
                  'line' => 288,
                  'char' => 45,
                ),
                1 => 
                array (
                  'assign-type' => 'variable',
                  'operator' => 'assign',
                  'variable' => 'data',
                  'expr' => 
                  array (
                    'type' => 'fcall',
                    'name' => 'unserialize',
                    'call-type' => 1,
                    'parameters' => 
                    array (
                      0 => 
                      array (
                        'parameter' => 
                        array (
                          'type' => 'variable',
                          'value' => 'serialized',
                          'file' => '/app/phalcon/Collection/Collection.zep',
                          'line' => 289,
                          'char' => 48,
                        ),
                        'file' => '/app/phalcon/Collection/Collection.zep',
                        'line' => 289,
                        'char' => 48,
                      ),
                    ),
                    'file' => '/app/phalcon/Collection/Collection.zep',
                    'line' => 289,
                    'char' => 49,
                  ),
                  'file' => '/app/phalcon/Collection/Collection.zep',
                  'line' => 289,
                  'char' => 49,
                ),
              ),
              'file' => '/app/phalcon/Collection/Collection.zep',
              'line' => 291,
              'char' => 12,
            ),
            2 => 
            array (
              'type' => 'mcall',
              'expr' => 
              array (
                'type' => 'mcall',
                'variable' => 
                array (
                  'type' => 'variable',
                  'value' => 'this',
                  'file' => '/app/phalcon/Collection/Collection.zep',
                  'line' => 291,
                  'char' => 14,
                ),
                'name' => 'init',
                'call-type' => 1,
                'parameters' => 
                array (
                  0 => 
                  array (
                    'parameter' => 
                    array (
                      'type' => 'variable',
                      'value' => 'data',
                      'file' => '/app/phalcon/Collection/Collection.zep',
                      'line' => 291,
                      'char' => 24,
                    ),
                    'file' => '/app/phalcon/Collection/Collection.zep',
                    'line' => 291,
                    'char' => 24,
                  ),
                ),
                'file' => '/app/phalcon/Collection/Collection.zep',
                'line' => 291,
                'char' => 25,
              ),
              'file' => '/app/phalcon/Collection/Collection.zep',
              'line' => 292,
              'char' => 5,
            ),
          ),
          'docblock' => '**
     * Constructs the object
     * See [unserialize](https://php.net/manual/en/serializable.unserialize.php)
     *',
          'return-type' => 
          array (
            'type' => 'return-type',
            'void' => 1,
            'file' => '/app/phalcon/Collection/Collection.zep',
            'line' => 285,
            'char' => 5,
          ),
          'file' => '/app/phalcon/Collection/Collection.zep',
          'line' => 284,
          'last-line' => 296,
          'char' => 19,
        ),
        22 => 
        array (
          'visibility' => 
          array (
            0 => 'protected',
          ),
          'type' => 'method',
          'name' => 'setData',
          'parameters' => 
          array (
            0 => 
            array (
              'type' => 'parameter',
              'name' => 'element',
              'const' => 0,
              'data-type' => 'string',
              'mandatory' => 0,
              'reference' => 0,
              'file' => '/app/phalcon/Collection/Collection.zep',
              'line' => 297,
              'char' => 46,
            ),
            1 => 
            array (
              'type' => 'parameter',
              'name' => 'value',
              'const' => 0,
              'data-type' => 'variable',
              'mandatory' => 0,
              'reference' => 0,
              'file' => '/app/phalcon/Collection/Collection.zep',
              'line' => 297,
              'char' => 57,
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
                  'variable' => 'key',
                  'file' => '/app/phalcon/Collection/Collection.zep',
                  'line' => 299,
                  'char' => 16,
                ),
              ),
              'file' => '/app/phalcon/Collection/Collection.zep',
              'line' => 301,
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
                  'variable' => 'key',
                  'expr' => 
                  array (
                    'type' => 'ternary',
                    'left' => 
                    array (
                      'type' => 'list',
                      'left' => 
                      array (
                        'type' => 'identical',
                        'left' => 
                        array (
                          'type' => 'bool',
                          'value' => 'true',
                          'file' => '/app/phalcon/Collection/Collection.zep',
                          'line' => 301,
                          'char' => 27,
                        ),
                        'right' => 
                        array (
                          'type' => 'property-access',
                          'left' => 
                          array (
                            'type' => 'variable',
                            'value' => 'this',
                            'file' => '/app/phalcon/Collection/Collection.zep',
                            'line' => 301,
                            'char' => 34,
                          ),
                          'right' => 
                          array (
                            'type' => 'variable',
                            'value' => 'insensitive',
                            'file' => '/app/phalcon/Collection/Collection.zep',
                            'line' => 301,
                            'char' => 46,
                          ),
                          'file' => '/app/phalcon/Collection/Collection.zep',
                          'line' => 301,
                          'char' => 46,
                        ),
                        'file' => '/app/phalcon/Collection/Collection.zep',
                        'line' => 301,
                        'char' => 46,
                      ),
                      'file' => '/app/phalcon/Collection/Collection.zep',
                      'line' => 301,
                      'char' => 48,
                    ),
                    'right' => 
                    array (
                      'type' => 'mcall',
                      'variable' => 
                      array (
                        'type' => 'variable',
                        'value' => 'element',
                        'file' => '/app/phalcon/Collection/Collection.zep',
                        'line' => 301,
                        'char' => 58,
                      ),
                      'name' => 'lower',
                      'call-type' => 1,
                      'file' => '/app/phalcon/Collection/Collection.zep',
                      'line' => 301,
                      'char' => 67,
                    ),
                    'extra' => 
                    array (
                      'type' => 'variable',
                      'value' => 'element',
                      'file' => '/app/phalcon/Collection/Collection.zep',
                      'line' => 301,
                      'char' => 76,
                    ),
                    'file' => '/app/phalcon/Collection/Collection.zep',
                    'line' => 301,
                    'char' => 76,
                  ),
                  'file' => '/app/phalcon/Collection/Collection.zep',
                  'line' => 301,
                  'char' => 76,
                ),
              ),
              'file' => '/app/phalcon/Collection/Collection.zep',
              'line' => 303,
              'char' => 11,
            ),
            2 => 
            array (
              'type' => 'let',
              'assignments' => 
              array (
                0 => 
                array (
                  'assign-type' => 'object-property-array-index',
                  'operator' => 'assign',
                  'variable' => 'this',
                  'property' => 'data',
                  'index-expr' => 
                  array (
                    0 => 
                    array (
                      'type' => 'variable',
                      'value' => 'element',
                      'file' => '/app/phalcon/Collection/Collection.zep',
                      'line' => 303,
                      'char' => 31,
                    ),
                  ),
                  'expr' => 
                  array (
                    'type' => 'variable',
                    'value' => 'value',
                    'file' => '/app/phalcon/Collection/Collection.zep',
                    'line' => 303,
                    'char' => 41,
                  ),
                  'file' => '/app/phalcon/Collection/Collection.zep',
                  'line' => 303,
                  'char' => 41,
                ),
                1 => 
                array (
                  'assign-type' => 'object-property-array-index',
                  'operator' => 'assign',
                  'variable' => 'this',
                  'property' => 'lowerKeys',
                  'index-expr' => 
                  array (
                    0 => 
                    array (
                      'type' => 'variable',
                      'value' => 'key',
                      'file' => '/app/phalcon/Collection/Collection.zep',
                      'line' => 304,
                      'char' => 32,
                    ),
                  ),
                  'expr' => 
                  array (
                    'type' => 'variable',
                    'value' => 'element',
                    'file' => '/app/phalcon/Collection/Collection.zep',
                    'line' => 304,
                    'char' => 43,
                  ),
                  'file' => '/app/phalcon/Collection/Collection.zep',
                  'line' => 304,
                  'char' => 43,
                ),
              ),
              'file' => '/app/phalcon/Collection/Collection.zep',
              'line' => 305,
              'char' => 5,
            ),
          ),
          'docblock' => '**
     * Internal method to set data
     *',
          'return-type' => 
          array (
            'type' => 'return-type',
            'void' => 1,
            'file' => '/app/phalcon/Collection/Collection.zep',
            'line' => 298,
            'char' => 5,
          ),
          'file' => '/app/phalcon/Collection/Collection.zep',
          'line' => 297,
          'last-line' => 306,
          'char' => 22,
        ),
      ),
      'file' => '/app/phalcon/Collection/Collection.zep',
      'line' => 28,
      'char' => 5,
    ),
    'file' => '/app/phalcon/Collection/Collection.zep',
    'line' => 28,
    'char' => 5,
  ),
);