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
    'file' => '/app/phalcon/Registry.zep',
    'line' => 11,
    'char' => 9,
  ),
  1 => 
  array (
    'type' => 'namespace',
    'name' => 'Phalcon',
    'file' => '/app/phalcon/Registry.zep',
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
        'name' => 'Phalcon\\Collection\\Collection',
        'file' => '/app/phalcon/Registry.zep',
        'line' => 13,
        'char' => 34,
      ),
    ),
    'file' => '/app/phalcon/Registry.zep',
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
        'name' => 'Traversable',
        'file' => '/app/phalcon/Registry.zep',
        'line' => 14,
        'char' => 16,
      ),
    ),
    'file' => '/app/phalcon/Registry.zep',
    'line' => 65,
    'char' => 2,
  ),
  4 => 
  array (
    'type' => 'comment',
    'value' => '**
 * Phalcon\\Registry
 *
 * A registry is a container for storing objects and values in the application
 * space. By storing the value in a registry, the same object is always
 * available throughout your application.
 *
 *```php
 * $registry = new \\Phalcon\\Registry();
 *
 * // Set value
 * $registry->something = "something";
 * // or
 * $registry["something"] = "something";
 *
 * // Get value
 * $value = $registry->something;
 * // or
 * $value = $registry["something"];
 *
 * // Check if the key exists
 * $exists = isset($registry->something);
 * // or
 * $exists = isset($registry["something"]);
 *
 * // Unset
 * unset($registry->something);
 * // or
 * unset($registry["something"]);
 *```
 *
 * In addition to ArrayAccess, Phalcon\\Registry also implements Countable
 * (count($registry) will return the number of elements in the registry),
 * Serializable and Iterator (you can iterate over the registry using a foreach
 * loop) interfaces. For PHP 5.4 and higher, JsonSerializable interface is
 * implemented.
 *
 * Phalcon\\Registry is very fast (it is typically faster than any userspace
 * implementation of the registry); however, this comes at a price:
 * Phalcon\\Registry is a final class and cannot be inherited from.
 *
 * Though Phalcon\\Registry exposes methods like __get(), offsetGet(), count() etc,
 * it is not recommended to invoke them manually (these methods exist mainly to
 * match the interfaces the registry implements): $registry->__get("property")
 * is several times slower than $registry->property.
 *
 * Internally all the magic methods (and interfaces except JsonSerializable)
 * are implemented using object handlers or similar techniques: this allows to
 * bypass relatively slow method calls.
 *',
    'file' => '/app/phalcon/Registry.zep',
    'line' => 66,
    'char' => 5,
  ),
  5 => 
  array (
    'type' => 'class',
    'name' => 'Registry',
    'abstract' => 0,
    'final' => 1,
    'extends' => 'Collection',
    'definition' => 
    array (
      'methods' => 
      array (
        0 => 
        array (
          'visibility' => 
          array (
            0 => 'final',
            1 => 'public',
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
              'mandatory' => 1,
              'default' => 
              array (
                'type' => 'null',
                'file' => '/app/phalcon/Registry.zep',
                'line' => 71,
                'char' => 57,
              ),
              'reference' => 0,
              'file' => '/app/phalcon/Registry.zep',
              'line' => 71,
              'char' => 57,
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
                      'type' => 'variable',
                      'value' => 'data',
                      'file' => '/app/phalcon/Registry.zep',
                      'line' => 73,
                      'char' => 33,
                    ),
                    'file' => '/app/phalcon/Registry.zep',
                    'line' => 73,
                    'char' => 33,
                  ),
                ),
                'file' => '/app/phalcon/Registry.zep',
                'line' => 73,
                'char' => 34,
              ),
              'file' => '/app/phalcon/Registry.zep',
              'line' => 74,
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
            'file' => '/app/phalcon/Registry.zep',
            'line' => 72,
            'char' => 5,
          ),
          'file' => '/app/phalcon/Registry.zep',
          'line' => 71,
          'last-line' => 78,
          'char' => 25,
        ),
        1 => 
        array (
          'visibility' => 
          array (
            0 => 'final',
            1 => 'public',
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
              'mandatory' => 1,
              'reference' => 0,
              'file' => '/app/phalcon/Registry.zep',
              'line' => 79,
              'char' => 48,
            ),
          ),
          'statements' => 
          array (
            0 => 
            array (
              'type' => 'return',
              'expr' => 
              array (
                'type' => 'scall',
                'dynamic-class' => 0,
                'class' => 'parent',
                'dynamic' => 0,
                'name' => 'get',
                'parameters' => 
                array (
                  0 => 
                  array (
                    'parameter' => 
                    array (
                      'type' => 'variable',
                      'value' => 'element',
                      'file' => '/app/phalcon/Registry.zep',
                      'line' => 81,
                      'char' => 35,
                    ),
                    'file' => '/app/phalcon/Registry.zep',
                    'line' => 81,
                    'char' => 35,
                  ),
                ),
                'file' => '/app/phalcon/Registry.zep',
                'line' => 81,
                'char' => 36,
              ),
              'file' => '/app/phalcon/Registry.zep',
              'line' => 82,
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
                'file' => '/app/phalcon/Registry.zep',
                'line' => 80,
                'char' => 5,
              ),
            ),
            'void' => 0,
            'file' => '/app/phalcon/Registry.zep',
            'line' => 80,
            'char' => 5,
          ),
          'file' => '/app/phalcon/Registry.zep',
          'line' => 79,
          'last-line' => 86,
          'char' => 25,
        ),
        2 => 
        array (
          'visibility' => 
          array (
            0 => 'final',
            1 => 'public',
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
              'mandatory' => 1,
              'reference' => 0,
              'file' => '/app/phalcon/Registry.zep',
              'line' => 87,
              'char' => 50,
            ),
          ),
          'statements' => 
          array (
            0 => 
            array (
              'type' => 'return',
              'expr' => 
              array (
                'type' => 'scall',
                'dynamic-class' => 0,
                'class' => 'parent',
                'dynamic' => 0,
                'name' => 'has',
                'parameters' => 
                array (
                  0 => 
                  array (
                    'parameter' => 
                    array (
                      'type' => 'variable',
                      'value' => 'element',
                      'file' => '/app/phalcon/Registry.zep',
                      'line' => 89,
                      'char' => 35,
                    ),
                    'file' => '/app/phalcon/Registry.zep',
                    'line' => 89,
                    'char' => 35,
                  ),
                ),
                'file' => '/app/phalcon/Registry.zep',
                'line' => 89,
                'char' => 36,
              ),
              'file' => '/app/phalcon/Registry.zep',
              'line' => 90,
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
                'file' => '/app/phalcon/Registry.zep',
                'line' => 88,
                'char' => 5,
              ),
            ),
            'void' => 0,
            'file' => '/app/phalcon/Registry.zep',
            'line' => 88,
            'char' => 5,
          ),
          'file' => '/app/phalcon/Registry.zep',
          'line' => 87,
          'last-line' => 94,
          'char' => 25,
        ),
        3 => 
        array (
          'visibility' => 
          array (
            0 => 'final',
            1 => 'public',
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
              'mandatory' => 1,
              'reference' => 0,
              'file' => '/app/phalcon/Registry.zep',
              'line' => 95,
              'char' => 48,
            ),
            1 => 
            array (
              'type' => 'parameter',
              'name' => 'value',
              'const' => 0,
              'data-type' => 'variable',
              'mandatory' => 0,
              'reference' => 0,
              'file' => '/app/phalcon/Registry.zep',
              'line' => 95,
              'char' => 59,
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
                'name' => 'set',
                'parameters' => 
                array (
                  0 => 
                  array (
                    'parameter' => 
                    array (
                      'type' => 'variable',
                      'value' => 'element',
                      'file' => '/app/phalcon/Registry.zep',
                      'line' => 97,
                      'char' => 28,
                    ),
                    'file' => '/app/phalcon/Registry.zep',
                    'line' => 97,
                    'char' => 28,
                  ),
                  1 => 
                  array (
                    'parameter' => 
                    array (
                      'type' => 'variable',
                      'value' => 'value',
                      'file' => '/app/phalcon/Registry.zep',
                      'line' => 97,
                      'char' => 35,
                    ),
                    'file' => '/app/phalcon/Registry.zep',
                    'line' => 97,
                    'char' => 35,
                  ),
                ),
                'file' => '/app/phalcon/Registry.zep',
                'line' => 97,
                'char' => 36,
              ),
              'file' => '/app/phalcon/Registry.zep',
              'line' => 98,
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
            'file' => '/app/phalcon/Registry.zep',
            'line' => 96,
            'char' => 5,
          ),
          'file' => '/app/phalcon/Registry.zep',
          'line' => 95,
          'last-line' => 102,
          'char' => 25,
        ),
        4 => 
        array (
          'visibility' => 
          array (
            0 => 'final',
            1 => 'public',
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
              'mandatory' => 1,
              'reference' => 0,
              'file' => '/app/phalcon/Registry.zep',
              'line' => 103,
              'char' => 50,
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
                'name' => 'remove',
                'parameters' => 
                array (
                  0 => 
                  array (
                    'parameter' => 
                    array (
                      'type' => 'variable',
                      'value' => 'element',
                      'file' => '/app/phalcon/Registry.zep',
                      'line' => 105,
                      'char' => 31,
                    ),
                    'file' => '/app/phalcon/Registry.zep',
                    'line' => 105,
                    'char' => 31,
                  ),
                ),
                'file' => '/app/phalcon/Registry.zep',
                'line' => 105,
                'char' => 32,
              ),
              'file' => '/app/phalcon/Registry.zep',
              'line' => 106,
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
            'file' => '/app/phalcon/Registry.zep',
            'line' => 104,
            'char' => 5,
          ),
          'file' => '/app/phalcon/Registry.zep',
          'line' => 103,
          'last-line' => 110,
          'char' => 25,
        ),
        5 => 
        array (
          'visibility' => 
          array (
            0 => 'final',
            1 => 'public',
          ),
          'type' => 'method',
          'name' => 'clear',
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
                'name' => 'clear',
                'file' => '/app/phalcon/Registry.zep',
                'line' => 113,
                'char' => 24,
              ),
              'file' => '/app/phalcon/Registry.zep',
              'line' => 114,
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
            'file' => '/app/phalcon/Registry.zep',
            'line' => 112,
            'char' => 5,
          ),
          'file' => '/app/phalcon/Registry.zep',
          'line' => 111,
          'last-line' => 120,
          'char' => 25,
        ),
        6 => 
        array (
          'visibility' => 
          array (
            0 => 'final',
            1 => 'public',
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
                'type' => 'scall',
                'dynamic-class' => 0,
                'class' => 'parent',
                'dynamic' => 0,
                'name' => 'count',
                'file' => '/app/phalcon/Registry.zep',
                'line' => 123,
                'char' => 31,
              ),
              'file' => '/app/phalcon/Registry.zep',
              'line' => 124,
              'char' => 5,
            ),
          ),
          'docblock' => '**
     * Count elements of an object
     *
     * @link https://php.net/manual/en/countable.count.php
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
                'file' => '/app/phalcon/Registry.zep',
                'line' => 122,
                'char' => 5,
              ),
            ),
            'void' => 0,
            'file' => '/app/phalcon/Registry.zep',
            'line' => 122,
            'char' => 5,
          ),
          'file' => '/app/phalcon/Registry.zep',
          'line' => 121,
          'last-line' => 128,
          'char' => 25,
        ),
        7 => 
        array (
          'visibility' => 
          array (
            0 => 'final',
            1 => 'public',
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
              'mandatory' => 1,
              'reference' => 0,
              'file' => '/app/phalcon/Registry.zep',
              'line' => 129,
              'char' => 46,
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
                'file' => '/app/phalcon/Registry.zep',
                'line' => 129,
                'char' => 71,
              ),
              'reference' => 0,
              'file' => '/app/phalcon/Registry.zep',
              'line' => 129,
              'char' => 71,
            ),
          ),
          'statements' => 
          array (
            0 => 
            array (
              'type' => 'return',
              'expr' => 
              array (
                'type' => 'scall',
                'dynamic-class' => 0,
                'class' => 'parent',
                'dynamic' => 0,
                'name' => 'get',
                'parameters' => 
                array (
                  0 => 
                  array (
                    'parameter' => 
                    array (
                      'type' => 'variable',
                      'value' => 'element',
                      'file' => '/app/phalcon/Registry.zep',
                      'line' => 131,
                      'char' => 35,
                    ),
                    'file' => '/app/phalcon/Registry.zep',
                    'line' => 131,
                    'char' => 35,
                  ),
                  1 => 
                  array (
                    'parameter' => 
                    array (
                      'type' => 'variable',
                      'value' => 'defaultValue',
                      'file' => '/app/phalcon/Registry.zep',
                      'line' => 131,
                      'char' => 49,
                    ),
                    'file' => '/app/phalcon/Registry.zep',
                    'line' => 131,
                    'char' => 49,
                  ),
                ),
                'file' => '/app/phalcon/Registry.zep',
                'line' => 131,
                'char' => 50,
              ),
              'file' => '/app/phalcon/Registry.zep',
              'line' => 132,
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
                'file' => '/app/phalcon/Registry.zep',
                'line' => 130,
                'char' => 5,
              ),
            ),
            'void' => 0,
            'file' => '/app/phalcon/Registry.zep',
            'line' => 130,
            'char' => 5,
          ),
          'file' => '/app/phalcon/Registry.zep',
          'line' => 129,
          'last-line' => 136,
          'char' => 25,
        ),
        8 => 
        array (
          'visibility' => 
          array (
            0 => 'final',
            1 => 'public',
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
                'type' => 'scall',
                'dynamic-class' => 0,
                'class' => 'parent',
                'dynamic' => 0,
                'name' => 'getIterator',
                'file' => '/app/phalcon/Registry.zep',
                'line' => 139,
                'char' => 37,
              ),
              'file' => '/app/phalcon/Registry.zep',
              'line' => 140,
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
                  'file' => '/app/phalcon/Registry.zep',
                  'line' => 138,
                  'char' => 5,
                ),
                'collection' => 0,
                'file' => '/app/phalcon/Registry.zep',
                'line' => 138,
                'char' => 5,
              ),
            ),
            'void' => 0,
            'file' => '/app/phalcon/Registry.zep',
            'line' => 138,
            'char' => 5,
          ),
          'file' => '/app/phalcon/Registry.zep',
          'line' => 137,
          'last-line' => 144,
          'char' => 25,
        ),
        9 => 
        array (
          'visibility' => 
          array (
            0 => 'final',
            1 => 'public',
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
              'mandatory' => 1,
              'reference' => 0,
              'file' => '/app/phalcon/Registry.zep',
              'line' => 145,
              'char' => 46,
            ),
          ),
          'statements' => 
          array (
            0 => 
            array (
              'type' => 'return',
              'expr' => 
              array (
                'type' => 'scall',
                'dynamic-class' => 0,
                'class' => 'parent',
                'dynamic' => 0,
                'name' => 'has',
                'parameters' => 
                array (
                  0 => 
                  array (
                    'parameter' => 
                    array (
                      'type' => 'variable',
                      'value' => 'element',
                      'file' => '/app/phalcon/Registry.zep',
                      'line' => 147,
                      'char' => 35,
                    ),
                    'file' => '/app/phalcon/Registry.zep',
                    'line' => 147,
                    'char' => 35,
                  ),
                ),
                'file' => '/app/phalcon/Registry.zep',
                'line' => 147,
                'char' => 36,
              ),
              'file' => '/app/phalcon/Registry.zep',
              'line' => 148,
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
                'file' => '/app/phalcon/Registry.zep',
                'line' => 146,
                'char' => 5,
              ),
            ),
            'void' => 0,
            'file' => '/app/phalcon/Registry.zep',
            'line' => 146,
            'char' => 5,
          ),
          'file' => '/app/phalcon/Registry.zep',
          'line' => 145,
          'last-line' => 152,
          'char' => 25,
        ),
        10 => 
        array (
          'visibility' => 
          array (
            0 => 'final',
            1 => 'public',
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
              'mandatory' => 1,
              'default' => 
              array (
                'type' => 'empty-array',
                'file' => '/app/phalcon/Registry.zep',
                'line' => 153,
                'char' => 48,
              ),
              'reference' => 0,
              'file' => '/app/phalcon/Registry.zep',
              'line' => 153,
              'char' => 48,
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
                'name' => 'init',
                'parameters' => 
                array (
                  0 => 
                  array (
                    'parameter' => 
                    array (
                      'type' => 'variable',
                      'value' => 'data',
                      'file' => '/app/phalcon/Registry.zep',
                      'line' => 155,
                      'char' => 26,
                    ),
                    'file' => '/app/phalcon/Registry.zep',
                    'line' => 155,
                    'char' => 26,
                  ),
                ),
                'file' => '/app/phalcon/Registry.zep',
                'line' => 155,
                'char' => 27,
              ),
              'file' => '/app/phalcon/Registry.zep',
              'line' => 156,
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
            'file' => '/app/phalcon/Registry.zep',
            'line' => 154,
            'char' => 5,
          ),
          'file' => '/app/phalcon/Registry.zep',
          'line' => 153,
          'last-line' => 162,
          'char' => 25,
        ),
        11 => 
        array (
          'visibility' => 
          array (
            0 => 'final',
            1 => 'public',
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
                'type' => 'scall',
                'dynamic-class' => 0,
                'class' => 'parent',
                'dynamic' => 0,
                'name' => 'jsonSerialize',
                'file' => '/app/phalcon/Registry.zep',
                'line' => 165,
                'char' => 39,
              ),
              'file' => '/app/phalcon/Registry.zep',
              'line' => 166,
              'char' => 5,
            ),
          ),
          'docblock' => '**
     * Specify data which should be serialized to JSON
     *
     * @link https://php.net/manual/en/jsonserializable.jsonserialize.php
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
                'file' => '/app/phalcon/Registry.zep',
                'line' => 164,
                'char' => 5,
              ),
            ),
            'void' => 0,
            'file' => '/app/phalcon/Registry.zep',
            'line' => 164,
            'char' => 5,
          ),
          'file' => '/app/phalcon/Registry.zep',
          'line' => 163,
          'last-line' => 172,
          'char' => 25,
        ),
        12 => 
        array (
          'visibility' => 
          array (
            0 => 'final',
            1 => 'public',
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
              'file' => '/app/phalcon/Registry.zep',
              'line' => 173,
              'char' => 51,
            ),
          ),
          'statements' => 
          array (
            0 => 
            array (
              'type' => 'return',
              'expr' => 
              array (
                'type' => 'scall',
                'dynamic-class' => 0,
                'class' => 'parent',
                'dynamic' => 0,
                'name' => 'has',
                'parameters' => 
                array (
                  0 => 
                  array (
                    'parameter' => 
                    array (
                      'type' => 'variable',
                      'value' => 'element',
                      'file' => '/app/phalcon/Registry.zep',
                      'line' => 175,
                      'char' => 35,
                    ),
                    'file' => '/app/phalcon/Registry.zep',
                    'line' => 175,
                    'char' => 35,
                  ),
                ),
                'file' => '/app/phalcon/Registry.zep',
                'line' => 175,
                'char' => 36,
              ),
              'file' => '/app/phalcon/Registry.zep',
              'line' => 176,
              'char' => 5,
            ),
          ),
          'docblock' => '**
     * Whether a offset exists
     *
     * @link https://php.net/manual/en/arrayaccess.offsetexists.php
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
                'file' => '/app/phalcon/Registry.zep',
                'line' => 174,
                'char' => 5,
              ),
            ),
            'void' => 0,
            'file' => '/app/phalcon/Registry.zep',
            'line' => 174,
            'char' => 5,
          ),
          'file' => '/app/phalcon/Registry.zep',
          'line' => 173,
          'last-line' => 182,
          'char' => 25,
        ),
        13 => 
        array (
          'visibility' => 
          array (
            0 => 'final',
            1 => 'public',
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
              'file' => '/app/phalcon/Registry.zep',
              'line' => 183,
              'char' => 48,
            ),
          ),
          'statements' => 
          array (
            0 => 
            array (
              'type' => 'return',
              'expr' => 
              array (
                'type' => 'scall',
                'dynamic-class' => 0,
                'class' => 'parent',
                'dynamic' => 0,
                'name' => 'get',
                'parameters' => 
                array (
                  0 => 
                  array (
                    'parameter' => 
                    array (
                      'type' => 'variable',
                      'value' => 'element',
                      'file' => '/app/phalcon/Registry.zep',
                      'line' => 185,
                      'char' => 35,
                    ),
                    'file' => '/app/phalcon/Registry.zep',
                    'line' => 185,
                    'char' => 35,
                  ),
                ),
                'file' => '/app/phalcon/Registry.zep',
                'line' => 185,
                'char' => 36,
              ),
              'file' => '/app/phalcon/Registry.zep',
              'line' => 186,
              'char' => 5,
            ),
          ),
          'docblock' => '**
     * Offset to retrieve
     *
     * @link https://php.net/manual/en/arrayaccess.offsetget.php
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
                'file' => '/app/phalcon/Registry.zep',
                'line' => 184,
                'char' => 5,
              ),
            ),
            'void' => 0,
            'file' => '/app/phalcon/Registry.zep',
            'line' => 184,
            'char' => 5,
          ),
          'file' => '/app/phalcon/Registry.zep',
          'line' => 183,
          'last-line' => 192,
          'char' => 25,
        ),
        14 => 
        array (
          'visibility' => 
          array (
            0 => 'final',
            1 => 'public',
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
              'file' => '/app/phalcon/Registry.zep',
              'line' => 193,
              'char' => 48,
            ),
            1 => 
            array (
              'type' => 'parameter',
              'name' => 'value',
              'const' => 0,
              'data-type' => 'variable',
              'mandatory' => 0,
              'reference' => 0,
              'file' => '/app/phalcon/Registry.zep',
              'line' => 193,
              'char' => 59,
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
                'name' => 'set',
                'parameters' => 
                array (
                  0 => 
                  array (
                    'parameter' => 
                    array (
                      'type' => 'variable',
                      'value' => 'element',
                      'file' => '/app/phalcon/Registry.zep',
                      'line' => 195,
                      'char' => 28,
                    ),
                    'file' => '/app/phalcon/Registry.zep',
                    'line' => 195,
                    'char' => 28,
                  ),
                  1 => 
                  array (
                    'parameter' => 
                    array (
                      'type' => 'variable',
                      'value' => 'value',
                      'file' => '/app/phalcon/Registry.zep',
                      'line' => 195,
                      'char' => 35,
                    ),
                    'file' => '/app/phalcon/Registry.zep',
                    'line' => 195,
                    'char' => 35,
                  ),
                ),
                'file' => '/app/phalcon/Registry.zep',
                'line' => 195,
                'char' => 36,
              ),
              'file' => '/app/phalcon/Registry.zep',
              'line' => 196,
              'char' => 5,
            ),
          ),
          'docblock' => '**
     * Offset to set
     *
     * @link https://php.net/manual/en/arrayaccess.offsetset.php
     *',
          'return-type' => 
          array (
            'type' => 'return-type',
            'void' => 1,
            'file' => '/app/phalcon/Registry.zep',
            'line' => 194,
            'char' => 5,
          ),
          'file' => '/app/phalcon/Registry.zep',
          'line' => 193,
          'last-line' => 202,
          'char' => 25,
        ),
        15 => 
        array (
          'visibility' => 
          array (
            0 => 'final',
            1 => 'public',
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
              'file' => '/app/phalcon/Registry.zep',
              'line' => 203,
              'char' => 50,
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
                'name' => 'remove',
                'parameters' => 
                array (
                  0 => 
                  array (
                    'parameter' => 
                    array (
                      'type' => 'variable',
                      'value' => 'element',
                      'file' => '/app/phalcon/Registry.zep',
                      'line' => 205,
                      'char' => 31,
                    ),
                    'file' => '/app/phalcon/Registry.zep',
                    'line' => 205,
                    'char' => 31,
                  ),
                ),
                'file' => '/app/phalcon/Registry.zep',
                'line' => 205,
                'char' => 32,
              ),
              'file' => '/app/phalcon/Registry.zep',
              'line' => 206,
              'char' => 5,
            ),
          ),
          'docblock' => '**
     * Offset to unset
     *
     * @link https://php.net/manual/en/arrayaccess.offsetunset.php
     *',
          'return-type' => 
          array (
            'type' => 'return-type',
            'void' => 1,
            'file' => '/app/phalcon/Registry.zep',
            'line' => 204,
            'char' => 5,
          ),
          'file' => '/app/phalcon/Registry.zep',
          'line' => 203,
          'last-line' => 210,
          'char' => 25,
        ),
        16 => 
        array (
          'visibility' => 
          array (
            0 => 'final',
            1 => 'public',
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
              'mandatory' => 1,
              'reference' => 0,
              'file' => '/app/phalcon/Registry.zep',
              'line' => 211,
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
                'name' => 'remove',
                'parameters' => 
                array (
                  0 => 
                  array (
                    'parameter' => 
                    array (
                      'type' => 'variable',
                      'value' => 'element',
                      'file' => '/app/phalcon/Registry.zep',
                      'line' => 213,
                      'char' => 31,
                    ),
                    'file' => '/app/phalcon/Registry.zep',
                    'line' => 213,
                    'char' => 31,
                  ),
                ),
                'file' => '/app/phalcon/Registry.zep',
                'line' => 213,
                'char' => 32,
              ),
              'file' => '/app/phalcon/Registry.zep',
              'line' => 214,
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
            'file' => '/app/phalcon/Registry.zep',
            'line' => 212,
            'char' => 5,
          ),
          'file' => '/app/phalcon/Registry.zep',
          'line' => 211,
          'last-line' => 220,
          'char' => 25,
        ),
        17 => 
        array (
          'visibility' => 
          array (
            0 => 'final',
            1 => 'public',
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
                'type' => 'scall',
                'dynamic-class' => 0,
                'class' => 'parent',
                'dynamic' => 0,
                'name' => 'serialize',
                'file' => '/app/phalcon/Registry.zep',
                'line' => 223,
                'char' => 35,
              ),
              'file' => '/app/phalcon/Registry.zep',
              'line' => 224,
              'char' => 5,
            ),
          ),
          'docblock' => '**
     * String representation of object
     *
     * @link https://php.net/manual/en/serializable.serialize.php
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
                'file' => '/app/phalcon/Registry.zep',
                'line' => 222,
                'char' => 5,
              ),
            ),
            'void' => 0,
            'file' => '/app/phalcon/Registry.zep',
            'line' => 222,
            'char' => 5,
          ),
          'file' => '/app/phalcon/Registry.zep',
          'line' => 221,
          'last-line' => 228,
          'char' => 25,
        ),
        18 => 
        array (
          'visibility' => 
          array (
            0 => 'final',
            1 => 'public',
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
              'mandatory' => 1,
              'reference' => 0,
              'file' => '/app/phalcon/Registry.zep',
              'line' => 229,
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
              'file' => '/app/phalcon/Registry.zep',
              'line' => 229,
              'char' => 57,
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
                'name' => 'set',
                'parameters' => 
                array (
                  0 => 
                  array (
                    'parameter' => 
                    array (
                      'type' => 'variable',
                      'value' => 'element',
                      'file' => '/app/phalcon/Registry.zep',
                      'line' => 231,
                      'char' => 28,
                    ),
                    'file' => '/app/phalcon/Registry.zep',
                    'line' => 231,
                    'char' => 28,
                  ),
                  1 => 
                  array (
                    'parameter' => 
                    array (
                      'type' => 'variable',
                      'value' => 'value',
                      'file' => '/app/phalcon/Registry.zep',
                      'line' => 231,
                      'char' => 35,
                    ),
                    'file' => '/app/phalcon/Registry.zep',
                    'line' => 231,
                    'char' => 35,
                  ),
                ),
                'file' => '/app/phalcon/Registry.zep',
                'line' => 231,
                'char' => 36,
              ),
              'file' => '/app/phalcon/Registry.zep',
              'line' => 232,
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
            'file' => '/app/phalcon/Registry.zep',
            'line' => 230,
            'char' => 5,
          ),
          'file' => '/app/phalcon/Registry.zep',
          'line' => 229,
          'last-line' => 236,
          'char' => 25,
        ),
        19 => 
        array (
          'visibility' => 
          array (
            0 => 'final',
            1 => 'public',
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
                'type' => 'scall',
                'dynamic-class' => 0,
                'class' => 'parent',
                'dynamic' => 0,
                'name' => 'toArray',
                'file' => '/app/phalcon/Registry.zep',
                'line' => 239,
                'char' => 33,
              ),
              'file' => '/app/phalcon/Registry.zep',
              'line' => 240,
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
                'file' => '/app/phalcon/Registry.zep',
                'line' => 238,
                'char' => 5,
              ),
            ),
            'void' => 0,
            'file' => '/app/phalcon/Registry.zep',
            'line' => 238,
            'char' => 5,
          ),
          'file' => '/app/phalcon/Registry.zep',
          'line' => 237,
          'last-line' => 250,
          'char' => 25,
        ),
        20 => 
        array (
          'visibility' => 
          array (
            0 => 'final',
            1 => 'public',
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
                'file' => '/app/phalcon/Registry.zep',
                'line' => 251,
                'char' => 50,
              ),
              'reference' => 0,
              'file' => '/app/phalcon/Registry.zep',
              'line' => 251,
              'char' => 50,
            ),
          ),
          'statements' => 
          array (
            0 => 
            array (
              'type' => 'return',
              'expr' => 
              array (
                'type' => 'scall',
                'dynamic-class' => 0,
                'class' => 'parent',
                'dynamic' => 0,
                'name' => 'toJson',
                'parameters' => 
                array (
                  0 => 
                  array (
                    'parameter' => 
                    array (
                      'type' => 'variable',
                      'value' => 'options',
                      'file' => '/app/phalcon/Registry.zep',
                      'line' => 253,
                      'char' => 38,
                    ),
                    'file' => '/app/phalcon/Registry.zep',
                    'line' => 253,
                    'char' => 38,
                  ),
                ),
                'file' => '/app/phalcon/Registry.zep',
                'line' => 253,
                'char' => 39,
              ),
              'file' => '/app/phalcon/Registry.zep',
              'line' => 254,
              'char' => 5,
            ),
          ),
          'docblock' => '**
     * Returns the object in a JSON format
     *
     * The default string uses the following options for json_encode
     *
     * JSON_HEX_TAG, JSON_HEX_APOS, JSON_HEX_AMP, JSON_HEX_QUOT, JSON_UNESCAPED_SLASHES
     *
     * @see https://www.ietf.org/rfc/rfc4627.txt
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
                'file' => '/app/phalcon/Registry.zep',
                'line' => 252,
                'char' => 5,
              ),
            ),
            'void' => 0,
            'file' => '/app/phalcon/Registry.zep',
            'line' => 252,
            'char' => 5,
          ),
          'file' => '/app/phalcon/Registry.zep',
          'line' => 251,
          'last-line' => 260,
          'char' => 25,
        ),
        21 => 
        array (
          'visibility' => 
          array (
            0 => 'final',
            1 => 'public',
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
              'file' => '/app/phalcon/Registry.zep',
              'line' => 261,
              'char' => 53,
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
                'name' => 'unserialize',
                'parameters' => 
                array (
                  0 => 
                  array (
                    'parameter' => 
                    array (
                      'type' => 'variable',
                      'value' => 'serialized',
                      'file' => '/app/phalcon/Registry.zep',
                      'line' => 263,
                      'char' => 39,
                    ),
                    'file' => '/app/phalcon/Registry.zep',
                    'line' => 263,
                    'char' => 39,
                  ),
                ),
                'file' => '/app/phalcon/Registry.zep',
                'line' => 263,
                'char' => 40,
              ),
              'file' => '/app/phalcon/Registry.zep',
              'line' => 264,
              'char' => 5,
            ),
          ),
          'docblock' => '**
     * Constructs the object
     *
     * @link https://php.net/manual/en/serializable.unserialize.php
     *',
          'return-type' => 
          array (
            'type' => 'return-type',
            'void' => 1,
            'file' => '/app/phalcon/Registry.zep',
            'line' => 262,
            'char' => 5,
          ),
          'file' => '/app/phalcon/Registry.zep',
          'line' => 261,
          'last-line' => 265,
          'char' => 25,
        ),
      ),
      'file' => '/app/phalcon/Registry.zep',
      'line' => 66,
      'char' => 11,
    ),
    'file' => '/app/phalcon/Registry.zep',
    'line' => 66,
    'char' => 11,
  ),
);