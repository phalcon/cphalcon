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
    'file' => '/app/phalcon/Mvc/Model/MetaData.zep',
    'line' => 11,
    'char' => 9,
  ),
  1 => 
  array (
    'type' => 'namespace',
    'name' => 'Phalcon\\Mvc\\Model',
    'file' => '/app/phalcon/Mvc/Model/MetaData.zep',
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
        'name' => 'Phalcon\\DiInterface',
        'file' => '/app/phalcon/Mvc/Model/MetaData.zep',
        'line' => 13,
        'char' => 24,
      ),
    ),
    'file' => '/app/phalcon/Mvc/Model/MetaData.zep',
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
        'name' => 'Phalcon\\Mvc\\ModelInterface',
        'file' => '/app/phalcon/Mvc/Model/MetaData.zep',
        'line' => 14,
        'char' => 31,
      ),
    ),
    'file' => '/app/phalcon/Mvc/Model/MetaData.zep',
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
        'name' => 'Phalcon\\Mvc\\Model\\Exception',
        'file' => '/app/phalcon/Mvc/Model/MetaData.zep',
        'line' => 15,
        'char' => 32,
      ),
    ),
    'file' => '/app/phalcon/Mvc/Model/MetaData.zep',
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
        'name' => 'Phalcon\\Di\\InjectionAwareInterface',
        'file' => '/app/phalcon/Mvc/Model/MetaData.zep',
        'line' => 16,
        'char' => 39,
      ),
    ),
    'file' => '/app/phalcon/Mvc/Model/MetaData.zep',
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
        'name' => 'Phalcon\\Mvc\\Model\\MetaData\\Strategy\\Introspection',
        'file' => '/app/phalcon/Mvc/Model/MetaData.zep',
        'line' => 17,
        'char' => 54,
      ),
    ),
    'file' => '/app/phalcon/Mvc/Model/MetaData.zep',
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
        'name' => 'Phalcon\\Mvc\\Model\\MetaData\\StrategyInterface',
        'file' => '/app/phalcon/Mvc/Model/MetaData.zep',
        'line' => 18,
        'char' => 49,
      ),
    ),
    'file' => '/app/phalcon/Mvc/Model/MetaData.zep',
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
        'name' => 'Phalcon\\Cache\\Adapter\\AdapterInterface',
        'alias' => 'CacheAdapterInterface',
        'file' => '/app/phalcon/Mvc/Model/MetaData.zep',
        'line' => 19,
        'char' => 68,
      ),
    ),
    'file' => '/app/phalcon/Mvc/Model/MetaData.zep',
    'line' => 40,
    'char' => 2,
  ),
  9 => 
  array (
    'type' => 'comment',
    'value' => '**
 * Phalcon\\Mvc\\Model\\MetaData
 *
 * Because Phalcon\\Mvc\\Model requires meta-data like field names, data types,
 * primary keys, etc. This component collect them and store for further
 * querying by Phalcon\\Mvc\\Model. Phalcon\\Mvc\\Model\\MetaData can also use
 * adapters to store temporarily or permanently the meta-data.
 *
 * A standard Phalcon\\Mvc\\Model\\MetaData can be used to query model attributes:
 *
 * ```php
 * $metaData = new \\Phalcon\\Mvc\\Model\\MetaData\\Memory();
 *
 * $attributes = $metaData->getAttributes(
 *     new Robots()
 * );
 *
 * print_r($attributes);
 * ```
 *',
    'file' => '/app/phalcon/Mvc/Model/MetaData.zep',
    'line' => 41,
    'char' => 8,
  ),
  10 => 
  array (
    'type' => 'class',
    'name' => 'MetaData',
    'abstract' => 1,
    'final' => 0,
    'implements' => 
    array (
      0 => 
      array (
        'type' => 'variable',
        'value' => 'InjectionAwareInterface',
        'file' => '/app/phalcon/Mvc/Model/MetaData.zep',
        'line' => 41,
        'char' => 59,
      ),
      1 => 
      array (
        'type' => 'variable',
        'value' => 'MetaDataInterface',
        'file' => '/app/phalcon/Mvc/Model/MetaData.zep',
        'line' => 42,
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
          'name' => 'adapter',
          'docblock' => '**
     * @var CacheAdapterInterface
     *',
          'file' => '/app/phalcon/Mvc/Model/MetaData.zep',
          'line' => 65,
          'char' => 13,
        ),
        1 => 
        array (
          'visibility' => 
          array (
            0 => 'protected',
          ),
          'type' => 'property',
          'name' => 'columnMap',
          'file' => '/app/phalcon/Mvc/Model/MetaData.zep',
          'line' => 67,
          'char' => 13,
        ),
        2 => 
        array (
          'visibility' => 
          array (
            0 => 'protected',
          ),
          'type' => 'property',
          'name' => 'container',
          'file' => '/app/phalcon/Mvc/Model/MetaData.zep',
          'line' => 69,
          'char' => 13,
        ),
        3 => 
        array (
          'visibility' => 
          array (
            0 => 'protected',
          ),
          'type' => 'property',
          'name' => 'metaData',
          'default' => 
          array (
            'type' => 'empty-array',
            'file' => '/app/phalcon/Mvc/Model/MetaData.zep',
            'line' => 69,
            'char' => 28,
          ),
          'file' => '/app/phalcon/Mvc/Model/MetaData.zep',
          'line' => 71,
          'char' => 13,
        ),
        4 => 
        array (
          'visibility' => 
          array (
            0 => 'protected',
          ),
          'type' => 'property',
          'name' => 'strategy',
          'file' => '/app/phalcon/Mvc/Model/MetaData.zep',
          'line' => 83,
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
          'name' => 'getAttributes',
          'parameters' => 
          array (
            0 => 
            array (
              'type' => 'parameter',
              'name' => 'model',
              'const' => 0,
              'data-type' => 'variable',
              'mandatory' => 0,
              'cast' => 
              array (
                'type' => 'variable',
                'value' => 'ModelInterface',
                'file' => '/app/phalcon/Mvc/Model/MetaData.zep',
                'line' => 84,
                'char' => 56,
              ),
              'reference' => 0,
              'file' => '/app/phalcon/Mvc/Model/MetaData.zep',
              'line' => 84,
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
                  'variable' => 'data',
                  'file' => '/app/phalcon/Mvc/Model/MetaData.zep',
                  'line' => 86,
                  'char' => 17,
                ),
              ),
              'file' => '/app/phalcon/Mvc/Model/MetaData.zep',
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
                  'variable' => 'data',
                  'expr' => 
                  array (
                    'type' => 'mcall',
                    'variable' => 
                    array (
                      'type' => 'variable',
                      'value' => 'this',
                      'file' => '/app/phalcon/Mvc/Model/MetaData.zep',
                      'line' => 88,
                      'char' => 25,
                    ),
                    'name' => 'readMetaDataIndex',
                    'call-type' => 1,
                    'parameters' => 
                    array (
                      0 => 
                      array (
                        'parameter' => 
                        array (
                          'type' => 'variable',
                          'value' => 'model',
                          'file' => '/app/phalcon/Mvc/Model/MetaData.zep',
                          'line' => 88,
                          'char' => 49,
                        ),
                        'file' => '/app/phalcon/Mvc/Model/MetaData.zep',
                        'line' => 88,
                        'char' => 49,
                      ),
                      1 => 
                      array (
                        'parameter' => 
                        array (
                          'type' => 'static-constant-access',
                          'left' => 
                          array (
                            'type' => 'variable',
                            'value' => 'self',
                            'file' => '/app/phalcon/Mvc/Model/MetaData.zep',
                            'line' => 88,
                            'char' => 74,
                          ),
                          'right' => 
                          array (
                            'type' => 'variable',
                            'value' => 'MODELS_ATTRIBUTES',
                            'file' => '/app/phalcon/Mvc/Model/MetaData.zep',
                            'line' => 88,
                            'char' => 74,
                          ),
                          'file' => '/app/phalcon/Mvc/Model/MetaData.zep',
                          'line' => 88,
                          'char' => 74,
                        ),
                        'file' => '/app/phalcon/Mvc/Model/MetaData.zep',
                        'line' => 88,
                        'char' => 74,
                      ),
                    ),
                    'file' => '/app/phalcon/Mvc/Model/MetaData.zep',
                    'line' => 88,
                    'char' => 75,
                  ),
                  'file' => '/app/phalcon/Mvc/Model/MetaData.zep',
                  'line' => 88,
                  'char' => 75,
                ),
              ),
              'file' => '/app/phalcon/Mvc/Model/MetaData.zep',
              'line' => 90,
              'char' => 10,
            ),
            2 => 
            array (
              'type' => 'if',
              'expr' => 
              array (
                'type' => 'unlikely',
                'left' => 
                array (
                  'type' => 'not-equals',
                  'left' => 
                  array (
                    'type' => 'typeof',
                    'left' => 
                    array (
                      'type' => 'variable',
                      'value' => 'data',
                      'file' => '/app/phalcon/Mvc/Model/MetaData.zep',
                      'line' => 90,
                      'char' => 34,
                    ),
                    'file' => '/app/phalcon/Mvc/Model/MetaData.zep',
                    'line' => 90,
                    'char' => 34,
                  ),
                  'right' => 
                  array (
                    'type' => 'string',
                    'value' => 'array',
                    'file' => '/app/phalcon/Mvc/Model/MetaData.zep',
                    'line' => 90,
                    'char' => 42,
                  ),
                  'file' => '/app/phalcon/Mvc/Model/MetaData.zep',
                  'line' => 90,
                  'char' => 42,
                ),
                'file' => '/app/phalcon/Mvc/Model/MetaData.zep',
                'line' => 90,
                'char' => 42,
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
                          'value' => 'The meta-data is invalid or is corrupt',
                          'file' => '/app/phalcon/Mvc/Model/MetaData.zep',
                          'line' => 91,
                          'char' => 71,
                        ),
                        'file' => '/app/phalcon/Mvc/Model/MetaData.zep',
                        'line' => 91,
                        'char' => 71,
                      ),
                    ),
                    'file' => '/app/phalcon/Mvc/Model/MetaData.zep',
                    'line' => 91,
                    'char' => 72,
                  ),
                  'file' => '/app/phalcon/Mvc/Model/MetaData.zep',
                  'line' => 92,
                  'char' => 9,
                ),
              ),
              'file' => '/app/phalcon/Mvc/Model/MetaData.zep',
              'line' => 94,
              'char' => 14,
            ),
            3 => 
            array (
              'type' => 'return',
              'expr' => 
              array (
                'type' => 'variable',
                'value' => 'data',
                'file' => '/app/phalcon/Mvc/Model/MetaData.zep',
                'line' => 94,
                'char' => 20,
              ),
              'file' => '/app/phalcon/Mvc/Model/MetaData.zep',
              'line' => 95,
              'char' => 5,
            ),
          ),
          'docblock' => '**
     * Returns table attributes names (fields)
     *
     *```php
     * print_r(
     *     $metaData->getAttributes(
     *         new Robots()
     *     )
     * );
     *```
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
                'file' => '/app/phalcon/Mvc/Model/MetaData.zep',
                'line' => 85,
                'char' => 5,
              ),
            ),
            'void' => 0,
            'file' => '/app/phalcon/Mvc/Model/MetaData.zep',
            'line' => 85,
            'char' => 5,
          ),
          'file' => '/app/phalcon/Mvc/Model/MetaData.zep',
          'line' => 84,
          'last-line' => 107,
          'char' => 19,
        ),
        1 => 
        array (
          'visibility' => 
          array (
            0 => 'public',
          ),
          'type' => 'method',
          'name' => 'getAutomaticCreateAttributes',
          'parameters' => 
          array (
            0 => 
            array (
              'type' => 'parameter',
              'name' => 'model',
              'const' => 0,
              'data-type' => 'variable',
              'mandatory' => 0,
              'cast' => 
              array (
                'type' => 'variable',
                'value' => 'ModelInterface',
                'file' => '/app/phalcon/Mvc/Model/MetaData.zep',
                'line' => 108,
                'char' => 71,
              ),
              'reference' => 0,
              'file' => '/app/phalcon/Mvc/Model/MetaData.zep',
              'line' => 108,
              'char' => 72,
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
                  'file' => '/app/phalcon/Mvc/Model/MetaData.zep',
                  'line' => 110,
                  'char' => 17,
                ),
              ),
              'file' => '/app/phalcon/Mvc/Model/MetaData.zep',
              'line' => 112,
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
                  'variable' => 'data',
                  'expr' => 
                  array (
                    'type' => 'mcall',
                    'variable' => 
                    array (
                      'type' => 'variable',
                      'value' => 'this',
                      'file' => '/app/phalcon/Mvc/Model/MetaData.zep',
                      'line' => 112,
                      'char' => 25,
                    ),
                    'name' => 'readMetaDataIndex',
                    'call-type' => 1,
                    'parameters' => 
                    array (
                      0 => 
                      array (
                        'parameter' => 
                        array (
                          'type' => 'variable',
                          'value' => 'model',
                          'file' => '/app/phalcon/Mvc/Model/MetaData.zep',
                          'line' => 113,
                          'char' => 18,
                        ),
                        'file' => '/app/phalcon/Mvc/Model/MetaData.zep',
                        'line' => 113,
                        'char' => 18,
                      ),
                      1 => 
                      array (
                        'parameter' => 
                        array (
                          'type' => 'static-constant-access',
                          'left' => 
                          array (
                            'type' => 'variable',
                            'value' => 'self',
                            'file' => '/app/phalcon/Mvc/Model/MetaData.zep',
                            'line' => 115,
                            'char' => 9,
                          ),
                          'right' => 
                          array (
                            'type' => 'variable',
                            'value' => 'MODELS_AUTOMATIC_DEFAULT_INSERT',
                            'file' => '/app/phalcon/Mvc/Model/MetaData.zep',
                            'line' => 115,
                            'char' => 9,
                          ),
                          'file' => '/app/phalcon/Mvc/Model/MetaData.zep',
                          'line' => 115,
                          'char' => 9,
                        ),
                        'file' => '/app/phalcon/Mvc/Model/MetaData.zep',
                        'line' => 115,
                        'char' => 9,
                      ),
                    ),
                    'file' => '/app/phalcon/Mvc/Model/MetaData.zep',
                    'line' => 115,
                    'char' => 10,
                  ),
                  'file' => '/app/phalcon/Mvc/Model/MetaData.zep',
                  'line' => 115,
                  'char' => 10,
                ),
              ),
              'file' => '/app/phalcon/Mvc/Model/MetaData.zep',
              'line' => 117,
              'char' => 10,
            ),
            2 => 
            array (
              'type' => 'if',
              'expr' => 
              array (
                'type' => 'unlikely',
                'left' => 
                array (
                  'type' => 'not-equals',
                  'left' => 
                  array (
                    'type' => 'typeof',
                    'left' => 
                    array (
                      'type' => 'variable',
                      'value' => 'data',
                      'file' => '/app/phalcon/Mvc/Model/MetaData.zep',
                      'line' => 117,
                      'char' => 34,
                    ),
                    'file' => '/app/phalcon/Mvc/Model/MetaData.zep',
                    'line' => 117,
                    'char' => 34,
                  ),
                  'right' => 
                  array (
                    'type' => 'string',
                    'value' => 'array',
                    'file' => '/app/phalcon/Mvc/Model/MetaData.zep',
                    'line' => 117,
                    'char' => 42,
                  ),
                  'file' => '/app/phalcon/Mvc/Model/MetaData.zep',
                  'line' => 117,
                  'char' => 42,
                ),
                'file' => '/app/phalcon/Mvc/Model/MetaData.zep',
                'line' => 117,
                'char' => 42,
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
                          'value' => 'The meta-data is invalid or is corrupt',
                          'file' => '/app/phalcon/Mvc/Model/MetaData.zep',
                          'line' => 118,
                          'char' => 71,
                        ),
                        'file' => '/app/phalcon/Mvc/Model/MetaData.zep',
                        'line' => 118,
                        'char' => 71,
                      ),
                    ),
                    'file' => '/app/phalcon/Mvc/Model/MetaData.zep',
                    'line' => 118,
                    'char' => 72,
                  ),
                  'file' => '/app/phalcon/Mvc/Model/MetaData.zep',
                  'line' => 119,
                  'char' => 9,
                ),
              ),
              'file' => '/app/phalcon/Mvc/Model/MetaData.zep',
              'line' => 121,
              'char' => 14,
            ),
            3 => 
            array (
              'type' => 'return',
              'expr' => 
              array (
                'type' => 'variable',
                'value' => 'data',
                'file' => '/app/phalcon/Mvc/Model/MetaData.zep',
                'line' => 121,
                'char' => 20,
              ),
              'file' => '/app/phalcon/Mvc/Model/MetaData.zep',
              'line' => 122,
              'char' => 5,
            ),
          ),
          'docblock' => '**
     * Returns attributes that must be ignored from the INSERT SQL generation
     *
     *```php
     * print_r(
     *     $metaData->getAutomaticCreateAttributes(
     *         new Robots()
     *     )
     * );
     *```
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
                'file' => '/app/phalcon/Mvc/Model/MetaData.zep',
                'line' => 109,
                'char' => 5,
              ),
            ),
            'void' => 0,
            'file' => '/app/phalcon/Mvc/Model/MetaData.zep',
            'line' => 109,
            'char' => 5,
          ),
          'file' => '/app/phalcon/Mvc/Model/MetaData.zep',
          'line' => 108,
          'last-line' => 134,
          'char' => 19,
        ),
        2 => 
        array (
          'visibility' => 
          array (
            0 => 'public',
          ),
          'type' => 'method',
          'name' => 'getAutomaticUpdateAttributes',
          'parameters' => 
          array (
            0 => 
            array (
              'type' => 'parameter',
              'name' => 'model',
              'const' => 0,
              'data-type' => 'variable',
              'mandatory' => 0,
              'cast' => 
              array (
                'type' => 'variable',
                'value' => 'ModelInterface',
                'file' => '/app/phalcon/Mvc/Model/MetaData.zep',
                'line' => 135,
                'char' => 71,
              ),
              'reference' => 0,
              'file' => '/app/phalcon/Mvc/Model/MetaData.zep',
              'line' => 135,
              'char' => 72,
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
                  'file' => '/app/phalcon/Mvc/Model/MetaData.zep',
                  'line' => 137,
                  'char' => 17,
                ),
              ),
              'file' => '/app/phalcon/Mvc/Model/MetaData.zep',
              'line' => 139,
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
                  'variable' => 'data',
                  'expr' => 
                  array (
                    'type' => 'mcall',
                    'variable' => 
                    array (
                      'type' => 'variable',
                      'value' => 'this',
                      'file' => '/app/phalcon/Mvc/Model/MetaData.zep',
                      'line' => 139,
                      'char' => 25,
                    ),
                    'name' => 'readMetaDataIndex',
                    'call-type' => 1,
                    'parameters' => 
                    array (
                      0 => 
                      array (
                        'parameter' => 
                        array (
                          'type' => 'variable',
                          'value' => 'model',
                          'file' => '/app/phalcon/Mvc/Model/MetaData.zep',
                          'line' => 140,
                          'char' => 18,
                        ),
                        'file' => '/app/phalcon/Mvc/Model/MetaData.zep',
                        'line' => 140,
                        'char' => 18,
                      ),
                      1 => 
                      array (
                        'parameter' => 
                        array (
                          'type' => 'static-constant-access',
                          'left' => 
                          array (
                            'type' => 'variable',
                            'value' => 'self',
                            'file' => '/app/phalcon/Mvc/Model/MetaData.zep',
                            'line' => 142,
                            'char' => 9,
                          ),
                          'right' => 
                          array (
                            'type' => 'variable',
                            'value' => 'MODELS_AUTOMATIC_DEFAULT_UPDATE',
                            'file' => '/app/phalcon/Mvc/Model/MetaData.zep',
                            'line' => 142,
                            'char' => 9,
                          ),
                          'file' => '/app/phalcon/Mvc/Model/MetaData.zep',
                          'line' => 142,
                          'char' => 9,
                        ),
                        'file' => '/app/phalcon/Mvc/Model/MetaData.zep',
                        'line' => 142,
                        'char' => 9,
                      ),
                    ),
                    'file' => '/app/phalcon/Mvc/Model/MetaData.zep',
                    'line' => 142,
                    'char' => 10,
                  ),
                  'file' => '/app/phalcon/Mvc/Model/MetaData.zep',
                  'line' => 142,
                  'char' => 10,
                ),
              ),
              'file' => '/app/phalcon/Mvc/Model/MetaData.zep',
              'line' => 144,
              'char' => 10,
            ),
            2 => 
            array (
              'type' => 'if',
              'expr' => 
              array (
                'type' => 'unlikely',
                'left' => 
                array (
                  'type' => 'not-equals',
                  'left' => 
                  array (
                    'type' => 'typeof',
                    'left' => 
                    array (
                      'type' => 'variable',
                      'value' => 'data',
                      'file' => '/app/phalcon/Mvc/Model/MetaData.zep',
                      'line' => 144,
                      'char' => 34,
                    ),
                    'file' => '/app/phalcon/Mvc/Model/MetaData.zep',
                    'line' => 144,
                    'char' => 34,
                  ),
                  'right' => 
                  array (
                    'type' => 'string',
                    'value' => 'array',
                    'file' => '/app/phalcon/Mvc/Model/MetaData.zep',
                    'line' => 144,
                    'char' => 42,
                  ),
                  'file' => '/app/phalcon/Mvc/Model/MetaData.zep',
                  'line' => 144,
                  'char' => 42,
                ),
                'file' => '/app/phalcon/Mvc/Model/MetaData.zep',
                'line' => 144,
                'char' => 42,
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
                          'value' => 'The meta-data is invalid or is corrupt',
                          'file' => '/app/phalcon/Mvc/Model/MetaData.zep',
                          'line' => 145,
                          'char' => 71,
                        ),
                        'file' => '/app/phalcon/Mvc/Model/MetaData.zep',
                        'line' => 145,
                        'char' => 71,
                      ),
                    ),
                    'file' => '/app/phalcon/Mvc/Model/MetaData.zep',
                    'line' => 145,
                    'char' => 72,
                  ),
                  'file' => '/app/phalcon/Mvc/Model/MetaData.zep',
                  'line' => 146,
                  'char' => 9,
                ),
              ),
              'file' => '/app/phalcon/Mvc/Model/MetaData.zep',
              'line' => 148,
              'char' => 14,
            ),
            3 => 
            array (
              'type' => 'return',
              'expr' => 
              array (
                'type' => 'variable',
                'value' => 'data',
                'file' => '/app/phalcon/Mvc/Model/MetaData.zep',
                'line' => 148,
                'char' => 20,
              ),
              'file' => '/app/phalcon/Mvc/Model/MetaData.zep',
              'line' => 149,
              'char' => 5,
            ),
          ),
          'docblock' => '**
     * Returns attributes that must be ignored from the UPDATE SQL generation
     *
     *```php
     * print_r(
     *     $metaData->getAutomaticUpdateAttributes(
     *         new Robots()
     *     )
     * );
     *```
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
                'file' => '/app/phalcon/Mvc/Model/MetaData.zep',
                'line' => 136,
                'char' => 5,
              ),
            ),
            'void' => 0,
            'file' => '/app/phalcon/Mvc/Model/MetaData.zep',
            'line' => 136,
            'char' => 5,
          ),
          'file' => '/app/phalcon/Mvc/Model/MetaData.zep',
          'line' => 135,
          'last-line' => 161,
          'char' => 19,
        ),
        3 => 
        array (
          'visibility' => 
          array (
            0 => 'public',
          ),
          'type' => 'method',
          'name' => 'getBindTypes',
          'parameters' => 
          array (
            0 => 
            array (
              'type' => 'parameter',
              'name' => 'model',
              'const' => 0,
              'data-type' => 'variable',
              'mandatory' => 0,
              'cast' => 
              array (
                'type' => 'variable',
                'value' => 'ModelInterface',
                'file' => '/app/phalcon/Mvc/Model/MetaData.zep',
                'line' => 162,
                'char' => 55,
              ),
              'reference' => 0,
              'file' => '/app/phalcon/Mvc/Model/MetaData.zep',
              'line' => 162,
              'char' => 56,
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
                  'file' => '/app/phalcon/Mvc/Model/MetaData.zep',
                  'line' => 164,
                  'char' => 17,
                ),
              ),
              'file' => '/app/phalcon/Mvc/Model/MetaData.zep',
              'line' => 166,
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
                  'variable' => 'data',
                  'expr' => 
                  array (
                    'type' => 'mcall',
                    'variable' => 
                    array (
                      'type' => 'variable',
                      'value' => 'this',
                      'file' => '/app/phalcon/Mvc/Model/MetaData.zep',
                      'line' => 166,
                      'char' => 25,
                    ),
                    'name' => 'readMetaDataIndex',
                    'call-type' => 1,
                    'parameters' => 
                    array (
                      0 => 
                      array (
                        'parameter' => 
                        array (
                          'type' => 'variable',
                          'value' => 'model',
                          'file' => '/app/phalcon/Mvc/Model/MetaData.zep',
                          'line' => 167,
                          'char' => 18,
                        ),
                        'file' => '/app/phalcon/Mvc/Model/MetaData.zep',
                        'line' => 167,
                        'char' => 18,
                      ),
                      1 => 
                      array (
                        'parameter' => 
                        array (
                          'type' => 'static-constant-access',
                          'left' => 
                          array (
                            'type' => 'variable',
                            'value' => 'self',
                            'file' => '/app/phalcon/Mvc/Model/MetaData.zep',
                            'line' => 169,
                            'char' => 9,
                          ),
                          'right' => 
                          array (
                            'type' => 'variable',
                            'value' => 'MODELS_DATA_TYPES_BIND',
                            'file' => '/app/phalcon/Mvc/Model/MetaData.zep',
                            'line' => 169,
                            'char' => 9,
                          ),
                          'file' => '/app/phalcon/Mvc/Model/MetaData.zep',
                          'line' => 169,
                          'char' => 9,
                        ),
                        'file' => '/app/phalcon/Mvc/Model/MetaData.zep',
                        'line' => 169,
                        'char' => 9,
                      ),
                    ),
                    'file' => '/app/phalcon/Mvc/Model/MetaData.zep',
                    'line' => 169,
                    'char' => 10,
                  ),
                  'file' => '/app/phalcon/Mvc/Model/MetaData.zep',
                  'line' => 169,
                  'char' => 10,
                ),
              ),
              'file' => '/app/phalcon/Mvc/Model/MetaData.zep',
              'line' => 171,
              'char' => 10,
            ),
            2 => 
            array (
              'type' => 'if',
              'expr' => 
              array (
                'type' => 'unlikely',
                'left' => 
                array (
                  'type' => 'not-equals',
                  'left' => 
                  array (
                    'type' => 'typeof',
                    'left' => 
                    array (
                      'type' => 'variable',
                      'value' => 'data',
                      'file' => '/app/phalcon/Mvc/Model/MetaData.zep',
                      'line' => 171,
                      'char' => 34,
                    ),
                    'file' => '/app/phalcon/Mvc/Model/MetaData.zep',
                    'line' => 171,
                    'char' => 34,
                  ),
                  'right' => 
                  array (
                    'type' => 'string',
                    'value' => 'array',
                    'file' => '/app/phalcon/Mvc/Model/MetaData.zep',
                    'line' => 171,
                    'char' => 42,
                  ),
                  'file' => '/app/phalcon/Mvc/Model/MetaData.zep',
                  'line' => 171,
                  'char' => 42,
                ),
                'file' => '/app/phalcon/Mvc/Model/MetaData.zep',
                'line' => 171,
                'char' => 42,
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
                          'value' => 'The meta-data is invalid or is corrupt',
                          'file' => '/app/phalcon/Mvc/Model/MetaData.zep',
                          'line' => 172,
                          'char' => 71,
                        ),
                        'file' => '/app/phalcon/Mvc/Model/MetaData.zep',
                        'line' => 172,
                        'char' => 71,
                      ),
                    ),
                    'file' => '/app/phalcon/Mvc/Model/MetaData.zep',
                    'line' => 172,
                    'char' => 72,
                  ),
                  'file' => '/app/phalcon/Mvc/Model/MetaData.zep',
                  'line' => 173,
                  'char' => 9,
                ),
              ),
              'file' => '/app/phalcon/Mvc/Model/MetaData.zep',
              'line' => 175,
              'char' => 14,
            ),
            3 => 
            array (
              'type' => 'return',
              'expr' => 
              array (
                'type' => 'variable',
                'value' => 'data',
                'file' => '/app/phalcon/Mvc/Model/MetaData.zep',
                'line' => 175,
                'char' => 20,
              ),
              'file' => '/app/phalcon/Mvc/Model/MetaData.zep',
              'line' => 176,
              'char' => 5,
            ),
          ),
          'docblock' => '**
     * Returns attributes and their bind data types
     *
     *```php
     * print_r(
     *     $metaData->getBindTypes(
     *         new Robots()
     *     )
     * );
     *```
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
                'file' => '/app/phalcon/Mvc/Model/MetaData.zep',
                'line' => 163,
                'char' => 5,
              ),
            ),
            'void' => 0,
            'file' => '/app/phalcon/Mvc/Model/MetaData.zep',
            'line' => 163,
            'char' => 5,
          ),
          'file' => '/app/phalcon/Mvc/Model/MetaData.zep',
          'line' => 162,
          'last-line' => 188,
          'char' => 19,
        ),
        4 => 
        array (
          'visibility' => 
          array (
            0 => 'public',
          ),
          'type' => 'method',
          'name' => 'getColumnMap',
          'parameters' => 
          array (
            0 => 
            array (
              'type' => 'parameter',
              'name' => 'model',
              'const' => 0,
              'data-type' => 'variable',
              'mandatory' => 0,
              'cast' => 
              array (
                'type' => 'variable',
                'value' => 'ModelInterface',
                'file' => '/app/phalcon/Mvc/Model/MetaData.zep',
                'line' => 189,
                'char' => 55,
              ),
              'reference' => 0,
              'file' => '/app/phalcon/Mvc/Model/MetaData.zep',
              'line' => 189,
              'char' => 56,
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
                  'file' => '/app/phalcon/Mvc/Model/MetaData.zep',
                  'line' => 191,
                  'char' => 17,
                ),
              ),
              'file' => '/app/phalcon/Mvc/Model/MetaData.zep',
              'line' => 193,
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
                  'variable' => 'data',
                  'expr' => 
                  array (
                    'type' => 'mcall',
                    'variable' => 
                    array (
                      'type' => 'variable',
                      'value' => 'this',
                      'file' => '/app/phalcon/Mvc/Model/MetaData.zep',
                      'line' => 193,
                      'char' => 25,
                    ),
                    'name' => 'readColumnMapIndex',
                    'call-type' => 1,
                    'parameters' => 
                    array (
                      0 => 
                      array (
                        'parameter' => 
                        array (
                          'type' => 'variable',
                          'value' => 'model',
                          'file' => '/app/phalcon/Mvc/Model/MetaData.zep',
                          'line' => 193,
                          'char' => 50,
                        ),
                        'file' => '/app/phalcon/Mvc/Model/MetaData.zep',
                        'line' => 193,
                        'char' => 50,
                      ),
                      1 => 
                      array (
                        'parameter' => 
                        array (
                          'type' => 'static-constant-access',
                          'left' => 
                          array (
                            'type' => 'variable',
                            'value' => 'self',
                            'file' => '/app/phalcon/Mvc/Model/MetaData.zep',
                            'line' => 193,
                            'char' => 75,
                          ),
                          'right' => 
                          array (
                            'type' => 'variable',
                            'value' => 'MODELS_COLUMN_MAP',
                            'file' => '/app/phalcon/Mvc/Model/MetaData.zep',
                            'line' => 193,
                            'char' => 75,
                          ),
                          'file' => '/app/phalcon/Mvc/Model/MetaData.zep',
                          'line' => 193,
                          'char' => 75,
                        ),
                        'file' => '/app/phalcon/Mvc/Model/MetaData.zep',
                        'line' => 193,
                        'char' => 75,
                      ),
                    ),
                    'file' => '/app/phalcon/Mvc/Model/MetaData.zep',
                    'line' => 193,
                    'char' => 76,
                  ),
                  'file' => '/app/phalcon/Mvc/Model/MetaData.zep',
                  'line' => 193,
                  'char' => 76,
                ),
              ),
              'file' => '/app/phalcon/Mvc/Model/MetaData.zep',
              'line' => 195,
              'char' => 10,
            ),
            2 => 
            array (
              'type' => 'if',
              'expr' => 
              array (
                'type' => 'unlikely',
                'left' => 
                array (
                  'type' => 'list',
                  'left' => 
                  array (
                    'type' => 'and',
                    'left' => 
                    array (
                      'type' => 'not-identical',
                      'left' => 
                      array (
                        'type' => 'variable',
                        'value' => 'data',
                        'file' => '/app/phalcon/Mvc/Model/MetaData.zep',
                        'line' => 195,
                        'char' => 29,
                      ),
                      'right' => 
                      array (
                        'type' => 'null',
                        'file' => '/app/phalcon/Mvc/Model/MetaData.zep',
                        'line' => 195,
                        'char' => 37,
                      ),
                      'file' => '/app/phalcon/Mvc/Model/MetaData.zep',
                      'line' => 195,
                      'char' => 37,
                    ),
                    'right' => 
                    array (
                      'type' => 'not-equals',
                      'left' => 
                      array (
                        'type' => 'typeof',
                        'left' => 
                        array (
                          'type' => 'variable',
                          'value' => 'data',
                          'file' => '/app/phalcon/Mvc/Model/MetaData.zep',
                          'line' => 195,
                          'char' => 52,
                        ),
                        'file' => '/app/phalcon/Mvc/Model/MetaData.zep',
                        'line' => 195,
                        'char' => 52,
                      ),
                      'right' => 
                      array (
                        'type' => 'string',
                        'value' => 'array',
                        'file' => '/app/phalcon/Mvc/Model/MetaData.zep',
                        'line' => 195,
                        'char' => 59,
                      ),
                      'file' => '/app/phalcon/Mvc/Model/MetaData.zep',
                      'line' => 195,
                      'char' => 59,
                    ),
                    'file' => '/app/phalcon/Mvc/Model/MetaData.zep',
                    'line' => 195,
                    'char' => 59,
                  ),
                  'file' => '/app/phalcon/Mvc/Model/MetaData.zep',
                  'line' => 195,
                  'char' => 61,
                ),
                'file' => '/app/phalcon/Mvc/Model/MetaData.zep',
                'line' => 195,
                'char' => 61,
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
                          'value' => 'The meta-data is invalid or is corrupt',
                          'file' => '/app/phalcon/Mvc/Model/MetaData.zep',
                          'line' => 196,
                          'char' => 71,
                        ),
                        'file' => '/app/phalcon/Mvc/Model/MetaData.zep',
                        'line' => 196,
                        'char' => 71,
                      ),
                    ),
                    'file' => '/app/phalcon/Mvc/Model/MetaData.zep',
                    'line' => 196,
                    'char' => 72,
                  ),
                  'file' => '/app/phalcon/Mvc/Model/MetaData.zep',
                  'line' => 197,
                  'char' => 9,
                ),
              ),
              'file' => '/app/phalcon/Mvc/Model/MetaData.zep',
              'line' => 199,
              'char' => 14,
            ),
            3 => 
            array (
              'type' => 'return',
              'expr' => 
              array (
                'type' => 'variable',
                'value' => 'data',
                'file' => '/app/phalcon/Mvc/Model/MetaData.zep',
                'line' => 199,
                'char' => 20,
              ),
              'file' => '/app/phalcon/Mvc/Model/MetaData.zep',
              'line' => 200,
              'char' => 5,
            ),
          ),
          'docblock' => '**
     * Returns the column map if any
     *
     *```php
     * print_r(
     *     $metaData->getColumnMap(
     *         new Robots()
     *     )
     * );
     *```
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
                'file' => '/app/phalcon/Mvc/Model/MetaData.zep',
                'line' => 190,
                'char' => 5,
              ),
            ),
            'void' => 0,
            'file' => '/app/phalcon/Mvc/Model/MetaData.zep',
            'line' => 190,
            'char' => 5,
          ),
          'file' => '/app/phalcon/Mvc/Model/MetaData.zep',
          'line' => 189,
          'last-line' => 212,
          'char' => 19,
        ),
        5 => 
        array (
          'visibility' => 
          array (
            0 => 'public',
          ),
          'type' => 'method',
          'name' => 'getDefaultValues',
          'parameters' => 
          array (
            0 => 
            array (
              'type' => 'parameter',
              'name' => 'model',
              'const' => 0,
              'data-type' => 'variable',
              'mandatory' => 0,
              'cast' => 
              array (
                'type' => 'variable',
                'value' => 'ModelInterface',
                'file' => '/app/phalcon/Mvc/Model/MetaData.zep',
                'line' => 213,
                'char' => 59,
              ),
              'reference' => 0,
              'file' => '/app/phalcon/Mvc/Model/MetaData.zep',
              'line' => 213,
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
                  'variable' => 'data',
                  'file' => '/app/phalcon/Mvc/Model/MetaData.zep',
                  'line' => 215,
                  'char' => 17,
                ),
              ),
              'file' => '/app/phalcon/Mvc/Model/MetaData.zep',
              'line' => 217,
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
                  'variable' => 'data',
                  'expr' => 
                  array (
                    'type' => 'mcall',
                    'variable' => 
                    array (
                      'type' => 'variable',
                      'value' => 'this',
                      'file' => '/app/phalcon/Mvc/Model/MetaData.zep',
                      'line' => 217,
                      'char' => 25,
                    ),
                    'name' => 'readMetaDataIndex',
                    'call-type' => 1,
                    'parameters' => 
                    array (
                      0 => 
                      array (
                        'parameter' => 
                        array (
                          'type' => 'variable',
                          'value' => 'model',
                          'file' => '/app/phalcon/Mvc/Model/MetaData.zep',
                          'line' => 217,
                          'char' => 49,
                        ),
                        'file' => '/app/phalcon/Mvc/Model/MetaData.zep',
                        'line' => 217,
                        'char' => 49,
                      ),
                      1 => 
                      array (
                        'parameter' => 
                        array (
                          'type' => 'static-constant-access',
                          'left' => 
                          array (
                            'type' => 'variable',
                            'value' => 'self',
                            'file' => '/app/phalcon/Mvc/Model/MetaData.zep',
                            'line' => 217,
                            'char' => 78,
                          ),
                          'right' => 
                          array (
                            'type' => 'variable',
                            'value' => 'MODELS_DEFAULT_VALUES',
                            'file' => '/app/phalcon/Mvc/Model/MetaData.zep',
                            'line' => 217,
                            'char' => 78,
                          ),
                          'file' => '/app/phalcon/Mvc/Model/MetaData.zep',
                          'line' => 217,
                          'char' => 78,
                        ),
                        'file' => '/app/phalcon/Mvc/Model/MetaData.zep',
                        'line' => 217,
                        'char' => 78,
                      ),
                    ),
                    'file' => '/app/phalcon/Mvc/Model/MetaData.zep',
                    'line' => 217,
                    'char' => 79,
                  ),
                  'file' => '/app/phalcon/Mvc/Model/MetaData.zep',
                  'line' => 217,
                  'char' => 79,
                ),
              ),
              'file' => '/app/phalcon/Mvc/Model/MetaData.zep',
              'line' => 219,
              'char' => 10,
            ),
            2 => 
            array (
              'type' => 'if',
              'expr' => 
              array (
                'type' => 'unlikely',
                'left' => 
                array (
                  'type' => 'not-equals',
                  'left' => 
                  array (
                    'type' => 'typeof',
                    'left' => 
                    array (
                      'type' => 'variable',
                      'value' => 'data',
                      'file' => '/app/phalcon/Mvc/Model/MetaData.zep',
                      'line' => 219,
                      'char' => 34,
                    ),
                    'file' => '/app/phalcon/Mvc/Model/MetaData.zep',
                    'line' => 219,
                    'char' => 34,
                  ),
                  'right' => 
                  array (
                    'type' => 'string',
                    'value' => 'array',
                    'file' => '/app/phalcon/Mvc/Model/MetaData.zep',
                    'line' => 219,
                    'char' => 42,
                  ),
                  'file' => '/app/phalcon/Mvc/Model/MetaData.zep',
                  'line' => 219,
                  'char' => 42,
                ),
                'file' => '/app/phalcon/Mvc/Model/MetaData.zep',
                'line' => 219,
                'char' => 42,
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
                          'value' => 'The meta-data is invalid or is corrupt',
                          'file' => '/app/phalcon/Mvc/Model/MetaData.zep',
                          'line' => 220,
                          'char' => 71,
                        ),
                        'file' => '/app/phalcon/Mvc/Model/MetaData.zep',
                        'line' => 220,
                        'char' => 71,
                      ),
                    ),
                    'file' => '/app/phalcon/Mvc/Model/MetaData.zep',
                    'line' => 220,
                    'char' => 72,
                  ),
                  'file' => '/app/phalcon/Mvc/Model/MetaData.zep',
                  'line' => 221,
                  'char' => 9,
                ),
              ),
              'file' => '/app/phalcon/Mvc/Model/MetaData.zep',
              'line' => 223,
              'char' => 14,
            ),
            3 => 
            array (
              'type' => 'return',
              'expr' => 
              array (
                'type' => 'variable',
                'value' => 'data',
                'file' => '/app/phalcon/Mvc/Model/MetaData.zep',
                'line' => 223,
                'char' => 20,
              ),
              'file' => '/app/phalcon/Mvc/Model/MetaData.zep',
              'line' => 224,
              'char' => 5,
            ),
          ),
          'docblock' => '**
     * Returns attributes (which have default values) and their default values
     *
     *```php
     * print_r(
     *     $metaData->getDefaultValues(
     *         new Robots()
     *     )
     * );
     *```
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
                'file' => '/app/phalcon/Mvc/Model/MetaData.zep',
                'line' => 214,
                'char' => 5,
              ),
            ),
            'void' => 0,
            'file' => '/app/phalcon/Mvc/Model/MetaData.zep',
            'line' => 214,
            'char' => 5,
          ),
          'file' => '/app/phalcon/Mvc/Model/MetaData.zep',
          'line' => 213,
          'last-line' => 236,
          'char' => 19,
        ),
        6 => 
        array (
          'visibility' => 
          array (
            0 => 'public',
          ),
          'type' => 'method',
          'name' => 'getDataTypes',
          'parameters' => 
          array (
            0 => 
            array (
              'type' => 'parameter',
              'name' => 'model',
              'const' => 0,
              'data-type' => 'variable',
              'mandatory' => 0,
              'cast' => 
              array (
                'type' => 'variable',
                'value' => 'ModelInterface',
                'file' => '/app/phalcon/Mvc/Model/MetaData.zep',
                'line' => 237,
                'char' => 55,
              ),
              'reference' => 0,
              'file' => '/app/phalcon/Mvc/Model/MetaData.zep',
              'line' => 237,
              'char' => 56,
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
                  'file' => '/app/phalcon/Mvc/Model/MetaData.zep',
                  'line' => 239,
                  'char' => 17,
                ),
              ),
              'file' => '/app/phalcon/Mvc/Model/MetaData.zep',
              'line' => 241,
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
                  'variable' => 'data',
                  'expr' => 
                  array (
                    'type' => 'mcall',
                    'variable' => 
                    array (
                      'type' => 'variable',
                      'value' => 'this',
                      'file' => '/app/phalcon/Mvc/Model/MetaData.zep',
                      'line' => 241,
                      'char' => 25,
                    ),
                    'name' => 'readMetaDataIndex',
                    'call-type' => 1,
                    'parameters' => 
                    array (
                      0 => 
                      array (
                        'parameter' => 
                        array (
                          'type' => 'variable',
                          'value' => 'model',
                          'file' => '/app/phalcon/Mvc/Model/MetaData.zep',
                          'line' => 241,
                          'char' => 49,
                        ),
                        'file' => '/app/phalcon/Mvc/Model/MetaData.zep',
                        'line' => 241,
                        'char' => 49,
                      ),
                      1 => 
                      array (
                        'parameter' => 
                        array (
                          'type' => 'static-constant-access',
                          'left' => 
                          array (
                            'type' => 'variable',
                            'value' => 'self',
                            'file' => '/app/phalcon/Mvc/Model/MetaData.zep',
                            'line' => 241,
                            'char' => 74,
                          ),
                          'right' => 
                          array (
                            'type' => 'variable',
                            'value' => 'MODELS_DATA_TYPES',
                            'file' => '/app/phalcon/Mvc/Model/MetaData.zep',
                            'line' => 241,
                            'char' => 74,
                          ),
                          'file' => '/app/phalcon/Mvc/Model/MetaData.zep',
                          'line' => 241,
                          'char' => 74,
                        ),
                        'file' => '/app/phalcon/Mvc/Model/MetaData.zep',
                        'line' => 241,
                        'char' => 74,
                      ),
                    ),
                    'file' => '/app/phalcon/Mvc/Model/MetaData.zep',
                    'line' => 241,
                    'char' => 75,
                  ),
                  'file' => '/app/phalcon/Mvc/Model/MetaData.zep',
                  'line' => 241,
                  'char' => 75,
                ),
              ),
              'file' => '/app/phalcon/Mvc/Model/MetaData.zep',
              'line' => 243,
              'char' => 10,
            ),
            2 => 
            array (
              'type' => 'if',
              'expr' => 
              array (
                'type' => 'unlikely',
                'left' => 
                array (
                  'type' => 'not-equals',
                  'left' => 
                  array (
                    'type' => 'typeof',
                    'left' => 
                    array (
                      'type' => 'variable',
                      'value' => 'data',
                      'file' => '/app/phalcon/Mvc/Model/MetaData.zep',
                      'line' => 243,
                      'char' => 34,
                    ),
                    'file' => '/app/phalcon/Mvc/Model/MetaData.zep',
                    'line' => 243,
                    'char' => 34,
                  ),
                  'right' => 
                  array (
                    'type' => 'string',
                    'value' => 'array',
                    'file' => '/app/phalcon/Mvc/Model/MetaData.zep',
                    'line' => 243,
                    'char' => 42,
                  ),
                  'file' => '/app/phalcon/Mvc/Model/MetaData.zep',
                  'line' => 243,
                  'char' => 42,
                ),
                'file' => '/app/phalcon/Mvc/Model/MetaData.zep',
                'line' => 243,
                'char' => 42,
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
                          'value' => 'The meta-data is invalid or is corrupt',
                          'file' => '/app/phalcon/Mvc/Model/MetaData.zep',
                          'line' => 244,
                          'char' => 71,
                        ),
                        'file' => '/app/phalcon/Mvc/Model/MetaData.zep',
                        'line' => 244,
                        'char' => 71,
                      ),
                    ),
                    'file' => '/app/phalcon/Mvc/Model/MetaData.zep',
                    'line' => 244,
                    'char' => 72,
                  ),
                  'file' => '/app/phalcon/Mvc/Model/MetaData.zep',
                  'line' => 245,
                  'char' => 9,
                ),
              ),
              'file' => '/app/phalcon/Mvc/Model/MetaData.zep',
              'line' => 247,
              'char' => 14,
            ),
            3 => 
            array (
              'type' => 'return',
              'expr' => 
              array (
                'type' => 'variable',
                'value' => 'data',
                'file' => '/app/phalcon/Mvc/Model/MetaData.zep',
                'line' => 247,
                'char' => 20,
              ),
              'file' => '/app/phalcon/Mvc/Model/MetaData.zep',
              'line' => 248,
              'char' => 5,
            ),
          ),
          'docblock' => '**
     * Returns attributes and their data types
     *
     *```php
     * print_r(
     *     $metaData->getDataTypes(
     *         new Robots()
     *     )
     * );
     *```
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
                'file' => '/app/phalcon/Mvc/Model/MetaData.zep',
                'line' => 238,
                'char' => 5,
              ),
            ),
            'void' => 0,
            'file' => '/app/phalcon/Mvc/Model/MetaData.zep',
            'line' => 238,
            'char' => 5,
          ),
          'file' => '/app/phalcon/Mvc/Model/MetaData.zep',
          'line' => 237,
          'last-line' => 260,
          'char' => 19,
        ),
        7 => 
        array (
          'visibility' => 
          array (
            0 => 'public',
          ),
          'type' => 'method',
          'name' => 'getDataTypesNumeric',
          'parameters' => 
          array (
            0 => 
            array (
              'type' => 'parameter',
              'name' => 'model',
              'const' => 0,
              'data-type' => 'variable',
              'mandatory' => 0,
              'cast' => 
              array (
                'type' => 'variable',
                'value' => 'ModelInterface',
                'file' => '/app/phalcon/Mvc/Model/MetaData.zep',
                'line' => 261,
                'char' => 62,
              ),
              'reference' => 0,
              'file' => '/app/phalcon/Mvc/Model/MetaData.zep',
              'line' => 261,
              'char' => 63,
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
                  'file' => '/app/phalcon/Mvc/Model/MetaData.zep',
                  'line' => 263,
                  'char' => 17,
                ),
              ),
              'file' => '/app/phalcon/Mvc/Model/MetaData.zep',
              'line' => 265,
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
                  'variable' => 'data',
                  'expr' => 
                  array (
                    'type' => 'mcall',
                    'variable' => 
                    array (
                      'type' => 'variable',
                      'value' => 'this',
                      'file' => '/app/phalcon/Mvc/Model/MetaData.zep',
                      'line' => 265,
                      'char' => 25,
                    ),
                    'name' => 'readMetaDataIndex',
                    'call-type' => 1,
                    'parameters' => 
                    array (
                      0 => 
                      array (
                        'parameter' => 
                        array (
                          'type' => 'variable',
                          'value' => 'model',
                          'file' => '/app/phalcon/Mvc/Model/MetaData.zep',
                          'line' => 266,
                          'char' => 18,
                        ),
                        'file' => '/app/phalcon/Mvc/Model/MetaData.zep',
                        'line' => 266,
                        'char' => 18,
                      ),
                      1 => 
                      array (
                        'parameter' => 
                        array (
                          'type' => 'static-constant-access',
                          'left' => 
                          array (
                            'type' => 'variable',
                            'value' => 'self',
                            'file' => '/app/phalcon/Mvc/Model/MetaData.zep',
                            'line' => 268,
                            'char' => 9,
                          ),
                          'right' => 
                          array (
                            'type' => 'variable',
                            'value' => 'MODELS_DATA_TYPES_NUMERIC',
                            'file' => '/app/phalcon/Mvc/Model/MetaData.zep',
                            'line' => 268,
                            'char' => 9,
                          ),
                          'file' => '/app/phalcon/Mvc/Model/MetaData.zep',
                          'line' => 268,
                          'char' => 9,
                        ),
                        'file' => '/app/phalcon/Mvc/Model/MetaData.zep',
                        'line' => 268,
                        'char' => 9,
                      ),
                    ),
                    'file' => '/app/phalcon/Mvc/Model/MetaData.zep',
                    'line' => 268,
                    'char' => 10,
                  ),
                  'file' => '/app/phalcon/Mvc/Model/MetaData.zep',
                  'line' => 268,
                  'char' => 10,
                ),
              ),
              'file' => '/app/phalcon/Mvc/Model/MetaData.zep',
              'line' => 270,
              'char' => 10,
            ),
            2 => 
            array (
              'type' => 'if',
              'expr' => 
              array (
                'type' => 'unlikely',
                'left' => 
                array (
                  'type' => 'not-equals',
                  'left' => 
                  array (
                    'type' => 'typeof',
                    'left' => 
                    array (
                      'type' => 'variable',
                      'value' => 'data',
                      'file' => '/app/phalcon/Mvc/Model/MetaData.zep',
                      'line' => 270,
                      'char' => 34,
                    ),
                    'file' => '/app/phalcon/Mvc/Model/MetaData.zep',
                    'line' => 270,
                    'char' => 34,
                  ),
                  'right' => 
                  array (
                    'type' => 'string',
                    'value' => 'array',
                    'file' => '/app/phalcon/Mvc/Model/MetaData.zep',
                    'line' => 270,
                    'char' => 42,
                  ),
                  'file' => '/app/phalcon/Mvc/Model/MetaData.zep',
                  'line' => 270,
                  'char' => 42,
                ),
                'file' => '/app/phalcon/Mvc/Model/MetaData.zep',
                'line' => 270,
                'char' => 42,
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
                          'value' => 'The meta-data is invalid or is corrupt',
                          'file' => '/app/phalcon/Mvc/Model/MetaData.zep',
                          'line' => 271,
                          'char' => 71,
                        ),
                        'file' => '/app/phalcon/Mvc/Model/MetaData.zep',
                        'line' => 271,
                        'char' => 71,
                      ),
                    ),
                    'file' => '/app/phalcon/Mvc/Model/MetaData.zep',
                    'line' => 271,
                    'char' => 72,
                  ),
                  'file' => '/app/phalcon/Mvc/Model/MetaData.zep',
                  'line' => 272,
                  'char' => 9,
                ),
              ),
              'file' => '/app/phalcon/Mvc/Model/MetaData.zep',
              'line' => 274,
              'char' => 14,
            ),
            3 => 
            array (
              'type' => 'return',
              'expr' => 
              array (
                'type' => 'variable',
                'value' => 'data',
                'file' => '/app/phalcon/Mvc/Model/MetaData.zep',
                'line' => 274,
                'char' => 20,
              ),
              'file' => '/app/phalcon/Mvc/Model/MetaData.zep',
              'line' => 275,
              'char' => 5,
            ),
          ),
          'docblock' => '**
     * Returns attributes which types are numerical
     *
     *```php
     * print_r(
     *     $metaData->getDataTypesNumeric(
     *         new Robots()
     *     )
     * );
     *```
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
                'file' => '/app/phalcon/Mvc/Model/MetaData.zep',
                'line' => 262,
                'char' => 5,
              ),
            ),
            'void' => 0,
            'file' => '/app/phalcon/Mvc/Model/MetaData.zep',
            'line' => 262,
            'char' => 5,
          ),
          'file' => '/app/phalcon/Mvc/Model/MetaData.zep',
          'line' => 261,
          'last-line' => 279,
          'char' => 19,
        ),
        8 => 
        array (
          'visibility' => 
          array (
            0 => 'public',
          ),
          'type' => 'method',
          'name' => 'getDI',
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
                  'file' => '/app/phalcon/Mvc/Model/MetaData.zep',
                  'line' => 282,
                  'char' => 21,
                ),
                'right' => 
                array (
                  'type' => 'variable',
                  'value' => 'container',
                  'file' => '/app/phalcon/Mvc/Model/MetaData.zep',
                  'line' => 282,
                  'char' => 31,
                ),
                'file' => '/app/phalcon/Mvc/Model/MetaData.zep',
                'line' => 282,
                'char' => 31,
              ),
              'file' => '/app/phalcon/Mvc/Model/MetaData.zep',
              'line' => 283,
              'char' => 5,
            ),
          ),
          'docblock' => '**
     * Returns the DependencyInjector container
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
                  'file' => '/app/phalcon/Mvc/Model/MetaData.zep',
                  'line' => 281,
                  'char' => 5,
                ),
                'collection' => 0,
                'file' => '/app/phalcon/Mvc/Model/MetaData.zep',
                'line' => 281,
                'char' => 5,
              ),
            ),
            'void' => 0,
            'file' => '/app/phalcon/Mvc/Model/MetaData.zep',
            'line' => 281,
            'char' => 5,
          ),
          'file' => '/app/phalcon/Mvc/Model/MetaData.zep',
          'line' => 280,
          'last-line' => 295,
          'char' => 19,
        ),
        9 => 
        array (
          'visibility' => 
          array (
            0 => 'public',
          ),
          'type' => 'method',
          'name' => 'getEmptyStringAttributes',
          'parameters' => 
          array (
            0 => 
            array (
              'type' => 'parameter',
              'name' => 'model',
              'const' => 0,
              'data-type' => 'variable',
              'mandatory' => 0,
              'cast' => 
              array (
                'type' => 'variable',
                'value' => 'ModelInterface',
                'file' => '/app/phalcon/Mvc/Model/MetaData.zep',
                'line' => 296,
                'char' => 67,
              ),
              'reference' => 0,
              'file' => '/app/phalcon/Mvc/Model/MetaData.zep',
              'line' => 296,
              'char' => 68,
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
                  'file' => '/app/phalcon/Mvc/Model/MetaData.zep',
                  'line' => 298,
                  'char' => 17,
                ),
              ),
              'file' => '/app/phalcon/Mvc/Model/MetaData.zep',
              'line' => 300,
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
                  'variable' => 'data',
                  'expr' => 
                  array (
                    'type' => 'mcall',
                    'variable' => 
                    array (
                      'type' => 'variable',
                      'value' => 'this',
                      'file' => '/app/phalcon/Mvc/Model/MetaData.zep',
                      'line' => 300,
                      'char' => 25,
                    ),
                    'name' => 'readMetaDataIndex',
                    'call-type' => 1,
                    'parameters' => 
                    array (
                      0 => 
                      array (
                        'parameter' => 
                        array (
                          'type' => 'variable',
                          'value' => 'model',
                          'file' => '/app/phalcon/Mvc/Model/MetaData.zep',
                          'line' => 301,
                          'char' => 18,
                        ),
                        'file' => '/app/phalcon/Mvc/Model/MetaData.zep',
                        'line' => 301,
                        'char' => 18,
                      ),
                      1 => 
                      array (
                        'parameter' => 
                        array (
                          'type' => 'static-constant-access',
                          'left' => 
                          array (
                            'type' => 'variable',
                            'value' => 'self',
                            'file' => '/app/phalcon/Mvc/Model/MetaData.zep',
                            'line' => 303,
                            'char' => 9,
                          ),
                          'right' => 
                          array (
                            'type' => 'variable',
                            'value' => 'MODELS_EMPTY_STRING_VALUES',
                            'file' => '/app/phalcon/Mvc/Model/MetaData.zep',
                            'line' => 303,
                            'char' => 9,
                          ),
                          'file' => '/app/phalcon/Mvc/Model/MetaData.zep',
                          'line' => 303,
                          'char' => 9,
                        ),
                        'file' => '/app/phalcon/Mvc/Model/MetaData.zep',
                        'line' => 303,
                        'char' => 9,
                      ),
                    ),
                    'file' => '/app/phalcon/Mvc/Model/MetaData.zep',
                    'line' => 303,
                    'char' => 10,
                  ),
                  'file' => '/app/phalcon/Mvc/Model/MetaData.zep',
                  'line' => 303,
                  'char' => 10,
                ),
              ),
              'file' => '/app/phalcon/Mvc/Model/MetaData.zep',
              'line' => 305,
              'char' => 10,
            ),
            2 => 
            array (
              'type' => 'if',
              'expr' => 
              array (
                'type' => 'unlikely',
                'left' => 
                array (
                  'type' => 'not-equals',
                  'left' => 
                  array (
                    'type' => 'typeof',
                    'left' => 
                    array (
                      'type' => 'variable',
                      'value' => 'data',
                      'file' => '/app/phalcon/Mvc/Model/MetaData.zep',
                      'line' => 305,
                      'char' => 34,
                    ),
                    'file' => '/app/phalcon/Mvc/Model/MetaData.zep',
                    'line' => 305,
                    'char' => 34,
                  ),
                  'right' => 
                  array (
                    'type' => 'string',
                    'value' => 'array',
                    'file' => '/app/phalcon/Mvc/Model/MetaData.zep',
                    'line' => 305,
                    'char' => 42,
                  ),
                  'file' => '/app/phalcon/Mvc/Model/MetaData.zep',
                  'line' => 305,
                  'char' => 42,
                ),
                'file' => '/app/phalcon/Mvc/Model/MetaData.zep',
                'line' => 305,
                'char' => 42,
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
                          'value' => 'The meta-data is invalid or is corrupt',
                          'file' => '/app/phalcon/Mvc/Model/MetaData.zep',
                          'line' => 306,
                          'char' => 71,
                        ),
                        'file' => '/app/phalcon/Mvc/Model/MetaData.zep',
                        'line' => 306,
                        'char' => 71,
                      ),
                    ),
                    'file' => '/app/phalcon/Mvc/Model/MetaData.zep',
                    'line' => 306,
                    'char' => 72,
                  ),
                  'file' => '/app/phalcon/Mvc/Model/MetaData.zep',
                  'line' => 307,
                  'char' => 9,
                ),
              ),
              'file' => '/app/phalcon/Mvc/Model/MetaData.zep',
              'line' => 309,
              'char' => 14,
            ),
            3 => 
            array (
              'type' => 'return',
              'expr' => 
              array (
                'type' => 'variable',
                'value' => 'data',
                'file' => '/app/phalcon/Mvc/Model/MetaData.zep',
                'line' => 309,
                'char' => 20,
              ),
              'file' => '/app/phalcon/Mvc/Model/MetaData.zep',
              'line' => 310,
              'char' => 5,
            ),
          ),
          'docblock' => '**
     * Returns attributes allow empty strings
     *
     *```php
     * print_r(
     *     $metaData->getEmptyStringAttributes(
     *         new Robots()
     *     )
     * );
     *```
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
                'file' => '/app/phalcon/Mvc/Model/MetaData.zep',
                'line' => 297,
                'char' => 5,
              ),
            ),
            'void' => 0,
            'file' => '/app/phalcon/Mvc/Model/MetaData.zep',
            'line' => 297,
            'char' => 5,
          ),
          'file' => '/app/phalcon/Mvc/Model/MetaData.zep',
          'line' => 296,
          'last-line' => 325,
          'char' => 19,
        ),
        10 => 
        array (
          'visibility' => 
          array (
            0 => 'public',
          ),
          'type' => 'method',
          'name' => 'getIdentityField',
          'parameters' => 
          array (
            0 => 
            array (
              'type' => 'parameter',
              'name' => 'model',
              'const' => 0,
              'data-type' => 'variable',
              'mandatory' => 0,
              'cast' => 
              array (
                'type' => 'variable',
                'value' => 'ModelInterface',
                'file' => '/app/phalcon/Mvc/Model/MetaData.zep',
                'line' => 326,
                'char' => 59,
              ),
              'reference' => 0,
              'file' => '/app/phalcon/Mvc/Model/MetaData.zep',
              'line' => 326,
              'char' => 60,
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
                  'file' => '/app/phalcon/Mvc/Model/MetaData.zep',
                  'line' => 328,
                  'char' => 21,
                ),
                'name' => 'readMetaDataIndex',
                'call-type' => 1,
                'parameters' => 
                array (
                  0 => 
                  array (
                    'parameter' => 
                    array (
                      'type' => 'variable',
                      'value' => 'model',
                      'file' => '/app/phalcon/Mvc/Model/MetaData.zep',
                      'line' => 328,
                      'char' => 45,
                    ),
                    'file' => '/app/phalcon/Mvc/Model/MetaData.zep',
                    'line' => 328,
                    'char' => 45,
                  ),
                  1 => 
                  array (
                    'parameter' => 
                    array (
                      'type' => 'static-constant-access',
                      'left' => 
                      array (
                        'type' => 'variable',
                        'value' => 'self',
                        'file' => '/app/phalcon/Mvc/Model/MetaData.zep',
                        'line' => 328,
                        'char' => 75,
                      ),
                      'right' => 
                      array (
                        'type' => 'variable',
                        'value' => 'MODELS_IDENTITY_COLUMN',
                        'file' => '/app/phalcon/Mvc/Model/MetaData.zep',
                        'line' => 328,
                        'char' => 75,
                      ),
                      'file' => '/app/phalcon/Mvc/Model/MetaData.zep',
                      'line' => 328,
                      'char' => 75,
                    ),
                    'file' => '/app/phalcon/Mvc/Model/MetaData.zep',
                    'line' => 328,
                    'char' => 75,
                  ),
                ),
                'file' => '/app/phalcon/Mvc/Model/MetaData.zep',
                'line' => 328,
                'char' => 76,
              ),
              'file' => '/app/phalcon/Mvc/Model/MetaData.zep',
              'line' => 329,
              'char' => 5,
            ),
          ),
          'docblock' => '**
     * Returns the name of identity field (if one is present)
     *
     *```php
     * print_r(
     *     $metaData->getIdentityField(
     *         new Robots()
     *     )
     * );
     *```
     *
     * @param  Phalcon\\Mvc\\ModelInterface model
     * @return string
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
                'file' => '/app/phalcon/Mvc/Model/MetaData.zep',
                'line' => 327,
                'char' => 5,
              ),
            ),
            'void' => 0,
            'file' => '/app/phalcon/Mvc/Model/MetaData.zep',
            'line' => 327,
            'char' => 5,
          ),
          'file' => '/app/phalcon/Mvc/Model/MetaData.zep',
          'line' => 326,
          'last-line' => 341,
          'char' => 19,
        ),
        11 => 
        array (
          'visibility' => 
          array (
            0 => 'public',
          ),
          'type' => 'method',
          'name' => 'getNonPrimaryKeyAttributes',
          'parameters' => 
          array (
            0 => 
            array (
              'type' => 'parameter',
              'name' => 'model',
              'const' => 0,
              'data-type' => 'variable',
              'mandatory' => 0,
              'cast' => 
              array (
                'type' => 'variable',
                'value' => 'ModelInterface',
                'file' => '/app/phalcon/Mvc/Model/MetaData.zep',
                'line' => 342,
                'char' => 69,
              ),
              'reference' => 0,
              'file' => '/app/phalcon/Mvc/Model/MetaData.zep',
              'line' => 342,
              'char' => 70,
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
                  'file' => '/app/phalcon/Mvc/Model/MetaData.zep',
                  'line' => 344,
                  'char' => 17,
                ),
              ),
              'file' => '/app/phalcon/Mvc/Model/MetaData.zep',
              'line' => 346,
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
                  'variable' => 'data',
                  'expr' => 
                  array (
                    'type' => 'mcall',
                    'variable' => 
                    array (
                      'type' => 'variable',
                      'value' => 'this',
                      'file' => '/app/phalcon/Mvc/Model/MetaData.zep',
                      'line' => 346,
                      'char' => 25,
                    ),
                    'name' => 'readMetaDataIndex',
                    'call-type' => 1,
                    'parameters' => 
                    array (
                      0 => 
                      array (
                        'parameter' => 
                        array (
                          'type' => 'variable',
                          'value' => 'model',
                          'file' => '/app/phalcon/Mvc/Model/MetaData.zep',
                          'line' => 346,
                          'char' => 49,
                        ),
                        'file' => '/app/phalcon/Mvc/Model/MetaData.zep',
                        'line' => 346,
                        'char' => 49,
                      ),
                      1 => 
                      array (
                        'parameter' => 
                        array (
                          'type' => 'static-constant-access',
                          'left' => 
                          array (
                            'type' => 'variable',
                            'value' => 'self',
                            'file' => '/app/phalcon/Mvc/Model/MetaData.zep',
                            'line' => 346,
                            'char' => 79,
                          ),
                          'right' => 
                          array (
                            'type' => 'variable',
                            'value' => 'MODELS_NON_PRIMARY_KEY',
                            'file' => '/app/phalcon/Mvc/Model/MetaData.zep',
                            'line' => 346,
                            'char' => 79,
                          ),
                          'file' => '/app/phalcon/Mvc/Model/MetaData.zep',
                          'line' => 346,
                          'char' => 79,
                        ),
                        'file' => '/app/phalcon/Mvc/Model/MetaData.zep',
                        'line' => 346,
                        'char' => 79,
                      ),
                    ),
                    'file' => '/app/phalcon/Mvc/Model/MetaData.zep',
                    'line' => 346,
                    'char' => 80,
                  ),
                  'file' => '/app/phalcon/Mvc/Model/MetaData.zep',
                  'line' => 346,
                  'char' => 80,
                ),
              ),
              'file' => '/app/phalcon/Mvc/Model/MetaData.zep',
              'line' => 348,
              'char' => 10,
            ),
            2 => 
            array (
              'type' => 'if',
              'expr' => 
              array (
                'type' => 'unlikely',
                'left' => 
                array (
                  'type' => 'not-equals',
                  'left' => 
                  array (
                    'type' => 'typeof',
                    'left' => 
                    array (
                      'type' => 'variable',
                      'value' => 'data',
                      'file' => '/app/phalcon/Mvc/Model/MetaData.zep',
                      'line' => 348,
                      'char' => 34,
                    ),
                    'file' => '/app/phalcon/Mvc/Model/MetaData.zep',
                    'line' => 348,
                    'char' => 34,
                  ),
                  'right' => 
                  array (
                    'type' => 'string',
                    'value' => 'array',
                    'file' => '/app/phalcon/Mvc/Model/MetaData.zep',
                    'line' => 348,
                    'char' => 42,
                  ),
                  'file' => '/app/phalcon/Mvc/Model/MetaData.zep',
                  'line' => 348,
                  'char' => 42,
                ),
                'file' => '/app/phalcon/Mvc/Model/MetaData.zep',
                'line' => 348,
                'char' => 42,
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
                          'value' => 'The meta-data is invalid or is corrupt',
                          'file' => '/app/phalcon/Mvc/Model/MetaData.zep',
                          'line' => 349,
                          'char' => 71,
                        ),
                        'file' => '/app/phalcon/Mvc/Model/MetaData.zep',
                        'line' => 349,
                        'char' => 71,
                      ),
                    ),
                    'file' => '/app/phalcon/Mvc/Model/MetaData.zep',
                    'line' => 349,
                    'char' => 72,
                  ),
                  'file' => '/app/phalcon/Mvc/Model/MetaData.zep',
                  'line' => 350,
                  'char' => 9,
                ),
              ),
              'file' => '/app/phalcon/Mvc/Model/MetaData.zep',
              'line' => 352,
              'char' => 14,
            ),
            3 => 
            array (
              'type' => 'return',
              'expr' => 
              array (
                'type' => 'variable',
                'value' => 'data',
                'file' => '/app/phalcon/Mvc/Model/MetaData.zep',
                'line' => 352,
                'char' => 20,
              ),
              'file' => '/app/phalcon/Mvc/Model/MetaData.zep',
              'line' => 353,
              'char' => 5,
            ),
          ),
          'docblock' => '**
     * Returns an array of fields which are not part of the primary key
     *
     *```php
     * print_r(
     *     $metaData->getNonPrimaryKeyAttributes(
     *         new Robots()
     *     )
     * );
     *```
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
                'file' => '/app/phalcon/Mvc/Model/MetaData.zep',
                'line' => 343,
                'char' => 5,
              ),
            ),
            'void' => 0,
            'file' => '/app/phalcon/Mvc/Model/MetaData.zep',
            'line' => 343,
            'char' => 5,
          ),
          'file' => '/app/phalcon/Mvc/Model/MetaData.zep',
          'line' => 342,
          'last-line' => 365,
          'char' => 19,
        ),
        12 => 
        array (
          'visibility' => 
          array (
            0 => 'public',
          ),
          'type' => 'method',
          'name' => 'getNotNullAttributes',
          'parameters' => 
          array (
            0 => 
            array (
              'type' => 'parameter',
              'name' => 'model',
              'const' => 0,
              'data-type' => 'variable',
              'mandatory' => 0,
              'cast' => 
              array (
                'type' => 'variable',
                'value' => 'ModelInterface',
                'file' => '/app/phalcon/Mvc/Model/MetaData.zep',
                'line' => 366,
                'char' => 63,
              ),
              'reference' => 0,
              'file' => '/app/phalcon/Mvc/Model/MetaData.zep',
              'line' => 366,
              'char' => 64,
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
                  'file' => '/app/phalcon/Mvc/Model/MetaData.zep',
                  'line' => 368,
                  'char' => 17,
                ),
              ),
              'file' => '/app/phalcon/Mvc/Model/MetaData.zep',
              'line' => 370,
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
                  'variable' => 'data',
                  'expr' => 
                  array (
                    'type' => 'mcall',
                    'variable' => 
                    array (
                      'type' => 'variable',
                      'value' => 'this',
                      'file' => '/app/phalcon/Mvc/Model/MetaData.zep',
                      'line' => 370,
                      'char' => 25,
                    ),
                    'name' => 'readMetaDataIndex',
                    'call-type' => 1,
                    'parameters' => 
                    array (
                      0 => 
                      array (
                        'parameter' => 
                        array (
                          'type' => 'variable',
                          'value' => 'model',
                          'file' => '/app/phalcon/Mvc/Model/MetaData.zep',
                          'line' => 370,
                          'char' => 49,
                        ),
                        'file' => '/app/phalcon/Mvc/Model/MetaData.zep',
                        'line' => 370,
                        'char' => 49,
                      ),
                      1 => 
                      array (
                        'parameter' => 
                        array (
                          'type' => 'static-constant-access',
                          'left' => 
                          array (
                            'type' => 'variable',
                            'value' => 'self',
                            'file' => '/app/phalcon/Mvc/Model/MetaData.zep',
                            'line' => 370,
                            'char' => 72,
                          ),
                          'right' => 
                          array (
                            'type' => 'variable',
                            'value' => 'MODELS_NOT_NULL',
                            'file' => '/app/phalcon/Mvc/Model/MetaData.zep',
                            'line' => 370,
                            'char' => 72,
                          ),
                          'file' => '/app/phalcon/Mvc/Model/MetaData.zep',
                          'line' => 370,
                          'char' => 72,
                        ),
                        'file' => '/app/phalcon/Mvc/Model/MetaData.zep',
                        'line' => 370,
                        'char' => 72,
                      ),
                    ),
                    'file' => '/app/phalcon/Mvc/Model/MetaData.zep',
                    'line' => 370,
                    'char' => 73,
                  ),
                  'file' => '/app/phalcon/Mvc/Model/MetaData.zep',
                  'line' => 370,
                  'char' => 73,
                ),
              ),
              'file' => '/app/phalcon/Mvc/Model/MetaData.zep',
              'line' => 372,
              'char' => 10,
            ),
            2 => 
            array (
              'type' => 'if',
              'expr' => 
              array (
                'type' => 'unlikely',
                'left' => 
                array (
                  'type' => 'not-equals',
                  'left' => 
                  array (
                    'type' => 'typeof',
                    'left' => 
                    array (
                      'type' => 'variable',
                      'value' => 'data',
                      'file' => '/app/phalcon/Mvc/Model/MetaData.zep',
                      'line' => 372,
                      'char' => 34,
                    ),
                    'file' => '/app/phalcon/Mvc/Model/MetaData.zep',
                    'line' => 372,
                    'char' => 34,
                  ),
                  'right' => 
                  array (
                    'type' => 'string',
                    'value' => 'array',
                    'file' => '/app/phalcon/Mvc/Model/MetaData.zep',
                    'line' => 372,
                    'char' => 42,
                  ),
                  'file' => '/app/phalcon/Mvc/Model/MetaData.zep',
                  'line' => 372,
                  'char' => 42,
                ),
                'file' => '/app/phalcon/Mvc/Model/MetaData.zep',
                'line' => 372,
                'char' => 42,
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
                          'value' => 'The meta-data is invalid or is corrupt',
                          'file' => '/app/phalcon/Mvc/Model/MetaData.zep',
                          'line' => 373,
                          'char' => 71,
                        ),
                        'file' => '/app/phalcon/Mvc/Model/MetaData.zep',
                        'line' => 373,
                        'char' => 71,
                      ),
                    ),
                    'file' => '/app/phalcon/Mvc/Model/MetaData.zep',
                    'line' => 373,
                    'char' => 72,
                  ),
                  'file' => '/app/phalcon/Mvc/Model/MetaData.zep',
                  'line' => 374,
                  'char' => 9,
                ),
              ),
              'file' => '/app/phalcon/Mvc/Model/MetaData.zep',
              'line' => 376,
              'char' => 14,
            ),
            3 => 
            array (
              'type' => 'return',
              'expr' => 
              array (
                'type' => 'variable',
                'value' => 'data',
                'file' => '/app/phalcon/Mvc/Model/MetaData.zep',
                'line' => 376,
                'char' => 20,
              ),
              'file' => '/app/phalcon/Mvc/Model/MetaData.zep',
              'line' => 377,
              'char' => 5,
            ),
          ),
          'docblock' => '**
     * Returns an array of not null attributes
     *
     *```php
     * print_r(
     *     $metaData->getNotNullAttributes(
     *         new Robots()
     *     )
     * );
     *```
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
                'file' => '/app/phalcon/Mvc/Model/MetaData.zep',
                'line' => 367,
                'char' => 5,
              ),
            ),
            'void' => 0,
            'file' => '/app/phalcon/Mvc/Model/MetaData.zep',
            'line' => 367,
            'char' => 5,
          ),
          'file' => '/app/phalcon/Mvc/Model/MetaData.zep',
          'line' => 366,
          'last-line' => 389,
          'char' => 19,
        ),
        13 => 
        array (
          'visibility' => 
          array (
            0 => 'public',
          ),
          'type' => 'method',
          'name' => 'getPrimaryKeyAttributes',
          'parameters' => 
          array (
            0 => 
            array (
              'type' => 'parameter',
              'name' => 'model',
              'const' => 0,
              'data-type' => 'variable',
              'mandatory' => 0,
              'cast' => 
              array (
                'type' => 'variable',
                'value' => 'ModelInterface',
                'file' => '/app/phalcon/Mvc/Model/MetaData.zep',
                'line' => 390,
                'char' => 66,
              ),
              'reference' => 0,
              'file' => '/app/phalcon/Mvc/Model/MetaData.zep',
              'line' => 390,
              'char' => 67,
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
                  'file' => '/app/phalcon/Mvc/Model/MetaData.zep',
                  'line' => 392,
                  'char' => 17,
                ),
              ),
              'file' => '/app/phalcon/Mvc/Model/MetaData.zep',
              'line' => 394,
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
                  'variable' => 'data',
                  'expr' => 
                  array (
                    'type' => 'mcall',
                    'variable' => 
                    array (
                      'type' => 'variable',
                      'value' => 'this',
                      'file' => '/app/phalcon/Mvc/Model/MetaData.zep',
                      'line' => 394,
                      'char' => 25,
                    ),
                    'name' => 'readMetaDataIndex',
                    'call-type' => 1,
                    'parameters' => 
                    array (
                      0 => 
                      array (
                        'parameter' => 
                        array (
                          'type' => 'variable',
                          'value' => 'model',
                          'file' => '/app/phalcon/Mvc/Model/MetaData.zep',
                          'line' => 394,
                          'char' => 49,
                        ),
                        'file' => '/app/phalcon/Mvc/Model/MetaData.zep',
                        'line' => 394,
                        'char' => 49,
                      ),
                      1 => 
                      array (
                        'parameter' => 
                        array (
                          'type' => 'static-constant-access',
                          'left' => 
                          array (
                            'type' => 'variable',
                            'value' => 'self',
                            'file' => '/app/phalcon/Mvc/Model/MetaData.zep',
                            'line' => 394,
                            'char' => 75,
                          ),
                          'right' => 
                          array (
                            'type' => 'variable',
                            'value' => 'MODELS_PRIMARY_KEY',
                            'file' => '/app/phalcon/Mvc/Model/MetaData.zep',
                            'line' => 394,
                            'char' => 75,
                          ),
                          'file' => '/app/phalcon/Mvc/Model/MetaData.zep',
                          'line' => 394,
                          'char' => 75,
                        ),
                        'file' => '/app/phalcon/Mvc/Model/MetaData.zep',
                        'line' => 394,
                        'char' => 75,
                      ),
                    ),
                    'file' => '/app/phalcon/Mvc/Model/MetaData.zep',
                    'line' => 394,
                    'char' => 76,
                  ),
                  'file' => '/app/phalcon/Mvc/Model/MetaData.zep',
                  'line' => 394,
                  'char' => 76,
                ),
              ),
              'file' => '/app/phalcon/Mvc/Model/MetaData.zep',
              'line' => 396,
              'char' => 10,
            ),
            2 => 
            array (
              'type' => 'if',
              'expr' => 
              array (
                'type' => 'unlikely',
                'left' => 
                array (
                  'type' => 'not-equals',
                  'left' => 
                  array (
                    'type' => 'typeof',
                    'left' => 
                    array (
                      'type' => 'variable',
                      'value' => 'data',
                      'file' => '/app/phalcon/Mvc/Model/MetaData.zep',
                      'line' => 396,
                      'char' => 34,
                    ),
                    'file' => '/app/phalcon/Mvc/Model/MetaData.zep',
                    'line' => 396,
                    'char' => 34,
                  ),
                  'right' => 
                  array (
                    'type' => 'string',
                    'value' => 'array',
                    'file' => '/app/phalcon/Mvc/Model/MetaData.zep',
                    'line' => 396,
                    'char' => 42,
                  ),
                  'file' => '/app/phalcon/Mvc/Model/MetaData.zep',
                  'line' => 396,
                  'char' => 42,
                ),
                'file' => '/app/phalcon/Mvc/Model/MetaData.zep',
                'line' => 396,
                'char' => 42,
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
                          'value' => 'The meta-data is invalid or is corrupt',
                          'file' => '/app/phalcon/Mvc/Model/MetaData.zep',
                          'line' => 397,
                          'char' => 71,
                        ),
                        'file' => '/app/phalcon/Mvc/Model/MetaData.zep',
                        'line' => 397,
                        'char' => 71,
                      ),
                    ),
                    'file' => '/app/phalcon/Mvc/Model/MetaData.zep',
                    'line' => 397,
                    'char' => 72,
                  ),
                  'file' => '/app/phalcon/Mvc/Model/MetaData.zep',
                  'line' => 398,
                  'char' => 9,
                ),
              ),
              'file' => '/app/phalcon/Mvc/Model/MetaData.zep',
              'line' => 400,
              'char' => 14,
            ),
            3 => 
            array (
              'type' => 'return',
              'expr' => 
              array (
                'type' => 'variable',
                'value' => 'data',
                'file' => '/app/phalcon/Mvc/Model/MetaData.zep',
                'line' => 400,
                'char' => 20,
              ),
              'file' => '/app/phalcon/Mvc/Model/MetaData.zep',
              'line' => 401,
              'char' => 5,
            ),
          ),
          'docblock' => '**
     * Returns an array of fields which are part of the primary key
     *
     *```php
     * print_r(
     *     $metaData->getPrimaryKeyAttributes(
     *         new Robots()
     *     )
     * );
     *```
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
                'file' => '/app/phalcon/Mvc/Model/MetaData.zep',
                'line' => 391,
                'char' => 5,
              ),
            ),
            'void' => 0,
            'file' => '/app/phalcon/Mvc/Model/MetaData.zep',
            'line' => 391,
            'char' => 5,
          ),
          'file' => '/app/phalcon/Mvc/Model/MetaData.zep',
          'line' => 390,
          'last-line' => 413,
          'char' => 19,
        ),
        14 => 
        array (
          'visibility' => 
          array (
            0 => 'public',
          ),
          'type' => 'method',
          'name' => 'getReverseColumnMap',
          'parameters' => 
          array (
            0 => 
            array (
              'type' => 'parameter',
              'name' => 'model',
              'const' => 0,
              'data-type' => 'variable',
              'mandatory' => 0,
              'cast' => 
              array (
                'type' => 'variable',
                'value' => 'ModelInterface',
                'file' => '/app/phalcon/Mvc/Model/MetaData.zep',
                'line' => 414,
                'char' => 62,
              ),
              'reference' => 0,
              'file' => '/app/phalcon/Mvc/Model/MetaData.zep',
              'line' => 414,
              'char' => 63,
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
                  'file' => '/app/phalcon/Mvc/Model/MetaData.zep',
                  'line' => 416,
                  'char' => 17,
                ),
              ),
              'file' => '/app/phalcon/Mvc/Model/MetaData.zep',
              'line' => 418,
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
                  'variable' => 'data',
                  'expr' => 
                  array (
                    'type' => 'mcall',
                    'variable' => 
                    array (
                      'type' => 'variable',
                      'value' => 'this',
                      'file' => '/app/phalcon/Mvc/Model/MetaData.zep',
                      'line' => 418,
                      'char' => 25,
                    ),
                    'name' => 'readColumnMapIndex',
                    'call-type' => 1,
                    'parameters' => 
                    array (
                      0 => 
                      array (
                        'parameter' => 
                        array (
                          'type' => 'variable',
                          'value' => 'model',
                          'file' => '/app/phalcon/Mvc/Model/MetaData.zep',
                          'line' => 419,
                          'char' => 18,
                        ),
                        'file' => '/app/phalcon/Mvc/Model/MetaData.zep',
                        'line' => 419,
                        'char' => 18,
                      ),
                      1 => 
                      array (
                        'parameter' => 
                        array (
                          'type' => 'static-constant-access',
                          'left' => 
                          array (
                            'type' => 'variable',
                            'value' => 'self',
                            'file' => '/app/phalcon/Mvc/Model/MetaData.zep',
                            'line' => 421,
                            'char' => 9,
                          ),
                          'right' => 
                          array (
                            'type' => 'variable',
                            'value' => 'MODELS_REVERSE_COLUMN_MAP',
                            'file' => '/app/phalcon/Mvc/Model/MetaData.zep',
                            'line' => 421,
                            'char' => 9,
                          ),
                          'file' => '/app/phalcon/Mvc/Model/MetaData.zep',
                          'line' => 421,
                          'char' => 9,
                        ),
                        'file' => '/app/phalcon/Mvc/Model/MetaData.zep',
                        'line' => 421,
                        'char' => 9,
                      ),
                    ),
                    'file' => '/app/phalcon/Mvc/Model/MetaData.zep',
                    'line' => 421,
                    'char' => 10,
                  ),
                  'file' => '/app/phalcon/Mvc/Model/MetaData.zep',
                  'line' => 421,
                  'char' => 10,
                ),
              ),
              'file' => '/app/phalcon/Mvc/Model/MetaData.zep',
              'line' => 423,
              'char' => 10,
            ),
            2 => 
            array (
              'type' => 'if',
              'expr' => 
              array (
                'type' => 'unlikely',
                'left' => 
                array (
                  'type' => 'list',
                  'left' => 
                  array (
                    'type' => 'and',
                    'left' => 
                    array (
                      'type' => 'not-identical',
                      'left' => 
                      array (
                        'type' => 'variable',
                        'value' => 'data',
                        'file' => '/app/phalcon/Mvc/Model/MetaData.zep',
                        'line' => 423,
                        'char' => 29,
                      ),
                      'right' => 
                      array (
                        'type' => 'null',
                        'file' => '/app/phalcon/Mvc/Model/MetaData.zep',
                        'line' => 423,
                        'char' => 37,
                      ),
                      'file' => '/app/phalcon/Mvc/Model/MetaData.zep',
                      'line' => 423,
                      'char' => 37,
                    ),
                    'right' => 
                    array (
                      'type' => 'not-equals',
                      'left' => 
                      array (
                        'type' => 'typeof',
                        'left' => 
                        array (
                          'type' => 'variable',
                          'value' => 'data',
                          'file' => '/app/phalcon/Mvc/Model/MetaData.zep',
                          'line' => 423,
                          'char' => 52,
                        ),
                        'file' => '/app/phalcon/Mvc/Model/MetaData.zep',
                        'line' => 423,
                        'char' => 52,
                      ),
                      'right' => 
                      array (
                        'type' => 'string',
                        'value' => 'array',
                        'file' => '/app/phalcon/Mvc/Model/MetaData.zep',
                        'line' => 423,
                        'char' => 59,
                      ),
                      'file' => '/app/phalcon/Mvc/Model/MetaData.zep',
                      'line' => 423,
                      'char' => 59,
                    ),
                    'file' => '/app/phalcon/Mvc/Model/MetaData.zep',
                    'line' => 423,
                    'char' => 59,
                  ),
                  'file' => '/app/phalcon/Mvc/Model/MetaData.zep',
                  'line' => 423,
                  'char' => 61,
                ),
                'file' => '/app/phalcon/Mvc/Model/MetaData.zep',
                'line' => 423,
                'char' => 61,
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
                          'value' => 'The meta-data is invalid or is corrupt',
                          'file' => '/app/phalcon/Mvc/Model/MetaData.zep',
                          'line' => 424,
                          'char' => 71,
                        ),
                        'file' => '/app/phalcon/Mvc/Model/MetaData.zep',
                        'line' => 424,
                        'char' => 71,
                      ),
                    ),
                    'file' => '/app/phalcon/Mvc/Model/MetaData.zep',
                    'line' => 424,
                    'char' => 72,
                  ),
                  'file' => '/app/phalcon/Mvc/Model/MetaData.zep',
                  'line' => 425,
                  'char' => 9,
                ),
              ),
              'file' => '/app/phalcon/Mvc/Model/MetaData.zep',
              'line' => 427,
              'char' => 14,
            ),
            3 => 
            array (
              'type' => 'return',
              'expr' => 
              array (
                'type' => 'variable',
                'value' => 'data',
                'file' => '/app/phalcon/Mvc/Model/MetaData.zep',
                'line' => 427,
                'char' => 20,
              ),
              'file' => '/app/phalcon/Mvc/Model/MetaData.zep',
              'line' => 428,
              'char' => 5,
            ),
          ),
          'docblock' => '**
     * Returns the reverse column map if any
     *
     *```php
     * print_r(
     *     $metaData->getReverseColumnMap(
     *         new Robots()
     *     )
     * );
     *```
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
                'file' => '/app/phalcon/Mvc/Model/MetaData.zep',
                'line' => 415,
                'char' => 5,
              ),
            ),
            'void' => 0,
            'file' => '/app/phalcon/Mvc/Model/MetaData.zep',
            'line' => 415,
            'char' => 5,
          ),
          'file' => '/app/phalcon/Mvc/Model/MetaData.zep',
          'line' => 414,
          'last-line' => 432,
          'char' => 19,
        ),
        15 => 
        array (
          'visibility' => 
          array (
            0 => 'public',
          ),
          'type' => 'method',
          'name' => 'getStrategy',
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
                  'type' => 'property-access',
                  'left' => 
                  array (
                    'type' => 'variable',
                    'value' => 'this',
                    'file' => '/app/phalcon/Mvc/Model/MetaData.zep',
                    'line' => 435,
                    'char' => 17,
                  ),
                  'right' => 
                  array (
                    'type' => 'variable',
                    'value' => 'strategy',
                    'file' => '/app/phalcon/Mvc/Model/MetaData.zep',
                    'line' => 435,
                    'char' => 29,
                  ),
                  'file' => '/app/phalcon/Mvc/Model/MetaData.zep',
                  'line' => 435,
                  'char' => 29,
                ),
                'right' => 
                array (
                  'type' => 'null',
                  'file' => '/app/phalcon/Mvc/Model/MetaData.zep',
                  'line' => 435,
                  'char' => 36,
                ),
                'file' => '/app/phalcon/Mvc/Model/MetaData.zep',
                'line' => 435,
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
                      'property' => 'strategy',
                      'expr' => 
                      array (
                        'type' => 'new',
                        'class' => 'Introspection',
                        'dynamic' => 0,
                        'file' => '/app/phalcon/Mvc/Model/MetaData.zep',
                        'line' => 436,
                        'char' => 53,
                      ),
                      'file' => '/app/phalcon/Mvc/Model/MetaData.zep',
                      'line' => 436,
                      'char' => 53,
                    ),
                  ),
                  'file' => '/app/phalcon/Mvc/Model/MetaData.zep',
                  'line' => 437,
                  'char' => 9,
                ),
              ),
              'file' => '/app/phalcon/Mvc/Model/MetaData.zep',
              'line' => 439,
              'char' => 14,
            ),
            1 => 
            array (
              'type' => 'return',
              'expr' => 
              array (
                'type' => 'property-access',
                'left' => 
                array (
                  'type' => 'variable',
                  'value' => 'this',
                  'file' => '/app/phalcon/Mvc/Model/MetaData.zep',
                  'line' => 439,
                  'char' => 21,
                ),
                'right' => 
                array (
                  'type' => 'variable',
                  'value' => 'strategy',
                  'file' => '/app/phalcon/Mvc/Model/MetaData.zep',
                  'line' => 439,
                  'char' => 30,
                ),
                'file' => '/app/phalcon/Mvc/Model/MetaData.zep',
                'line' => 439,
                'char' => 30,
              ),
              'file' => '/app/phalcon/Mvc/Model/MetaData.zep',
              'line' => 440,
              'char' => 5,
            ),
          ),
          'docblock' => '**
     * Return the strategy to obtain the meta-data
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
                  'value' => 'StrategyInterface',
                  'file' => '/app/phalcon/Mvc/Model/MetaData.zep',
                  'line' => 434,
                  'char' => 5,
                ),
                'collection' => 0,
                'file' => '/app/phalcon/Mvc/Model/MetaData.zep',
                'line' => 434,
                'char' => 5,
              ),
            ),
            'void' => 0,
            'file' => '/app/phalcon/Mvc/Model/MetaData.zep',
            'line' => 434,
            'char' => 5,
          ),
          'file' => '/app/phalcon/Mvc/Model/MetaData.zep',
          'line' => 433,
          'last-line' => 453,
          'char' => 19,
        ),
        16 => 
        array (
          'visibility' => 
          array (
            0 => 'public',
          ),
          'type' => 'method',
          'name' => 'hasAttribute',
          'parameters' => 
          array (
            0 => 
            array (
              'type' => 'parameter',
              'name' => 'model',
              'const' => 0,
              'data-type' => 'variable',
              'mandatory' => 0,
              'cast' => 
              array (
                'type' => 'variable',
                'value' => 'ModelInterface',
                'file' => '/app/phalcon/Mvc/Model/MetaData.zep',
                'line' => 454,
                'char' => 55,
              ),
              'reference' => 0,
              'file' => '/app/phalcon/Mvc/Model/MetaData.zep',
              'line' => 454,
              'char' => 56,
            ),
            1 => 
            array (
              'type' => 'parameter',
              'name' => 'attribute',
              'const' => 0,
              'data-type' => 'string',
              'mandatory' => 0,
              'reference' => 0,
              'file' => '/app/phalcon/Mvc/Model/MetaData.zep',
              'line' => 454,
              'char' => 74,
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
                  'variable' => 'columnMap',
                  'file' => '/app/phalcon/Mvc/Model/MetaData.zep',
                  'line' => 456,
                  'char' => 22,
                ),
              ),
              'file' => '/app/phalcon/Mvc/Model/MetaData.zep',
              'line' => 458,
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
                  'variable' => 'columnMap',
                  'expr' => 
                  array (
                    'type' => 'mcall',
                    'variable' => 
                    array (
                      'type' => 'variable',
                      'value' => 'this',
                      'file' => '/app/phalcon/Mvc/Model/MetaData.zep',
                      'line' => 458,
                      'char' => 30,
                    ),
                    'name' => 'getReverseColumnMap',
                    'call-type' => 1,
                    'parameters' => 
                    array (
                      0 => 
                      array (
                        'parameter' => 
                        array (
                          'type' => 'variable',
                          'value' => 'model',
                          'file' => '/app/phalcon/Mvc/Model/MetaData.zep',
                          'line' => 458,
                          'char' => 56,
                        ),
                        'file' => '/app/phalcon/Mvc/Model/MetaData.zep',
                        'line' => 458,
                        'char' => 56,
                      ),
                    ),
                    'file' => '/app/phalcon/Mvc/Model/MetaData.zep',
                    'line' => 458,
                    'char' => 57,
                  ),
                  'file' => '/app/phalcon/Mvc/Model/MetaData.zep',
                  'line' => 458,
                  'char' => 57,
                ),
              ),
              'file' => '/app/phalcon/Mvc/Model/MetaData.zep',
              'line' => 460,
              'char' => 10,
            ),
            2 => 
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
                    'value' => 'columnMap',
                    'file' => '/app/phalcon/Mvc/Model/MetaData.zep',
                    'line' => 460,
                    'char' => 30,
                  ),
                  'file' => '/app/phalcon/Mvc/Model/MetaData.zep',
                  'line' => 460,
                  'char' => 30,
                ),
                'right' => 
                array (
                  'type' => 'string',
                  'value' => 'array',
                  'file' => '/app/phalcon/Mvc/Model/MetaData.zep',
                  'line' => 460,
                  'char' => 38,
                ),
                'file' => '/app/phalcon/Mvc/Model/MetaData.zep',
                'line' => 460,
                'char' => 38,
              ),
              'statements' => 
              array (
                0 => 
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
                        'type' => 'variable',
                        'value' => 'columnMap',
                        'file' => '/app/phalcon/Mvc/Model/MetaData.zep',
                        'line' => 461,
                        'char' => 35,
                      ),
                      'right' => 
                      array (
                        'type' => 'variable',
                        'value' => 'attribute',
                        'file' => '/app/phalcon/Mvc/Model/MetaData.zep',
                        'line' => 461,
                        'char' => 45,
                      ),
                      'file' => '/app/phalcon/Mvc/Model/MetaData.zep',
                      'line' => 461,
                      'char' => 46,
                    ),
                    'file' => '/app/phalcon/Mvc/Model/MetaData.zep',
                    'line' => 461,
                    'char' => 46,
                  ),
                  'file' => '/app/phalcon/Mvc/Model/MetaData.zep',
                  'line' => 462,
                  'char' => 9,
                ),
              ),
              'file' => '/app/phalcon/Mvc/Model/MetaData.zep',
              'line' => 464,
              'char' => 14,
            ),
            3 => 
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
                    'type' => 'array-access',
                    'left' => 
                    array (
                      'type' => 'mcall',
                      'variable' => 
                      array (
                        'type' => 'variable',
                        'value' => 'this',
                        'file' => '/app/phalcon/Mvc/Model/MetaData.zep',
                        'line' => 464,
                        'char' => 27,
                      ),
                      'name' => 'readMetaData',
                      'call-type' => 1,
                      'parameters' => 
                      array (
                        0 => 
                        array (
                          'parameter' => 
                          array (
                            'type' => 'variable',
                            'value' => 'model',
                            'file' => '/app/phalcon/Mvc/Model/MetaData.zep',
                            'line' => 464,
                            'char' => 46,
                          ),
                          'file' => '/app/phalcon/Mvc/Model/MetaData.zep',
                          'line' => 464,
                          'char' => 46,
                        ),
                      ),
                      'file' => '/app/phalcon/Mvc/Model/MetaData.zep',
                      'line' => 464,
                      'char' => 47,
                    ),
                    'right' => 
                    array (
                      'type' => 'static-constant-access',
                      'left' => 
                      array (
                        'type' => 'variable',
                        'value' => 'self',
                        'file' => '/app/phalcon/Mvc/Model/MetaData.zep',
                        'line' => 464,
                        'char' => 71,
                      ),
                      'right' => 
                      array (
                        'type' => 'variable',
                        'value' => 'MODELS_DATA_TYPES',
                        'file' => '/app/phalcon/Mvc/Model/MetaData.zep',
                        'line' => 464,
                        'char' => 71,
                      ),
                      'file' => '/app/phalcon/Mvc/Model/MetaData.zep',
                      'line' => 464,
                      'char' => 71,
                    ),
                    'file' => '/app/phalcon/Mvc/Model/MetaData.zep',
                    'line' => 464,
                    'char' => 72,
                  ),
                  'right' => 
                  array (
                    'type' => 'variable',
                    'value' => 'attribute',
                    'file' => '/app/phalcon/Mvc/Model/MetaData.zep',
                    'line' => 464,
                    'char' => 82,
                  ),
                  'file' => '/app/phalcon/Mvc/Model/MetaData.zep',
                  'line' => 464,
                  'char' => 83,
                ),
                'file' => '/app/phalcon/Mvc/Model/MetaData.zep',
                'line' => 464,
                'char' => 83,
              ),
              'file' => '/app/phalcon/Mvc/Model/MetaData.zep',
              'line' => 465,
              'char' => 5,
            ),
          ),
          'docblock' => '**
     * Check if a model has certain attribute
     *
     *```php
     * var_dump(
     *     $metaData->hasAttribute(
     *         new Robots(),
     *         "name"
     *     )
     * );
     *```
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
                'file' => '/app/phalcon/Mvc/Model/MetaData.zep',
                'line' => 455,
                'char' => 5,
              ),
            ),
            'void' => 0,
            'file' => '/app/phalcon/Mvc/Model/MetaData.zep',
            'line' => 455,
            'char' => 5,
          ),
          'file' => '/app/phalcon/Mvc/Model/MetaData.zep',
          'line' => 454,
          'last-line' => 475,
          'char' => 19,
        ),
        17 => 
        array (
          'visibility' => 
          array (
            0 => 'public',
          ),
          'type' => 'method',
          'name' => 'isEmpty',
          'statements' => 
          array (
            0 => 
            array (
              'type' => 'return',
              'expr' => 
              array (
                'type' => 'equals',
                'left' => 
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
                          'file' => '/app/phalcon/Mvc/Model/MetaData.zep',
                          'line' => 478,
                          'char' => 27,
                        ),
                        'right' => 
                        array (
                          'type' => 'variable',
                          'value' => 'metaData',
                          'file' => '/app/phalcon/Mvc/Model/MetaData.zep',
                          'line' => 478,
                          'char' => 36,
                        ),
                        'file' => '/app/phalcon/Mvc/Model/MetaData.zep',
                        'line' => 478,
                        'char' => 36,
                      ),
                      'file' => '/app/phalcon/Mvc/Model/MetaData.zep',
                      'line' => 478,
                      'char' => 36,
                    ),
                  ),
                  'file' => '/app/phalcon/Mvc/Model/MetaData.zep',
                  'line' => 478,
                  'char' => 39,
                ),
                'right' => 
                array (
                  'type' => 'int',
                  'value' => '0',
                  'file' => '/app/phalcon/Mvc/Model/MetaData.zep',
                  'line' => 478,
                  'char' => 42,
                ),
                'file' => '/app/phalcon/Mvc/Model/MetaData.zep',
                'line' => 478,
                'char' => 42,
              ),
              'file' => '/app/phalcon/Mvc/Model/MetaData.zep',
              'line' => 479,
              'char' => 5,
            ),
          ),
          'docblock' => '**
     * Checks if the internal meta-data container is empty
     *
     *```php
     * var_dump(
     *     $metaData->isEmpty()
     * );
     *```
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
                'file' => '/app/phalcon/Mvc/Model/MetaData.zep',
                'line' => 477,
                'char' => 5,
              ),
            ),
            'void' => 0,
            'file' => '/app/phalcon/Mvc/Model/MetaData.zep',
            'line' => 477,
            'char' => 5,
          ),
          'file' => '/app/phalcon/Mvc/Model/MetaData.zep',
          'line' => 476,
          'last-line' => 483,
          'char' => 19,
        ),
        18 => 
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
              'name' => 'key',
              'const' => 0,
              'data-type' => 'string',
              'mandatory' => 1,
              'reference' => 0,
              'file' => '/app/phalcon/Mvc/Model/MetaData.zep',
              'line' => 484,
              'char' => 37,
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
                  'type' => 'property-access',
                  'left' => 
                  array (
                    'type' => 'variable',
                    'value' => 'this',
                    'file' => '/app/phalcon/Mvc/Model/MetaData.zep',
                    'line' => 486,
                    'char' => 21,
                  ),
                  'right' => 
                  array (
                    'type' => 'variable',
                    'value' => 'adapter',
                    'file' => '/app/phalcon/Mvc/Model/MetaData.zep',
                    'line' => 486,
                    'char' => 30,
                  ),
                  'file' => '/app/phalcon/Mvc/Model/MetaData.zep',
                  'line' => 486,
                  'char' => 30,
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
                      'value' => 'key',
                      'file' => '/app/phalcon/Mvc/Model/MetaData.zep',
                      'line' => 486,
                      'char' => 38,
                    ),
                    'file' => '/app/phalcon/Mvc/Model/MetaData.zep',
                    'line' => 486,
                    'char' => 38,
                  ),
                ),
                'file' => '/app/phalcon/Mvc/Model/MetaData.zep',
                'line' => 486,
                'char' => 39,
              ),
              'file' => '/app/phalcon/Mvc/Model/MetaData.zep',
              'line' => 487,
              'char' => 5,
            ),
          ),
          'docblock' => '**
     * Reads metadata from the adapter
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
                'file' => '/app/phalcon/Mvc/Model/MetaData.zep',
                'line' => 484,
                'char' => 48,
              ),
              1 => 
              array (
                'type' => 'return-type-parameter',
                'data-type' => 'null',
                'mandatory' => 0,
                'file' => '/app/phalcon/Mvc/Model/MetaData.zep',
                'line' => 485,
                'char' => 5,
              ),
            ),
            'void' => 0,
            'file' => '/app/phalcon/Mvc/Model/MetaData.zep',
            'line' => 485,
            'char' => 5,
          ),
          'file' => '/app/phalcon/Mvc/Model/MetaData.zep',
          'line' => 484,
          'last-line' => 499,
          'char' => 19,
        ),
        19 => 
        array (
          'visibility' => 
          array (
            0 => 'final',
            1 => 'public',
          ),
          'type' => 'method',
          'name' => 'readColumnMap',
          'parameters' => 
          array (
            0 => 
            array (
              'type' => 'parameter',
              'name' => 'model',
              'const' => 0,
              'data-type' => 'variable',
              'mandatory' => 0,
              'cast' => 
              array (
                'type' => 'variable',
                'value' => 'ModelInterface',
                'file' => '/app/phalcon/Mvc/Model/MetaData.zep',
                'line' => 500,
                'char' => 62,
              ),
              'reference' => 0,
              'file' => '/app/phalcon/Mvc/Model/MetaData.zep',
              'line' => 500,
              'char' => 63,
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
                  'variable' => 'keyName',
                  'file' => '/app/phalcon/Mvc/Model/MetaData.zep',
                  'line' => 502,
                  'char' => 20,
                ),
                1 => 
                array (
                  'variable' => 'data',
                  'file' => '/app/phalcon/Mvc/Model/MetaData.zep',
                  'line' => 502,
                  'char' => 26,
                ),
              ),
              'file' => '/app/phalcon/Mvc/Model/MetaData.zep',
              'line' => 504,
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
                  'type' => 'fcall',
                  'name' => 'globals_get',
                  'call-type' => 1,
                  'parameters' => 
                  array (
                    0 => 
                    array (
                      'parameter' => 
                      array (
                        'type' => 'string',
                        'value' => 'orm.column_renaming',
                        'file' => '/app/phalcon/Mvc/Model/MetaData.zep',
                        'line' => 504,
                        'char' => 44,
                      ),
                      'file' => '/app/phalcon/Mvc/Model/MetaData.zep',
                      'line' => 504,
                      'char' => 44,
                    ),
                  ),
                  'file' => '/app/phalcon/Mvc/Model/MetaData.zep',
                  'line' => 504,
                  'char' => 46,
                ),
                'file' => '/app/phalcon/Mvc/Model/MetaData.zep',
                'line' => 504,
                'char' => 46,
              ),
              'statements' => 
              array (
                0 => 
                array (
                  'type' => 'return',
                  'expr' => 
                  array (
                    'type' => 'null',
                    'file' => '/app/phalcon/Mvc/Model/MetaData.zep',
                    'line' => 505,
                    'char' => 24,
                  ),
                  'file' => '/app/phalcon/Mvc/Model/MetaData.zep',
                  'line' => 506,
                  'char' => 9,
                ),
              ),
              'file' => '/app/phalcon/Mvc/Model/MetaData.zep',
              'line' => 508,
              'char' => 11,
            ),
            2 => 
            array (
              'type' => 'let',
              'assignments' => 
              array (
                0 => 
                array (
                  'assign-type' => 'variable',
                  'operator' => 'assign',
                  'variable' => 'keyName',
                  'expr' => 
                  array (
                    'type' => 'fcall',
                    'name' => 'get_class_lower',
                    'call-type' => 1,
                    'parameters' => 
                    array (
                      0 => 
                      array (
                        'parameter' => 
                        array (
                          'type' => 'variable',
                          'value' => 'model',
                          'file' => '/app/phalcon/Mvc/Model/MetaData.zep',
                          'line' => 508,
                          'char' => 44,
                        ),
                        'file' => '/app/phalcon/Mvc/Model/MetaData.zep',
                        'line' => 508,
                        'char' => 44,
                      ),
                    ),
                    'file' => '/app/phalcon/Mvc/Model/MetaData.zep',
                    'line' => 508,
                    'char' => 45,
                  ),
                  'file' => '/app/phalcon/Mvc/Model/MetaData.zep',
                  'line' => 508,
                  'char' => 45,
                ),
              ),
              'file' => '/app/phalcon/Mvc/Model/MetaData.zep',
              'line' => 510,
              'char' => 10,
            ),
            3 => 
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
                    'value' => 'data',
                    'file' => '/app/phalcon/Mvc/Model/MetaData.zep',
                    'line' => 510,
                    'char' => 50,
                  ),
                  'right' => 
                  array (
                    'type' => 'array-access',
                    'left' => 
                    array (
                      'type' => 'property-access',
                      'left' => 
                      array (
                        'type' => 'variable',
                        'value' => 'this',
                        'file' => '/app/phalcon/Mvc/Model/MetaData.zep',
                        'line' => 510,
                        'char' => 30,
                      ),
                      'right' => 
                      array (
                        'type' => 'variable',
                        'value' => 'columnMap',
                        'file' => '/app/phalcon/Mvc/Model/MetaData.zep',
                        'line' => 510,
                        'char' => 40,
                      ),
                      'file' => '/app/phalcon/Mvc/Model/MetaData.zep',
                      'line' => 510,
                      'char' => 40,
                    ),
                    'right' => 
                    array (
                      'type' => 'variable',
                      'value' => 'keyName',
                      'file' => '/app/phalcon/Mvc/Model/MetaData.zep',
                      'line' => 510,
                      'char' => 48,
                    ),
                    'file' => '/app/phalcon/Mvc/Model/MetaData.zep',
                    'line' => 510,
                    'char' => 50,
                  ),
                  'file' => '/app/phalcon/Mvc/Model/MetaData.zep',
                  'line' => 510,
                  'char' => 50,
                ),
                'file' => '/app/phalcon/Mvc/Model/MetaData.zep',
                'line' => 510,
                'char' => 50,
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
                      'file' => '/app/phalcon/Mvc/Model/MetaData.zep',
                      'line' => 511,
                      'char' => 18,
                    ),
                    'name' => 'initialize',
                    'call-type' => 1,
                    'parameters' => 
                    array (
                      0 => 
                      array (
                        'parameter' => 
                        array (
                          'type' => 'variable',
                          'value' => 'model',
                          'file' => '/app/phalcon/Mvc/Model/MetaData.zep',
                          'line' => 511,
                          'char' => 35,
                        ),
                        'file' => '/app/phalcon/Mvc/Model/MetaData.zep',
                        'line' => 511,
                        'char' => 35,
                      ),
                      1 => 
                      array (
                        'parameter' => 
                        array (
                          'type' => 'null',
                          'file' => '/app/phalcon/Mvc/Model/MetaData.zep',
                          'line' => 511,
                          'char' => 41,
                        ),
                        'file' => '/app/phalcon/Mvc/Model/MetaData.zep',
                        'line' => 511,
                        'char' => 41,
                      ),
                      2 => 
                      array (
                        'parameter' => 
                        array (
                          'type' => 'null',
                          'file' => '/app/phalcon/Mvc/Model/MetaData.zep',
                          'line' => 511,
                          'char' => 47,
                        ),
                        'file' => '/app/phalcon/Mvc/Model/MetaData.zep',
                        'line' => 511,
                        'char' => 47,
                      ),
                      3 => 
                      array (
                        'parameter' => 
                        array (
                          'type' => 'null',
                          'file' => '/app/phalcon/Mvc/Model/MetaData.zep',
                          'line' => 511,
                          'char' => 53,
                        ),
                        'file' => '/app/phalcon/Mvc/Model/MetaData.zep',
                        'line' => 511,
                        'char' => 53,
                      ),
                    ),
                    'file' => '/app/phalcon/Mvc/Model/MetaData.zep',
                    'line' => 511,
                    'char' => 54,
                  ),
                  'file' => '/app/phalcon/Mvc/Model/MetaData.zep',
                  'line' => 513,
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
                        'type' => 'array-access',
                        'left' => 
                        array (
                          'type' => 'property-access',
                          'left' => 
                          array (
                            'type' => 'variable',
                            'value' => 'this',
                            'file' => '/app/phalcon/Mvc/Model/MetaData.zep',
                            'line' => 513,
                            'char' => 29,
                          ),
                          'right' => 
                          array (
                            'type' => 'variable',
                            'value' => 'columnMap',
                            'file' => '/app/phalcon/Mvc/Model/MetaData.zep',
                            'line' => 513,
                            'char' => 39,
                          ),
                          'file' => '/app/phalcon/Mvc/Model/MetaData.zep',
                          'line' => 513,
                          'char' => 39,
                        ),
                        'right' => 
                        array (
                          'type' => 'variable',
                          'value' => 'keyName',
                          'file' => '/app/phalcon/Mvc/Model/MetaData.zep',
                          'line' => 513,
                          'char' => 47,
                        ),
                        'file' => '/app/phalcon/Mvc/Model/MetaData.zep',
                        'line' => 513,
                        'char' => 48,
                      ),
                      'file' => '/app/phalcon/Mvc/Model/MetaData.zep',
                      'line' => 513,
                      'char' => 48,
                    ),
                  ),
                  'file' => '/app/phalcon/Mvc/Model/MetaData.zep',
                  'line' => 514,
                  'char' => 9,
                ),
              ),
              'file' => '/app/phalcon/Mvc/Model/MetaData.zep',
              'line' => 516,
              'char' => 14,
            ),
            4 => 
            array (
              'type' => 'return',
              'expr' => 
              array (
                'type' => 'variable',
                'value' => 'data',
                'file' => '/app/phalcon/Mvc/Model/MetaData.zep',
                'line' => 516,
                'char' => 20,
              ),
              'file' => '/app/phalcon/Mvc/Model/MetaData.zep',
              'line' => 517,
              'char' => 5,
            ),
          ),
          'docblock' => '**
     * Reads the ordered/reversed column map for certain model
     *
     *```php
     * print_r(
     *     $metaData->readColumnMap(
     *         new Robots()
     *     )
     * );
     *```
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
                'file' => '/app/phalcon/Mvc/Model/MetaData.zep',
                'line' => 500,
                'char' => 74,
              ),
              1 => 
              array (
                'type' => 'return-type-parameter',
                'data-type' => 'null',
                'mandatory' => 0,
                'file' => '/app/phalcon/Mvc/Model/MetaData.zep',
                'line' => 501,
                'char' => 5,
              ),
            ),
            'void' => 0,
            'file' => '/app/phalcon/Mvc/Model/MetaData.zep',
            'line' => 501,
            'char' => 5,
          ),
          'file' => '/app/phalcon/Mvc/Model/MetaData.zep',
          'line' => 500,
          'last-line' => 530,
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
          'name' => 'readColumnMapIndex',
          'parameters' => 
          array (
            0 => 
            array (
              'type' => 'parameter',
              'name' => 'model',
              'const' => 0,
              'data-type' => 'variable',
              'mandatory' => 0,
              'cast' => 
              array (
                'type' => 'variable',
                'value' => 'ModelInterface',
                'file' => '/app/phalcon/Mvc/Model/MetaData.zep',
                'line' => 531,
                'char' => 67,
              ),
              'reference' => 0,
              'file' => '/app/phalcon/Mvc/Model/MetaData.zep',
              'line' => 531,
              'char' => 68,
            ),
            1 => 
            array (
              'type' => 'parameter',
              'name' => 'index',
              'const' => 0,
              'data-type' => 'int',
              'mandatory' => 0,
              'reference' => 0,
              'file' => '/app/phalcon/Mvc/Model/MetaData.zep',
              'line' => 531,
              'char' => 79,
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
                  'variable' => 'keyName',
                  'file' => '/app/phalcon/Mvc/Model/MetaData.zep',
                  'line' => 533,
                  'char' => 20,
                ),
                1 => 
                array (
                  'variable' => 'columnMapModel',
                  'file' => '/app/phalcon/Mvc/Model/MetaData.zep',
                  'line' => 533,
                  'char' => 36,
                ),
                2 => 
                array (
                  'variable' => 'map',
                  'file' => '/app/phalcon/Mvc/Model/MetaData.zep',
                  'line' => 533,
                  'char' => 41,
                ),
              ),
              'file' => '/app/phalcon/Mvc/Model/MetaData.zep',
              'line' => 535,
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
                  'type' => 'fcall',
                  'name' => 'globals_get',
                  'call-type' => 1,
                  'parameters' => 
                  array (
                    0 => 
                    array (
                      'parameter' => 
                      array (
                        'type' => 'string',
                        'value' => 'orm.column_renaming',
                        'file' => '/app/phalcon/Mvc/Model/MetaData.zep',
                        'line' => 535,
                        'char' => 44,
                      ),
                      'file' => '/app/phalcon/Mvc/Model/MetaData.zep',
                      'line' => 535,
                      'char' => 44,
                    ),
                  ),
                  'file' => '/app/phalcon/Mvc/Model/MetaData.zep',
                  'line' => 535,
                  'char' => 46,
                ),
                'file' => '/app/phalcon/Mvc/Model/MetaData.zep',
                'line' => 535,
                'char' => 46,
              ),
              'statements' => 
              array (
                0 => 
                array (
                  'type' => 'return',
                  'expr' => 
                  array (
                    'type' => 'null',
                    'file' => '/app/phalcon/Mvc/Model/MetaData.zep',
                    'line' => 536,
                    'char' => 24,
                  ),
                  'file' => '/app/phalcon/Mvc/Model/MetaData.zep',
                  'line' => 537,
                  'char' => 9,
                ),
              ),
              'file' => '/app/phalcon/Mvc/Model/MetaData.zep',
              'line' => 539,
              'char' => 11,
            ),
            2 => 
            array (
              'type' => 'let',
              'assignments' => 
              array (
                0 => 
                array (
                  'assign-type' => 'variable',
                  'operator' => 'assign',
                  'variable' => 'keyName',
                  'expr' => 
                  array (
                    'type' => 'fcall',
                    'name' => 'get_class_lower',
                    'call-type' => 1,
                    'parameters' => 
                    array (
                      0 => 
                      array (
                        'parameter' => 
                        array (
                          'type' => 'variable',
                          'value' => 'model',
                          'file' => '/app/phalcon/Mvc/Model/MetaData.zep',
                          'line' => 539,
                          'char' => 44,
                        ),
                        'file' => '/app/phalcon/Mvc/Model/MetaData.zep',
                        'line' => 539,
                        'char' => 44,
                      ),
                    ),
                    'file' => '/app/phalcon/Mvc/Model/MetaData.zep',
                    'line' => 539,
                    'char' => 45,
                  ),
                  'file' => '/app/phalcon/Mvc/Model/MetaData.zep',
                  'line' => 539,
                  'char' => 45,
                ),
              ),
              'file' => '/app/phalcon/Mvc/Model/MetaData.zep',
              'line' => 541,
              'char' => 10,
            ),
            3 => 
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
                    'value' => 'columnMapModel',
                    'file' => '/app/phalcon/Mvc/Model/MetaData.zep',
                    'line' => 541,
                    'char' => 60,
                  ),
                  'right' => 
                  array (
                    'type' => 'array-access',
                    'left' => 
                    array (
                      'type' => 'property-access',
                      'left' => 
                      array (
                        'type' => 'variable',
                        'value' => 'this',
                        'file' => '/app/phalcon/Mvc/Model/MetaData.zep',
                        'line' => 541,
                        'char' => 40,
                      ),
                      'right' => 
                      array (
                        'type' => 'variable',
                        'value' => 'columnMap',
                        'file' => '/app/phalcon/Mvc/Model/MetaData.zep',
                        'line' => 541,
                        'char' => 50,
                      ),
                      'file' => '/app/phalcon/Mvc/Model/MetaData.zep',
                      'line' => 541,
                      'char' => 50,
                    ),
                    'right' => 
                    array (
                      'type' => 'variable',
                      'value' => 'keyName',
                      'file' => '/app/phalcon/Mvc/Model/MetaData.zep',
                      'line' => 541,
                      'char' => 58,
                    ),
                    'file' => '/app/phalcon/Mvc/Model/MetaData.zep',
                    'line' => 541,
                    'char' => 60,
                  ),
                  'file' => '/app/phalcon/Mvc/Model/MetaData.zep',
                  'line' => 541,
                  'char' => 60,
                ),
                'file' => '/app/phalcon/Mvc/Model/MetaData.zep',
                'line' => 541,
                'char' => 60,
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
                      'file' => '/app/phalcon/Mvc/Model/MetaData.zep',
                      'line' => 542,
                      'char' => 18,
                    ),
                    'name' => 'initialize',
                    'call-type' => 1,
                    'parameters' => 
                    array (
                      0 => 
                      array (
                        'parameter' => 
                        array (
                          'type' => 'variable',
                          'value' => 'model',
                          'file' => '/app/phalcon/Mvc/Model/MetaData.zep',
                          'line' => 542,
                          'char' => 35,
                        ),
                        'file' => '/app/phalcon/Mvc/Model/MetaData.zep',
                        'line' => 542,
                        'char' => 35,
                      ),
                      1 => 
                      array (
                        'parameter' => 
                        array (
                          'type' => 'null',
                          'file' => '/app/phalcon/Mvc/Model/MetaData.zep',
                          'line' => 542,
                          'char' => 41,
                        ),
                        'file' => '/app/phalcon/Mvc/Model/MetaData.zep',
                        'line' => 542,
                        'char' => 41,
                      ),
                      2 => 
                      array (
                        'parameter' => 
                        array (
                          'type' => 'null',
                          'file' => '/app/phalcon/Mvc/Model/MetaData.zep',
                          'line' => 542,
                          'char' => 47,
                        ),
                        'file' => '/app/phalcon/Mvc/Model/MetaData.zep',
                        'line' => 542,
                        'char' => 47,
                      ),
                      3 => 
                      array (
                        'parameter' => 
                        array (
                          'type' => 'null',
                          'file' => '/app/phalcon/Mvc/Model/MetaData.zep',
                          'line' => 542,
                          'char' => 53,
                        ),
                        'file' => '/app/phalcon/Mvc/Model/MetaData.zep',
                        'line' => 542,
                        'char' => 53,
                      ),
                    ),
                    'file' => '/app/phalcon/Mvc/Model/MetaData.zep',
                    'line' => 542,
                    'char' => 54,
                  ),
                  'file' => '/app/phalcon/Mvc/Model/MetaData.zep',
                  'line' => 544,
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
                      'variable' => 'columnMapModel',
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
                            'file' => '/app/phalcon/Mvc/Model/MetaData.zep',
                            'line' => 544,
                            'char' => 39,
                          ),
                          'right' => 
                          array (
                            'type' => 'variable',
                            'value' => 'columnMap',
                            'file' => '/app/phalcon/Mvc/Model/MetaData.zep',
                            'line' => 544,
                            'char' => 49,
                          ),
                          'file' => '/app/phalcon/Mvc/Model/MetaData.zep',
                          'line' => 544,
                          'char' => 49,
                        ),
                        'right' => 
                        array (
                          'type' => 'variable',
                          'value' => 'keyName',
                          'file' => '/app/phalcon/Mvc/Model/MetaData.zep',
                          'line' => 544,
                          'char' => 57,
                        ),
                        'file' => '/app/phalcon/Mvc/Model/MetaData.zep',
                        'line' => 544,
                        'char' => 58,
                      ),
                      'file' => '/app/phalcon/Mvc/Model/MetaData.zep',
                      'line' => 544,
                      'char' => 58,
                    ),
                  ),
                  'file' => '/app/phalcon/Mvc/Model/MetaData.zep',
                  'line' => 545,
                  'char' => 9,
                ),
              ),
              'file' => '/app/phalcon/Mvc/Model/MetaData.zep',
              'line' => 547,
              'char' => 13,
            ),
            4 => 
            array (
              'type' => 'fetch',
              'expr' => 
              array (
                'type' => 'fetch',
                'left' => 
                array (
                  'type' => 'variable',
                  'value' => 'map',
                  'file' => '/app/phalcon/Mvc/Model/MetaData.zep',
                  'line' => 547,
                  'char' => 41,
                ),
                'right' => 
                array (
                  'type' => 'array-access',
                  'left' => 
                  array (
                    'type' => 'variable',
                    'value' => 'columnMapModel',
                    'file' => '/app/phalcon/Mvc/Model/MetaData.zep',
                    'line' => 547,
                    'char' => 34,
                  ),
                  'right' => 
                  array (
                    'type' => 'variable',
                    'value' => 'index',
                    'file' => '/app/phalcon/Mvc/Model/MetaData.zep',
                    'line' => 547,
                    'char' => 40,
                  ),
                  'file' => '/app/phalcon/Mvc/Model/MetaData.zep',
                  'line' => 547,
                  'char' => 41,
                ),
                'file' => '/app/phalcon/Mvc/Model/MetaData.zep',
                'line' => 547,
                'char' => 41,
              ),
              'file' => '/app/phalcon/Mvc/Model/MetaData.zep',
              'line' => 549,
              'char' => 14,
            ),
            5 => 
            array (
              'type' => 'return',
              'expr' => 
              array (
                'type' => 'variable',
                'value' => 'map',
                'file' => '/app/phalcon/Mvc/Model/MetaData.zep',
                'line' => 549,
                'char' => 19,
              ),
              'file' => '/app/phalcon/Mvc/Model/MetaData.zep',
              'line' => 550,
              'char' => 5,
            ),
          ),
          'docblock' => '**
     * Reads column-map information for certain model using a MODEL_* constant
     *
     *```php
     * print_r(
     *     $metaData->readColumnMapIndex(
     *         new Robots(),
     *         MetaData::MODELS_REVERSE_COLUMN_MAP
     *     )
     * );
     *```
     *',
          'file' => '/app/phalcon/Mvc/Model/MetaData.zep',
          'line' => 531,
          'last-line' => 562,
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
          'name' => 'readMetaData',
          'parameters' => 
          array (
            0 => 
            array (
              'type' => 'parameter',
              'name' => 'model',
              'const' => 0,
              'data-type' => 'variable',
              'mandatory' => 0,
              'cast' => 
              array (
                'type' => 'variable',
                'value' => 'ModelInterface',
                'file' => '/app/phalcon/Mvc/Model/MetaData.zep',
                'line' => 563,
                'char' => 61,
              ),
              'reference' => 0,
              'file' => '/app/phalcon/Mvc/Model/MetaData.zep',
              'line' => 563,
              'char' => 62,
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
                  'variable' => 'source',
                  'file' => '/app/phalcon/Mvc/Model/MetaData.zep',
                  'line' => 565,
                  'char' => 19,
                ),
                1 => 
                array (
                  'variable' => 'schema',
                  'file' => '/app/phalcon/Mvc/Model/MetaData.zep',
                  'line' => 565,
                  'char' => 27,
                ),
              ),
              'file' => '/app/phalcon/Mvc/Model/MetaData.zep',
              'line' => 566,
              'char' => 14,
            ),
            1 => 
            array (
              'type' => 'declare',
              'data-type' => 'string',
              'variables' => 
              array (
                0 => 
                array (
                  'variable' => 'key',
                  'file' => '/app/phalcon/Mvc/Model/MetaData.zep',
                  'line' => 566,
                  'char' => 19,
                ),
              ),
              'file' => '/app/phalcon/Mvc/Model/MetaData.zep',
              'line' => 568,
              'char' => 11,
            ),
            2 => 
            array (
              'type' => 'let',
              'assignments' => 
              array (
                0 => 
                array (
                  'assign-type' => 'variable',
                  'operator' => 'assign',
                  'variable' => 'source',
                  'expr' => 
                  array (
                    'type' => 'mcall',
                    'variable' => 
                    array (
                      'type' => 'variable',
                      'value' => 'model',
                      'file' => '/app/phalcon/Mvc/Model/MetaData.zep',
                      'line' => 568,
                      'char' => 28,
                    ),
                    'name' => 'getSource',
                    'call-type' => 1,
                    'file' => '/app/phalcon/Mvc/Model/MetaData.zep',
                    'line' => 568,
                    'char' => 40,
                  ),
                  'file' => '/app/phalcon/Mvc/Model/MetaData.zep',
                  'line' => 568,
                  'char' => 40,
                ),
                1 => 
                array (
                  'assign-type' => 'variable',
                  'operator' => 'assign',
                  'variable' => 'schema',
                  'expr' => 
                  array (
                    'type' => 'mcall',
                    'variable' => 
                    array (
                      'type' => 'variable',
                      'value' => 'model',
                      'file' => '/app/phalcon/Mvc/Model/MetaData.zep',
                      'line' => 569,
                      'char' => 28,
                    ),
                    'name' => 'getSchema',
                    'call-type' => 1,
                    'file' => '/app/phalcon/Mvc/Model/MetaData.zep',
                    'line' => 569,
                    'char' => 40,
                  ),
                  'file' => '/app/phalcon/Mvc/Model/MetaData.zep',
                  'line' => 569,
                  'char' => 40,
                ),
              ),
              'file' => '/app/phalcon/Mvc/Model/MetaData.zep',
              'line' => 574,
              'char' => 11,
            ),
            3 => 
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
                    'type' => 'concat',
                    'left' => 
                    array (
                      'type' => 'concat',
                      'left' => 
                      array (
                        'type' => 'concat',
                        'left' => 
                        array (
                          'type' => 'fcall',
                          'name' => 'get_class_lower',
                          'call-type' => 1,
                          'parameters' => 
                          array (
                            0 => 
                            array (
                              'parameter' => 
                              array (
                                'type' => 'variable',
                                'value' => 'model',
                                'file' => '/app/phalcon/Mvc/Model/MetaData.zep',
                                'line' => 574,
                                'char' => 40,
                              ),
                              'file' => '/app/phalcon/Mvc/Model/MetaData.zep',
                              'line' => 574,
                              'char' => 40,
                            ),
                          ),
                          'file' => '/app/phalcon/Mvc/Model/MetaData.zep',
                          'line' => 574,
                          'char' => 42,
                        ),
                        'right' => 
                        array (
                          'type' => 'string',
                          'value' => '-',
                          'file' => '/app/phalcon/Mvc/Model/MetaData.zep',
                          'line' => 574,
                          'char' => 46,
                        ),
                        'file' => '/app/phalcon/Mvc/Model/MetaData.zep',
                        'line' => 574,
                        'char' => 46,
                      ),
                      'right' => 
                      array (
                        'type' => 'variable',
                        'value' => 'schema',
                        'file' => '/app/phalcon/Mvc/Model/MetaData.zep',
                        'line' => 574,
                        'char' => 55,
                      ),
                      'file' => '/app/phalcon/Mvc/Model/MetaData.zep',
                      'line' => 574,
                      'char' => 55,
                    ),
                    'right' => 
                    array (
                      'type' => 'variable',
                      'value' => 'source',
                      'file' => '/app/phalcon/Mvc/Model/MetaData.zep',
                      'line' => 574,
                      'char' => 63,
                    ),
                    'file' => '/app/phalcon/Mvc/Model/MetaData.zep',
                    'line' => 574,
                    'char' => 63,
                  ),
                  'file' => '/app/phalcon/Mvc/Model/MetaData.zep',
                  'line' => 574,
                  'char' => 63,
                ),
              ),
              'file' => '/app/phalcon/Mvc/Model/MetaData.zep',
              'line' => 576,
              'char' => 10,
            ),
            4 => 
            array (
              'type' => 'if',
              'expr' => 
              array (
                'type' => 'not',
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
                        'file' => '/app/phalcon/Mvc/Model/MetaData.zep',
                        'line' => 576,
                        'char' => 24,
                      ),
                      'right' => 
                      array (
                        'type' => 'variable',
                        'value' => 'metaData',
                        'file' => '/app/phalcon/Mvc/Model/MetaData.zep',
                        'line' => 576,
                        'char' => 33,
                      ),
                      'file' => '/app/phalcon/Mvc/Model/MetaData.zep',
                      'line' => 576,
                      'char' => 33,
                    ),
                    'right' => 
                    array (
                      'type' => 'variable',
                      'value' => 'key',
                      'file' => '/app/phalcon/Mvc/Model/MetaData.zep',
                      'line' => 576,
                      'char' => 37,
                    ),
                    'file' => '/app/phalcon/Mvc/Model/MetaData.zep',
                    'line' => 576,
                    'char' => 39,
                  ),
                  'file' => '/app/phalcon/Mvc/Model/MetaData.zep',
                  'line' => 576,
                  'char' => 39,
                ),
                'file' => '/app/phalcon/Mvc/Model/MetaData.zep',
                'line' => 576,
                'char' => 39,
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
                      'file' => '/app/phalcon/Mvc/Model/MetaData.zep',
                      'line' => 577,
                      'char' => 18,
                    ),
                    'name' => 'initialize',
                    'call-type' => 1,
                    'parameters' => 
                    array (
                      0 => 
                      array (
                        'parameter' => 
                        array (
                          'type' => 'variable',
                          'value' => 'model',
                          'file' => '/app/phalcon/Mvc/Model/MetaData.zep',
                          'line' => 577,
                          'char' => 35,
                        ),
                        'file' => '/app/phalcon/Mvc/Model/MetaData.zep',
                        'line' => 577,
                        'char' => 35,
                      ),
                      1 => 
                      array (
                        'parameter' => 
                        array (
                          'type' => 'variable',
                          'value' => 'key',
                          'file' => '/app/phalcon/Mvc/Model/MetaData.zep',
                          'line' => 577,
                          'char' => 40,
                        ),
                        'file' => '/app/phalcon/Mvc/Model/MetaData.zep',
                        'line' => 577,
                        'char' => 40,
                      ),
                      2 => 
                      array (
                        'parameter' => 
                        array (
                          'type' => 'variable',
                          'value' => 'source',
                          'file' => '/app/phalcon/Mvc/Model/MetaData.zep',
                          'line' => 577,
                          'char' => 48,
                        ),
                        'file' => '/app/phalcon/Mvc/Model/MetaData.zep',
                        'line' => 577,
                        'char' => 48,
                      ),
                      3 => 
                      array (
                        'parameter' => 
                        array (
                          'type' => 'variable',
                          'value' => 'schema',
                          'file' => '/app/phalcon/Mvc/Model/MetaData.zep',
                          'line' => 577,
                          'char' => 56,
                        ),
                        'file' => '/app/phalcon/Mvc/Model/MetaData.zep',
                        'line' => 577,
                        'char' => 56,
                      ),
                    ),
                    'file' => '/app/phalcon/Mvc/Model/MetaData.zep',
                    'line' => 577,
                    'char' => 57,
                  ),
                  'file' => '/app/phalcon/Mvc/Model/MetaData.zep',
                  'line' => 578,
                  'char' => 9,
                ),
              ),
              'file' => '/app/phalcon/Mvc/Model/MetaData.zep',
              'line' => 580,
              'char' => 14,
            ),
            5 => 
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
                    'file' => '/app/phalcon/Mvc/Model/MetaData.zep',
                    'line' => 580,
                    'char' => 21,
                  ),
                  'right' => 
                  array (
                    'type' => 'variable',
                    'value' => 'metaData',
                    'file' => '/app/phalcon/Mvc/Model/MetaData.zep',
                    'line' => 580,
                    'char' => 30,
                  ),
                  'file' => '/app/phalcon/Mvc/Model/MetaData.zep',
                  'line' => 580,
                  'char' => 30,
                ),
                'right' => 
                array (
                  'type' => 'variable',
                  'value' => 'key',
                  'file' => '/app/phalcon/Mvc/Model/MetaData.zep',
                  'line' => 580,
                  'char' => 34,
                ),
                'file' => '/app/phalcon/Mvc/Model/MetaData.zep',
                'line' => 580,
                'char' => 35,
              ),
              'file' => '/app/phalcon/Mvc/Model/MetaData.zep',
              'line' => 581,
              'char' => 5,
            ),
          ),
          'docblock' => '**
     * Reads the complete meta-data for certain model
     *
     *```php
     * print_r(
     *     $metaData->readMetaData(
     *         new Robots()
     *     )
     * );
     *```
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
                'file' => '/app/phalcon/Mvc/Model/MetaData.zep',
                'line' => 564,
                'char' => 5,
              ),
            ),
            'void' => 0,
            'file' => '/app/phalcon/Mvc/Model/MetaData.zep',
            'line' => 564,
            'char' => 5,
          ),
          'file' => '/app/phalcon/Mvc/Model/MetaData.zep',
          'line' => 563,
          'last-line' => 594,
          'char' => 25,
        ),
        22 => 
        array (
          'visibility' => 
          array (
            0 => 'final',
            1 => 'public',
          ),
          'type' => 'method',
          'name' => 'readMetaDataIndex',
          'parameters' => 
          array (
            0 => 
            array (
              'type' => 'parameter',
              'name' => 'model',
              'const' => 0,
              'data-type' => 'variable',
              'mandatory' => 0,
              'cast' => 
              array (
                'type' => 'variable',
                'value' => 'ModelInterface',
                'file' => '/app/phalcon/Mvc/Model/MetaData.zep',
                'line' => 595,
                'char' => 66,
              ),
              'reference' => 0,
              'file' => '/app/phalcon/Mvc/Model/MetaData.zep',
              'line' => 595,
              'char' => 67,
            ),
            1 => 
            array (
              'type' => 'parameter',
              'name' => 'index',
              'const' => 0,
              'data-type' => 'int',
              'mandatory' => 0,
              'reference' => 0,
              'file' => '/app/phalcon/Mvc/Model/MetaData.zep',
              'line' => 595,
              'char' => 78,
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
                  'variable' => 'source',
                  'file' => '/app/phalcon/Mvc/Model/MetaData.zep',
                  'line' => 597,
                  'char' => 19,
                ),
                1 => 
                array (
                  'variable' => 'schema',
                  'file' => '/app/phalcon/Mvc/Model/MetaData.zep',
                  'line' => 597,
                  'char' => 27,
                ),
              ),
              'file' => '/app/phalcon/Mvc/Model/MetaData.zep',
              'line' => 598,
              'char' => 14,
            ),
            1 => 
            array (
              'type' => 'declare',
              'data-type' => 'string',
              'variables' => 
              array (
                0 => 
                array (
                  'variable' => 'key',
                  'file' => '/app/phalcon/Mvc/Model/MetaData.zep',
                  'line' => 598,
                  'char' => 19,
                ),
              ),
              'file' => '/app/phalcon/Mvc/Model/MetaData.zep',
              'line' => 600,
              'char' => 11,
            ),
            2 => 
            array (
              'type' => 'let',
              'assignments' => 
              array (
                0 => 
                array (
                  'assign-type' => 'variable',
                  'operator' => 'assign',
                  'variable' => 'source',
                  'expr' => 
                  array (
                    'type' => 'mcall',
                    'variable' => 
                    array (
                      'type' => 'variable',
                      'value' => 'model',
                      'file' => '/app/phalcon/Mvc/Model/MetaData.zep',
                      'line' => 600,
                      'char' => 28,
                    ),
                    'name' => 'getSource',
                    'call-type' => 1,
                    'file' => '/app/phalcon/Mvc/Model/MetaData.zep',
                    'line' => 600,
                    'char' => 40,
                  ),
                  'file' => '/app/phalcon/Mvc/Model/MetaData.zep',
                  'line' => 600,
                  'char' => 40,
                ),
                1 => 
                array (
                  'assign-type' => 'variable',
                  'operator' => 'assign',
                  'variable' => 'schema',
                  'expr' => 
                  array (
                    'type' => 'mcall',
                    'variable' => 
                    array (
                      'type' => 'variable',
                      'value' => 'model',
                      'file' => '/app/phalcon/Mvc/Model/MetaData.zep',
                      'line' => 601,
                      'char' => 28,
                    ),
                    'name' => 'getSchema',
                    'call-type' => 1,
                    'file' => '/app/phalcon/Mvc/Model/MetaData.zep',
                    'line' => 601,
                    'char' => 40,
                  ),
                  'file' => '/app/phalcon/Mvc/Model/MetaData.zep',
                  'line' => 601,
                  'char' => 40,
                ),
              ),
              'file' => '/app/phalcon/Mvc/Model/MetaData.zep',
              'line' => 606,
              'char' => 11,
            ),
            3 => 
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
                    'type' => 'concat',
                    'left' => 
                    array (
                      'type' => 'concat',
                      'left' => 
                      array (
                        'type' => 'concat',
                        'left' => 
                        array (
                          'type' => 'fcall',
                          'name' => 'get_class_lower',
                          'call-type' => 1,
                          'parameters' => 
                          array (
                            0 => 
                            array (
                              'parameter' => 
                              array (
                                'type' => 'variable',
                                'value' => 'model',
                                'file' => '/app/phalcon/Mvc/Model/MetaData.zep',
                                'line' => 606,
                                'char' => 40,
                              ),
                              'file' => '/app/phalcon/Mvc/Model/MetaData.zep',
                              'line' => 606,
                              'char' => 40,
                            ),
                          ),
                          'file' => '/app/phalcon/Mvc/Model/MetaData.zep',
                          'line' => 606,
                          'char' => 42,
                        ),
                        'right' => 
                        array (
                          'type' => 'string',
                          'value' => '-',
                          'file' => '/app/phalcon/Mvc/Model/MetaData.zep',
                          'line' => 606,
                          'char' => 46,
                        ),
                        'file' => '/app/phalcon/Mvc/Model/MetaData.zep',
                        'line' => 606,
                        'char' => 46,
                      ),
                      'right' => 
                      array (
                        'type' => 'variable',
                        'value' => 'schema',
                        'file' => '/app/phalcon/Mvc/Model/MetaData.zep',
                        'line' => 606,
                        'char' => 55,
                      ),
                      'file' => '/app/phalcon/Mvc/Model/MetaData.zep',
                      'line' => 606,
                      'char' => 55,
                    ),
                    'right' => 
                    array (
                      'type' => 'variable',
                      'value' => 'source',
                      'file' => '/app/phalcon/Mvc/Model/MetaData.zep',
                      'line' => 606,
                      'char' => 63,
                    ),
                    'file' => '/app/phalcon/Mvc/Model/MetaData.zep',
                    'line' => 606,
                    'char' => 63,
                  ),
                  'file' => '/app/phalcon/Mvc/Model/MetaData.zep',
                  'line' => 606,
                  'char' => 63,
                ),
              ),
              'file' => '/app/phalcon/Mvc/Model/MetaData.zep',
              'line' => 608,
              'char' => 10,
            ),
            4 => 
            array (
              'type' => 'if',
              'expr' => 
              array (
                'type' => 'not',
                'left' => 
                array (
                  'type' => 'isset',
                  'left' => 
                  array (
                    'type' => 'array-access',
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
                          'file' => '/app/phalcon/Mvc/Model/MetaData.zep',
                          'line' => 608,
                          'char' => 24,
                        ),
                        'right' => 
                        array (
                          'type' => 'variable',
                          'value' => 'metaData',
                          'file' => '/app/phalcon/Mvc/Model/MetaData.zep',
                          'line' => 608,
                          'char' => 33,
                        ),
                        'file' => '/app/phalcon/Mvc/Model/MetaData.zep',
                        'line' => 608,
                        'char' => 33,
                      ),
                      'right' => 
                      array (
                        'type' => 'variable',
                        'value' => 'key',
                        'file' => '/app/phalcon/Mvc/Model/MetaData.zep',
                        'line' => 608,
                        'char' => 37,
                      ),
                      'file' => '/app/phalcon/Mvc/Model/MetaData.zep',
                      'line' => 608,
                      'char' => 38,
                    ),
                    'right' => 
                    array (
                      'type' => 'variable',
                      'value' => 'index',
                      'file' => '/app/phalcon/Mvc/Model/MetaData.zep',
                      'line' => 608,
                      'char' => 44,
                    ),
                    'file' => '/app/phalcon/Mvc/Model/MetaData.zep',
                    'line' => 608,
                    'char' => 46,
                  ),
                  'file' => '/app/phalcon/Mvc/Model/MetaData.zep',
                  'line' => 608,
                  'char' => 46,
                ),
                'file' => '/app/phalcon/Mvc/Model/MetaData.zep',
                'line' => 608,
                'char' => 46,
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
                      'file' => '/app/phalcon/Mvc/Model/MetaData.zep',
                      'line' => 609,
                      'char' => 18,
                    ),
                    'name' => 'initialize',
                    'call-type' => 1,
                    'parameters' => 
                    array (
                      0 => 
                      array (
                        'parameter' => 
                        array (
                          'type' => 'variable',
                          'value' => 'model',
                          'file' => '/app/phalcon/Mvc/Model/MetaData.zep',
                          'line' => 609,
                          'char' => 35,
                        ),
                        'file' => '/app/phalcon/Mvc/Model/MetaData.zep',
                        'line' => 609,
                        'char' => 35,
                      ),
                      1 => 
                      array (
                        'parameter' => 
                        array (
                          'type' => 'variable',
                          'value' => 'key',
                          'file' => '/app/phalcon/Mvc/Model/MetaData.zep',
                          'line' => 609,
                          'char' => 40,
                        ),
                        'file' => '/app/phalcon/Mvc/Model/MetaData.zep',
                        'line' => 609,
                        'char' => 40,
                      ),
                      2 => 
                      array (
                        'parameter' => 
                        array (
                          'type' => 'variable',
                          'value' => 'source',
                          'file' => '/app/phalcon/Mvc/Model/MetaData.zep',
                          'line' => 609,
                          'char' => 48,
                        ),
                        'file' => '/app/phalcon/Mvc/Model/MetaData.zep',
                        'line' => 609,
                        'char' => 48,
                      ),
                      3 => 
                      array (
                        'parameter' => 
                        array (
                          'type' => 'variable',
                          'value' => 'schema',
                          'file' => '/app/phalcon/Mvc/Model/MetaData.zep',
                          'line' => 609,
                          'char' => 56,
                        ),
                        'file' => '/app/phalcon/Mvc/Model/MetaData.zep',
                        'line' => 609,
                        'char' => 56,
                      ),
                    ),
                    'file' => '/app/phalcon/Mvc/Model/MetaData.zep',
                    'line' => 609,
                    'char' => 57,
                  ),
                  'file' => '/app/phalcon/Mvc/Model/MetaData.zep',
                  'line' => 610,
                  'char' => 9,
                ),
              ),
              'file' => '/app/phalcon/Mvc/Model/MetaData.zep',
              'line' => 612,
              'char' => 14,
            ),
            5 => 
            array (
              'type' => 'return',
              'expr' => 
              array (
                'type' => 'array-access',
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
                      'file' => '/app/phalcon/Mvc/Model/MetaData.zep',
                      'line' => 612,
                      'char' => 21,
                    ),
                    'right' => 
                    array (
                      'type' => 'variable',
                      'value' => 'metaData',
                      'file' => '/app/phalcon/Mvc/Model/MetaData.zep',
                      'line' => 612,
                      'char' => 30,
                    ),
                    'file' => '/app/phalcon/Mvc/Model/MetaData.zep',
                    'line' => 612,
                    'char' => 30,
                  ),
                  'right' => 
                  array (
                    'type' => 'variable',
                    'value' => 'key',
                    'file' => '/app/phalcon/Mvc/Model/MetaData.zep',
                    'line' => 612,
                    'char' => 34,
                  ),
                  'file' => '/app/phalcon/Mvc/Model/MetaData.zep',
                  'line' => 612,
                  'char' => 35,
                ),
                'right' => 
                array (
                  'type' => 'variable',
                  'value' => 'index',
                  'file' => '/app/phalcon/Mvc/Model/MetaData.zep',
                  'line' => 612,
                  'char' => 41,
                ),
                'file' => '/app/phalcon/Mvc/Model/MetaData.zep',
                'line' => 612,
                'char' => 42,
              ),
              'file' => '/app/phalcon/Mvc/Model/MetaData.zep',
              'line' => 613,
              'char' => 5,
            ),
          ),
          'docblock' => '**
     * Reads meta-data for certain model
     *
     *```php
     * print_r(
     *     $metaData->readMetaDataIndex(
     *         new Robots(),
     *         0
     *     )
     * );
     *```
     *',
          'file' => '/app/phalcon/Mvc/Model/MetaData.zep',
          'line' => 595,
          'last-line' => 621,
          'char' => 25,
        ),
        23 => 
        array (
          'visibility' => 
          array (
            0 => 'public',
          ),
          'type' => 'method',
          'name' => 'reset',
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
                  'property' => 'metaData',
                  'expr' => 
                  array (
                    'type' => 'empty-array',
                    'file' => '/app/phalcon/Mvc/Model/MetaData.zep',
                    'line' => 624,
                    'char' => 32,
                  ),
                  'file' => '/app/phalcon/Mvc/Model/MetaData.zep',
                  'line' => 624,
                  'char' => 32,
                ),
                1 => 
                array (
                  'assign-type' => 'object-property',
                  'operator' => 'assign',
                  'variable' => 'this',
                  'property' => 'columnMap',
                  'expr' => 
                  array (
                    'type' => 'empty-array',
                    'file' => '/app/phalcon/Mvc/Model/MetaData.zep',
                    'line' => 625,
                    'char' => 33,
                  ),
                  'file' => '/app/phalcon/Mvc/Model/MetaData.zep',
                  'line' => 625,
                  'char' => 33,
                ),
              ),
              'file' => '/app/phalcon/Mvc/Model/MetaData.zep',
              'line' => 626,
              'char' => 5,
            ),
          ),
          'docblock' => '**
     * Resets internal meta-data in order to regenerate it
     *
     *```php
     * $metaData->reset();
     *```
     *',
          'return-type' => 
          array (
            'type' => 'return-type',
            'void' => 1,
            'file' => '/app/phalcon/Mvc/Model/MetaData.zep',
            'line' => 623,
            'char' => 5,
          ),
          'file' => '/app/phalcon/Mvc/Model/MetaData.zep',
          'line' => 622,
          'last-line' => 639,
          'char' => 19,
        ),
        24 => 
        array (
          'visibility' => 
          array (
            0 => 'public',
          ),
          'type' => 'method',
          'name' => 'setAutomaticCreateAttributes',
          'parameters' => 
          array (
            0 => 
            array (
              'type' => 'parameter',
              'name' => 'model',
              'const' => 0,
              'data-type' => 'variable',
              'mandatory' => 0,
              'cast' => 
              array (
                'type' => 'variable',
                'value' => 'ModelInterface',
                'file' => '/app/phalcon/Mvc/Model/MetaData.zep',
                'line' => 640,
                'char' => 71,
              ),
              'reference' => 0,
              'file' => '/app/phalcon/Mvc/Model/MetaData.zep',
              'line' => 640,
              'char' => 72,
            ),
            1 => 
            array (
              'type' => 'parameter',
              'name' => 'attributes',
              'const' => 0,
              'data-type' => 'array',
              'mandatory' => 0,
              'reference' => 0,
              'file' => '/app/phalcon/Mvc/Model/MetaData.zep',
              'line' => 640,
              'char' => 90,
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
                  'file' => '/app/phalcon/Mvc/Model/MetaData.zep',
                  'line' => 642,
                  'char' => 14,
                ),
                'name' => 'writeMetaDataIndex',
                'call-type' => 1,
                'parameters' => 
                array (
                  0 => 
                  array (
                    'parameter' => 
                    array (
                      'type' => 'variable',
                      'value' => 'model',
                      'file' => '/app/phalcon/Mvc/Model/MetaData.zep',
                      'line' => 643,
                      'char' => 18,
                    ),
                    'file' => '/app/phalcon/Mvc/Model/MetaData.zep',
                    'line' => 643,
                    'char' => 18,
                  ),
                  1 => 
                  array (
                    'parameter' => 
                    array (
                      'type' => 'static-constant-access',
                      'left' => 
                      array (
                        'type' => 'variable',
                        'value' => 'self',
                        'file' => '/app/phalcon/Mvc/Model/MetaData.zep',
                        'line' => 644,
                        'char' => 50,
                      ),
                      'right' => 
                      array (
                        'type' => 'variable',
                        'value' => 'MODELS_AUTOMATIC_DEFAULT_INSERT',
                        'file' => '/app/phalcon/Mvc/Model/MetaData.zep',
                        'line' => 644,
                        'char' => 50,
                      ),
                      'file' => '/app/phalcon/Mvc/Model/MetaData.zep',
                      'line' => 644,
                      'char' => 50,
                    ),
                    'file' => '/app/phalcon/Mvc/Model/MetaData.zep',
                    'line' => 644,
                    'char' => 50,
                  ),
                  2 => 
                  array (
                    'parameter' => 
                    array (
                      'type' => 'variable',
                      'value' => 'attributes',
                      'file' => '/app/phalcon/Mvc/Model/MetaData.zep',
                      'line' => 646,
                      'char' => 9,
                    ),
                    'file' => '/app/phalcon/Mvc/Model/MetaData.zep',
                    'line' => 646,
                    'char' => 9,
                  ),
                ),
                'file' => '/app/phalcon/Mvc/Model/MetaData.zep',
                'line' => 646,
                'char' => 10,
              ),
              'file' => '/app/phalcon/Mvc/Model/MetaData.zep',
              'line' => 647,
              'char' => 5,
            ),
          ),
          'docblock' => '**
     * Set the attributes that must be ignored from the INSERT SQL generation
     *
     *```php
     * $metaData->setAutomaticCreateAttributes(
     *     new Robots(),
     *     [
     *         "created_at" => true,
     *     ]
     * );
     *```
     *',
          'return-type' => 
          array (
            'type' => 'return-type',
            'void' => 1,
            'file' => '/app/phalcon/Mvc/Model/MetaData.zep',
            'line' => 641,
            'char' => 5,
          ),
          'file' => '/app/phalcon/Mvc/Model/MetaData.zep',
          'line' => 640,
          'last-line' => 660,
          'char' => 19,
        ),
        25 => 
        array (
          'visibility' => 
          array (
            0 => 'public',
          ),
          'type' => 'method',
          'name' => 'setAutomaticUpdateAttributes',
          'parameters' => 
          array (
            0 => 
            array (
              'type' => 'parameter',
              'name' => 'model',
              'const' => 0,
              'data-type' => 'variable',
              'mandatory' => 0,
              'cast' => 
              array (
                'type' => 'variable',
                'value' => 'ModelInterface',
                'file' => '/app/phalcon/Mvc/Model/MetaData.zep',
                'line' => 661,
                'char' => 71,
              ),
              'reference' => 0,
              'file' => '/app/phalcon/Mvc/Model/MetaData.zep',
              'line' => 661,
              'char' => 72,
            ),
            1 => 
            array (
              'type' => 'parameter',
              'name' => 'attributes',
              'const' => 0,
              'data-type' => 'array',
              'mandatory' => 0,
              'reference' => 0,
              'file' => '/app/phalcon/Mvc/Model/MetaData.zep',
              'line' => 661,
              'char' => 90,
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
                  'file' => '/app/phalcon/Mvc/Model/MetaData.zep',
                  'line' => 663,
                  'char' => 14,
                ),
                'name' => 'writeMetaDataIndex',
                'call-type' => 1,
                'parameters' => 
                array (
                  0 => 
                  array (
                    'parameter' => 
                    array (
                      'type' => 'variable',
                      'value' => 'model',
                      'file' => '/app/phalcon/Mvc/Model/MetaData.zep',
                      'line' => 664,
                      'char' => 18,
                    ),
                    'file' => '/app/phalcon/Mvc/Model/MetaData.zep',
                    'line' => 664,
                    'char' => 18,
                  ),
                  1 => 
                  array (
                    'parameter' => 
                    array (
                      'type' => 'static-constant-access',
                      'left' => 
                      array (
                        'type' => 'variable',
                        'value' => 'self',
                        'file' => '/app/phalcon/Mvc/Model/MetaData.zep',
                        'line' => 665,
                        'char' => 50,
                      ),
                      'right' => 
                      array (
                        'type' => 'variable',
                        'value' => 'MODELS_AUTOMATIC_DEFAULT_UPDATE',
                        'file' => '/app/phalcon/Mvc/Model/MetaData.zep',
                        'line' => 665,
                        'char' => 50,
                      ),
                      'file' => '/app/phalcon/Mvc/Model/MetaData.zep',
                      'line' => 665,
                      'char' => 50,
                    ),
                    'file' => '/app/phalcon/Mvc/Model/MetaData.zep',
                    'line' => 665,
                    'char' => 50,
                  ),
                  2 => 
                  array (
                    'parameter' => 
                    array (
                      'type' => 'variable',
                      'value' => 'attributes',
                      'file' => '/app/phalcon/Mvc/Model/MetaData.zep',
                      'line' => 667,
                      'char' => 9,
                    ),
                    'file' => '/app/phalcon/Mvc/Model/MetaData.zep',
                    'line' => 667,
                    'char' => 9,
                  ),
                ),
                'file' => '/app/phalcon/Mvc/Model/MetaData.zep',
                'line' => 667,
                'char' => 10,
              ),
              'file' => '/app/phalcon/Mvc/Model/MetaData.zep',
              'line' => 668,
              'char' => 5,
            ),
          ),
          'docblock' => '**
     * Set the attributes that must be ignored from the UPDATE SQL generation
     *
     *```php
     * $metaData->setAutomaticUpdateAttributes(
     *     new Robots(),
     *     [
     *         "modified_at" => true,
     *     ]
     * );
     *```
     *',
          'return-type' => 
          array (
            'type' => 'return-type',
            'void' => 1,
            'file' => '/app/phalcon/Mvc/Model/MetaData.zep',
            'line' => 662,
            'char' => 5,
          ),
          'file' => '/app/phalcon/Mvc/Model/MetaData.zep',
          'line' => 661,
          'last-line' => 681,
          'char' => 19,
        ),
        26 => 
        array (
          'visibility' => 
          array (
            0 => 'public',
          ),
          'type' => 'method',
          'name' => 'setEmptyStringAttributes',
          'parameters' => 
          array (
            0 => 
            array (
              'type' => 'parameter',
              'name' => 'model',
              'const' => 0,
              'data-type' => 'variable',
              'mandatory' => 0,
              'cast' => 
              array (
                'type' => 'variable',
                'value' => 'ModelInterface',
                'file' => '/app/phalcon/Mvc/Model/MetaData.zep',
                'line' => 682,
                'char' => 67,
              ),
              'reference' => 0,
              'file' => '/app/phalcon/Mvc/Model/MetaData.zep',
              'line' => 682,
              'char' => 68,
            ),
            1 => 
            array (
              'type' => 'parameter',
              'name' => 'attributes',
              'const' => 0,
              'data-type' => 'array',
              'mandatory' => 0,
              'reference' => 0,
              'file' => '/app/phalcon/Mvc/Model/MetaData.zep',
              'line' => 682,
              'char' => 86,
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
                  'file' => '/app/phalcon/Mvc/Model/MetaData.zep',
                  'line' => 684,
                  'char' => 14,
                ),
                'name' => 'writeMetaDataIndex',
                'call-type' => 1,
                'parameters' => 
                array (
                  0 => 
                  array (
                    'parameter' => 
                    array (
                      'type' => 'variable',
                      'value' => 'model',
                      'file' => '/app/phalcon/Mvc/Model/MetaData.zep',
                      'line' => 685,
                      'char' => 18,
                    ),
                    'file' => '/app/phalcon/Mvc/Model/MetaData.zep',
                    'line' => 685,
                    'char' => 18,
                  ),
                  1 => 
                  array (
                    'parameter' => 
                    array (
                      'type' => 'static-constant-access',
                      'left' => 
                      array (
                        'type' => 'variable',
                        'value' => 'self',
                        'file' => '/app/phalcon/Mvc/Model/MetaData.zep',
                        'line' => 686,
                        'char' => 45,
                      ),
                      'right' => 
                      array (
                        'type' => 'variable',
                        'value' => 'MODELS_EMPTY_STRING_VALUES',
                        'file' => '/app/phalcon/Mvc/Model/MetaData.zep',
                        'line' => 686,
                        'char' => 45,
                      ),
                      'file' => '/app/phalcon/Mvc/Model/MetaData.zep',
                      'line' => 686,
                      'char' => 45,
                    ),
                    'file' => '/app/phalcon/Mvc/Model/MetaData.zep',
                    'line' => 686,
                    'char' => 45,
                  ),
                  2 => 
                  array (
                    'parameter' => 
                    array (
                      'type' => 'variable',
                      'value' => 'attributes',
                      'file' => '/app/phalcon/Mvc/Model/MetaData.zep',
                      'line' => 688,
                      'char' => 9,
                    ),
                    'file' => '/app/phalcon/Mvc/Model/MetaData.zep',
                    'line' => 688,
                    'char' => 9,
                  ),
                ),
                'file' => '/app/phalcon/Mvc/Model/MetaData.zep',
                'line' => 688,
                'char' => 10,
              ),
              'file' => '/app/phalcon/Mvc/Model/MetaData.zep',
              'line' => 689,
              'char' => 5,
            ),
          ),
          'docblock' => '**
     * Set the attributes that allow empty string values
     *
     *```php
     * $metaData->setEmptyStringAttributes(
     *     new Robots(),
     *     [
     *         "name" => true,
     *     ]
     * );
     *```
     *',
          'return-type' => 
          array (
            'type' => 'return-type',
            'void' => 1,
            'file' => '/app/phalcon/Mvc/Model/MetaData.zep',
            'line' => 683,
            'char' => 5,
          ),
          'file' => '/app/phalcon/Mvc/Model/MetaData.zep',
          'line' => 682,
          'last-line' => 693,
          'char' => 19,
        ),
        27 => 
        array (
          'visibility' => 
          array (
            0 => 'public',
          ),
          'type' => 'method',
          'name' => 'setDI',
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
                'file' => '/app/phalcon/Mvc/Model/MetaData.zep',
                'line' => 694,
                'char' => 49,
              ),
              'reference' => 0,
              'file' => '/app/phalcon/Mvc/Model/MetaData.zep',
              'line' => 694,
              'char' => 50,
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
                  'property' => 'container',
                  'expr' => 
                  array (
                    'type' => 'variable',
                    'value' => 'container',
                    'file' => '/app/phalcon/Mvc/Model/MetaData.zep',
                    'line' => 696,
                    'char' => 40,
                  ),
                  'file' => '/app/phalcon/Mvc/Model/MetaData.zep',
                  'line' => 696,
                  'char' => 40,
                ),
              ),
              'file' => '/app/phalcon/Mvc/Model/MetaData.zep',
              'line' => 697,
              'char' => 5,
            ),
          ),
          'docblock' => '**
     * Sets the DependencyInjector container
     *',
          'return-type' => 
          array (
            'type' => 'return-type',
            'void' => 1,
            'file' => '/app/phalcon/Mvc/Model/MetaData.zep',
            'line' => 695,
            'char' => 5,
          ),
          'file' => '/app/phalcon/Mvc/Model/MetaData.zep',
          'line' => 694,
          'last-line' => 701,
          'char' => 19,
        ),
        28 => 
        array (
          'visibility' => 
          array (
            0 => 'public',
          ),
          'type' => 'method',
          'name' => 'setStrategy',
          'parameters' => 
          array (
            0 => 
            array (
              'type' => 'parameter',
              'name' => 'strategy',
              'const' => 0,
              'data-type' => 'variable',
              'mandatory' => 0,
              'cast' => 
              array (
                'type' => 'variable',
                'value' => 'StrategyInterface',
                'file' => '/app/phalcon/Mvc/Model/MetaData.zep',
                'line' => 702,
                'char' => 60,
              ),
              'reference' => 0,
              'file' => '/app/phalcon/Mvc/Model/MetaData.zep',
              'line' => 702,
              'char' => 61,
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
                  'property' => 'strategy',
                  'expr' => 
                  array (
                    'type' => 'variable',
                    'value' => 'strategy',
                    'file' => '/app/phalcon/Mvc/Model/MetaData.zep',
                    'line' => 704,
                    'char' => 38,
                  ),
                  'file' => '/app/phalcon/Mvc/Model/MetaData.zep',
                  'line' => 704,
                  'char' => 38,
                ),
              ),
              'file' => '/app/phalcon/Mvc/Model/MetaData.zep',
              'line' => 705,
              'char' => 5,
            ),
          ),
          'docblock' => '**
     * Set the meta-data extraction strategy
     *',
          'return-type' => 
          array (
            'type' => 'return-type',
            'void' => 1,
            'file' => '/app/phalcon/Mvc/Model/MetaData.zep',
            'line' => 703,
            'char' => 5,
          ),
          'file' => '/app/phalcon/Mvc/Model/MetaData.zep',
          'line' => 702,
          'last-line' => 709,
          'char' => 19,
        ),
        29 => 
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
              'name' => 'key',
              'const' => 0,
              'data-type' => 'string',
              'mandatory' => 1,
              'reference' => 0,
              'file' => '/app/phalcon/Mvc/Model/MetaData.zep',
              'line' => 710,
              'char' => 38,
            ),
            1 => 
            array (
              'type' => 'parameter',
              'name' => 'data',
              'const' => 0,
              'data-type' => 'array',
              'mandatory' => 0,
              'reference' => 0,
              'file' => '/app/phalcon/Mvc/Model/MetaData.zep',
              'line' => 710,
              'char' => 50,
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
                  'variable' => 'result',
                  'file' => '/app/phalcon/Mvc/Model/MetaData.zep',
                  'line' => 712,
                  'char' => 19,
                ),
                1 => 
                array (
                  'variable' => 'option',
                  'file' => '/app/phalcon/Mvc/Model/MetaData.zep',
                  'line' => 712,
                  'char' => 27,
                ),
              ),
              'file' => '/app/phalcon/Mvc/Model/MetaData.zep',
              'line' => 714,
              'char' => 11,
            ),
            1 => 
            array (
              'type' => 'try-catch',
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
                      'variable' => 'option',
                      'expr' => 
                      array (
                        'type' => 'fcall',
                        'name' => 'globals_get',
                        'call-type' => 1,
                        'parameters' => 
                        array (
                          0 => 
                          array (
                            'parameter' => 
                            array (
                              'type' => 'string',
                              'value' => 'orm.exception_on_failed_metadata_save',
                              'file' => '/app/phalcon/Mvc/Model/MetaData.zep',
                              'line' => 715,
                              'char' => 75,
                            ),
                            'file' => '/app/phalcon/Mvc/Model/MetaData.zep',
                            'line' => 715,
                            'char' => 75,
                          ),
                        ),
                        'file' => '/app/phalcon/Mvc/Model/MetaData.zep',
                        'line' => 715,
                        'char' => 76,
                      ),
                      'file' => '/app/phalcon/Mvc/Model/MetaData.zep',
                      'line' => 715,
                      'char' => 76,
                    ),
                    1 => 
                    array (
                      'assign-type' => 'variable',
                      'operator' => 'assign',
                      'variable' => 'result',
                      'expr' => 
                      array (
                        'type' => 'mcall',
                        'variable' => 
                        array (
                          'type' => 'property-access',
                          'left' => 
                          array (
                            'type' => 'variable',
                            'value' => 'this',
                            'file' => '/app/phalcon/Mvc/Model/MetaData.zep',
                            'line' => 716,
                            'char' => 31,
                          ),
                          'right' => 
                          array (
                            'type' => 'variable',
                            'value' => 'adapter',
                            'file' => '/app/phalcon/Mvc/Model/MetaData.zep',
                            'line' => 716,
                            'char' => 40,
                          ),
                          'file' => '/app/phalcon/Mvc/Model/MetaData.zep',
                          'line' => 716,
                          'char' => 40,
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
                              'value' => 'key',
                              'file' => '/app/phalcon/Mvc/Model/MetaData.zep',
                              'line' => 716,
                              'char' => 48,
                            ),
                            'file' => '/app/phalcon/Mvc/Model/MetaData.zep',
                            'line' => 716,
                            'char' => 48,
                          ),
                          1 => 
                          array (
                            'parameter' => 
                            array (
                              'type' => 'variable',
                              'value' => 'data',
                              'file' => '/app/phalcon/Mvc/Model/MetaData.zep',
                              'line' => 716,
                              'char' => 54,
                            ),
                            'file' => '/app/phalcon/Mvc/Model/MetaData.zep',
                            'line' => 716,
                            'char' => 54,
                          ),
                        ),
                        'file' => '/app/phalcon/Mvc/Model/MetaData.zep',
                        'line' => 716,
                        'char' => 55,
                      ),
                      'file' => '/app/phalcon/Mvc/Model/MetaData.zep',
                      'line' => 716,
                      'char' => 55,
                    ),
                  ),
                  'file' => '/app/phalcon/Mvc/Model/MetaData.zep',
                  'line' => 718,
                  'char' => 14,
                ),
                1 => 
                array (
                  'type' => 'if',
                  'expr' => 
                  array (
                    'type' => 'identical',
                    'left' => 
                    array (
                      'type' => 'bool',
                      'value' => 'false',
                      'file' => '/app/phalcon/Mvc/Model/MetaData.zep',
                      'line' => 718,
                      'char' => 24,
                    ),
                    'right' => 
                    array (
                      'type' => 'variable',
                      'value' => 'result',
                      'file' => '/app/phalcon/Mvc/Model/MetaData.zep',
                      'line' => 718,
                      'char' => 33,
                    ),
                    'file' => '/app/phalcon/Mvc/Model/MetaData.zep',
                    'line' => 718,
                    'char' => 33,
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
                          'file' => '/app/phalcon/Mvc/Model/MetaData.zep',
                          'line' => 719,
                          'char' => 22,
                        ),
                        'name' => 'throwWriteException',
                        'call-type' => 1,
                        'parameters' => 
                        array (
                          0 => 
                          array (
                            'parameter' => 
                            array (
                              'type' => 'variable',
                              'value' => 'option',
                              'file' => '/app/phalcon/Mvc/Model/MetaData.zep',
                              'line' => 719,
                              'char' => 49,
                            ),
                            'file' => '/app/phalcon/Mvc/Model/MetaData.zep',
                            'line' => 719,
                            'char' => 49,
                          ),
                        ),
                        'file' => '/app/phalcon/Mvc/Model/MetaData.zep',
                        'line' => 719,
                        'char' => 50,
                      ),
                      'file' => '/app/phalcon/Mvc/Model/MetaData.zep',
                      'line' => 720,
                      'char' => 13,
                    ),
                  ),
                  'file' => '/app/phalcon/Mvc/Model/MetaData.zep',
                  'line' => 721,
                  'char' => 9,
                ),
              ),
              'catches' => 
              array (
                0 => 
                array (
                  'classes' => 
                  array (
                    0 => 
                    array (
                      'type' => 'variable',
                      'value' => '\\Exception',
                      'file' => '/app/phalcon/Mvc/Model/MetaData.zep',
                      'line' => 721,
                      'char' => 28,
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
                          'file' => '/app/phalcon/Mvc/Model/MetaData.zep',
                          'line' => 722,
                          'char' => 18,
                        ),
                        'name' => 'throwWriteException',
                        'call-type' => 1,
                        'parameters' => 
                        array (
                          0 => 
                          array (
                            'parameter' => 
                            array (
                              'type' => 'variable',
                              'value' => 'option',
                              'file' => '/app/phalcon/Mvc/Model/MetaData.zep',
                              'line' => 722,
                              'char' => 45,
                            ),
                            'file' => '/app/phalcon/Mvc/Model/MetaData.zep',
                            'line' => 722,
                            'char' => 45,
                          ),
                        ),
                        'file' => '/app/phalcon/Mvc/Model/MetaData.zep',
                        'line' => 722,
                        'char' => 46,
                      ),
                      'file' => '/app/phalcon/Mvc/Model/MetaData.zep',
                      'line' => 723,
                      'char' => 9,
                    ),
                  ),
                  'file' => '/app/phalcon/Mvc/Model/MetaData.zep',
                  'line' => 724,
                  'char' => 5,
                ),
              ),
              'file' => '/app/phalcon/Mvc/Model/MetaData.zep',
              'line' => 724,
              'char' => 5,
            ),
          ),
          'docblock' => '**
     * Writes the metadata to adapter
     *',
          'return-type' => 
          array (
            'type' => 'return-type',
            'void' => 1,
            'file' => '/app/phalcon/Mvc/Model/MetaData.zep',
            'line' => 711,
            'char' => 5,
          ),
          'file' => '/app/phalcon/Mvc/Model/MetaData.zep',
          'line' => 710,
          'last-line' => 740,
          'char' => 19,
        ),
        30 => 
        array (
          'visibility' => 
          array (
            0 => 'final',
            1 => 'public',
          ),
          'type' => 'method',
          'name' => 'writeMetaDataIndex',
          'parameters' => 
          array (
            0 => 
            array (
              'type' => 'parameter',
              'name' => 'model',
              'const' => 0,
              'data-type' => 'variable',
              'mandatory' => 0,
              'cast' => 
              array (
                'type' => 'variable',
                'value' => 'ModelInterface',
                'file' => '/app/phalcon/Mvc/Model/MetaData.zep',
                'line' => 741,
                'char' => 67,
              ),
              'reference' => 0,
              'file' => '/app/phalcon/Mvc/Model/MetaData.zep',
              'line' => 741,
              'char' => 68,
            ),
            1 => 
            array (
              'type' => 'parameter',
              'name' => 'index',
              'const' => 0,
              'data-type' => 'int',
              'mandatory' => 0,
              'reference' => 0,
              'file' => '/app/phalcon/Mvc/Model/MetaData.zep',
              'line' => 741,
              'char' => 79,
            ),
            2 => 
            array (
              'type' => 'parameter',
              'name' => 'data',
              'const' => 0,
              'data-type' => 'variable',
              'mandatory' => 0,
              'reference' => 0,
              'file' => '/app/phalcon/Mvc/Model/MetaData.zep',
              'line' => 741,
              'char' => 89,
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
                  'variable' => 'source',
                  'file' => '/app/phalcon/Mvc/Model/MetaData.zep',
                  'line' => 743,
                  'char' => 19,
                ),
                1 => 
                array (
                  'variable' => 'schema',
                  'file' => '/app/phalcon/Mvc/Model/MetaData.zep',
                  'line' => 743,
                  'char' => 27,
                ),
              ),
              'file' => '/app/phalcon/Mvc/Model/MetaData.zep',
              'line' => 744,
              'char' => 14,
            ),
            1 => 
            array (
              'type' => 'declare',
              'data-type' => 'string',
              'variables' => 
              array (
                0 => 
                array (
                  'variable' => 'key',
                  'file' => '/app/phalcon/Mvc/Model/MetaData.zep',
                  'line' => 744,
                  'char' => 19,
                ),
              ),
              'file' => '/app/phalcon/Mvc/Model/MetaData.zep',
              'line' => 746,
              'char' => 10,
            ),
            2 => 
            array (
              'type' => 'if',
              'expr' => 
              array (
                'type' => 'unlikely',
                'left' => 
                array (
                  'type' => 'list',
                  'left' => 
                  array (
                    'type' => 'and',
                    'left' => 
                    array (
                      'type' => 'and',
                      'left' => 
                      array (
                        'type' => 'not-equals',
                        'left' => 
                        array (
                          'type' => 'typeof',
                          'left' => 
                          array (
                            'type' => 'variable',
                            'value' => 'data',
                            'file' => '/app/phalcon/Mvc/Model/MetaData.zep',
                            'line' => 746,
                            'char' => 35,
                          ),
                          'file' => '/app/phalcon/Mvc/Model/MetaData.zep',
                          'line' => 746,
                          'char' => 35,
                        ),
                        'right' => 
                        array (
                          'type' => 'string',
                          'value' => 'array',
                          'file' => '/app/phalcon/Mvc/Model/MetaData.zep',
                          'line' => 746,
                          'char' => 44,
                        ),
                        'file' => '/app/phalcon/Mvc/Model/MetaData.zep',
                        'line' => 746,
                        'char' => 44,
                      ),
                      'right' => 
                      array (
                        'type' => 'not-equals',
                        'left' => 
                        array (
                          'type' => 'typeof',
                          'left' => 
                          array (
                            'type' => 'variable',
                            'value' => 'data',
                            'file' => '/app/phalcon/Mvc/Model/MetaData.zep',
                            'line' => 746,
                            'char' => 59,
                          ),
                          'file' => '/app/phalcon/Mvc/Model/MetaData.zep',
                          'line' => 746,
                          'char' => 59,
                        ),
                        'right' => 
                        array (
                          'type' => 'string',
                          'value' => 'string',
                          'file' => '/app/phalcon/Mvc/Model/MetaData.zep',
                          'line' => 746,
                          'char' => 69,
                        ),
                        'file' => '/app/phalcon/Mvc/Model/MetaData.zep',
                        'line' => 746,
                        'char' => 69,
                      ),
                      'file' => '/app/phalcon/Mvc/Model/MetaData.zep',
                      'line' => 746,
                      'char' => 69,
                    ),
                    'right' => 
                    array (
                      'type' => 'not-equals',
                      'left' => 
                      array (
                        'type' => 'typeof',
                        'left' => 
                        array (
                          'type' => 'variable',
                          'value' => 'data',
                          'file' => '/app/phalcon/Mvc/Model/MetaData.zep',
                          'line' => 746,
                          'char' => 84,
                        ),
                        'file' => '/app/phalcon/Mvc/Model/MetaData.zep',
                        'line' => 746,
                        'char' => 84,
                      ),
                      'right' => 
                      array (
                        'type' => 'string',
                        'value' => 'boolean',
                        'file' => '/app/phalcon/Mvc/Model/MetaData.zep',
                        'line' => 746,
                        'char' => 93,
                      ),
                      'file' => '/app/phalcon/Mvc/Model/MetaData.zep',
                      'line' => 746,
                      'char' => 93,
                    ),
                    'file' => '/app/phalcon/Mvc/Model/MetaData.zep',
                    'line' => 746,
                    'char' => 93,
                  ),
                  'file' => '/app/phalcon/Mvc/Model/MetaData.zep',
                  'line' => 746,
                  'char' => 95,
                ),
                'file' => '/app/phalcon/Mvc/Model/MetaData.zep',
                'line' => 746,
                'char' => 95,
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
                          'value' => 'Invalid data for index',
                          'file' => '/app/phalcon/Mvc/Model/MetaData.zep',
                          'line' => 747,
                          'char' => 55,
                        ),
                        'file' => '/app/phalcon/Mvc/Model/MetaData.zep',
                        'line' => 747,
                        'char' => 55,
                      ),
                    ),
                    'file' => '/app/phalcon/Mvc/Model/MetaData.zep',
                    'line' => 747,
                    'char' => 56,
                  ),
                  'file' => '/app/phalcon/Mvc/Model/MetaData.zep',
                  'line' => 748,
                  'char' => 9,
                ),
              ),
              'file' => '/app/phalcon/Mvc/Model/MetaData.zep',
              'line' => 750,
              'char' => 11,
            ),
            3 => 
            array (
              'type' => 'let',
              'assignments' => 
              array (
                0 => 
                array (
                  'assign-type' => 'variable',
                  'operator' => 'assign',
                  'variable' => 'source',
                  'expr' => 
                  array (
                    'type' => 'mcall',
                    'variable' => 
                    array (
                      'type' => 'variable',
                      'value' => 'model',
                      'file' => '/app/phalcon/Mvc/Model/MetaData.zep',
                      'line' => 750,
                      'char' => 28,
                    ),
                    'name' => 'getSource',
                    'call-type' => 1,
                    'file' => '/app/phalcon/Mvc/Model/MetaData.zep',
                    'line' => 750,
                    'char' => 40,
                  ),
                  'file' => '/app/phalcon/Mvc/Model/MetaData.zep',
                  'line' => 750,
                  'char' => 40,
                ),
                1 => 
                array (
                  'assign-type' => 'variable',
                  'operator' => 'assign',
                  'variable' => 'schema',
                  'expr' => 
                  array (
                    'type' => 'mcall',
                    'variable' => 
                    array (
                      'type' => 'variable',
                      'value' => 'model',
                      'file' => '/app/phalcon/Mvc/Model/MetaData.zep',
                      'line' => 751,
                      'char' => 28,
                    ),
                    'name' => 'getSchema',
                    'call-type' => 1,
                    'file' => '/app/phalcon/Mvc/Model/MetaData.zep',
                    'line' => 751,
                    'char' => 40,
                  ),
                  'file' => '/app/phalcon/Mvc/Model/MetaData.zep',
                  'line' => 751,
                  'char' => 40,
                ),
              ),
              'file' => '/app/phalcon/Mvc/Model/MetaData.zep',
              'line' => 756,
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
                  'variable' => 'key',
                  'expr' => 
                  array (
                    'type' => 'concat',
                    'left' => 
                    array (
                      'type' => 'concat',
                      'left' => 
                      array (
                        'type' => 'concat',
                        'left' => 
                        array (
                          'type' => 'fcall',
                          'name' => 'get_class_lower',
                          'call-type' => 1,
                          'parameters' => 
                          array (
                            0 => 
                            array (
                              'parameter' => 
                              array (
                                'type' => 'variable',
                                'value' => 'model',
                                'file' => '/app/phalcon/Mvc/Model/MetaData.zep',
                                'line' => 756,
                                'char' => 40,
                              ),
                              'file' => '/app/phalcon/Mvc/Model/MetaData.zep',
                              'line' => 756,
                              'char' => 40,
                            ),
                          ),
                          'file' => '/app/phalcon/Mvc/Model/MetaData.zep',
                          'line' => 756,
                          'char' => 42,
                        ),
                        'right' => 
                        array (
                          'type' => 'string',
                          'value' => '-',
                          'file' => '/app/phalcon/Mvc/Model/MetaData.zep',
                          'line' => 756,
                          'char' => 46,
                        ),
                        'file' => '/app/phalcon/Mvc/Model/MetaData.zep',
                        'line' => 756,
                        'char' => 46,
                      ),
                      'right' => 
                      array (
                        'type' => 'variable',
                        'value' => 'schema',
                        'file' => '/app/phalcon/Mvc/Model/MetaData.zep',
                        'line' => 756,
                        'char' => 55,
                      ),
                      'file' => '/app/phalcon/Mvc/Model/MetaData.zep',
                      'line' => 756,
                      'char' => 55,
                    ),
                    'right' => 
                    array (
                      'type' => 'variable',
                      'value' => 'source',
                      'file' => '/app/phalcon/Mvc/Model/MetaData.zep',
                      'line' => 756,
                      'char' => 63,
                    ),
                    'file' => '/app/phalcon/Mvc/Model/MetaData.zep',
                    'line' => 756,
                    'char' => 63,
                  ),
                  'file' => '/app/phalcon/Mvc/Model/MetaData.zep',
                  'line' => 756,
                  'char' => 63,
                ),
              ),
              'file' => '/app/phalcon/Mvc/Model/MetaData.zep',
              'line' => 758,
              'char' => 10,
            ),
            5 => 
            array (
              'type' => 'if',
              'expr' => 
              array (
                'type' => 'not',
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
                        'file' => '/app/phalcon/Mvc/Model/MetaData.zep',
                        'line' => 758,
                        'char' => 24,
                      ),
                      'right' => 
                      array (
                        'type' => 'variable',
                        'value' => 'metaData',
                        'file' => '/app/phalcon/Mvc/Model/MetaData.zep',
                        'line' => 758,
                        'char' => 33,
                      ),
                      'file' => '/app/phalcon/Mvc/Model/MetaData.zep',
                      'line' => 758,
                      'char' => 33,
                    ),
                    'right' => 
                    array (
                      'type' => 'variable',
                      'value' => 'key',
                      'file' => '/app/phalcon/Mvc/Model/MetaData.zep',
                      'line' => 758,
                      'char' => 37,
                    ),
                    'file' => '/app/phalcon/Mvc/Model/MetaData.zep',
                    'line' => 758,
                    'char' => 39,
                  ),
                  'file' => '/app/phalcon/Mvc/Model/MetaData.zep',
                  'line' => 758,
                  'char' => 39,
                ),
                'file' => '/app/phalcon/Mvc/Model/MetaData.zep',
                'line' => 758,
                'char' => 39,
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
                      'file' => '/app/phalcon/Mvc/Model/MetaData.zep',
                      'line' => 759,
                      'char' => 18,
                    ),
                    'name' => 'initialize',
                    'call-type' => 1,
                    'parameters' => 
                    array (
                      0 => 
                      array (
                        'parameter' => 
                        array (
                          'type' => 'variable',
                          'value' => 'model',
                          'file' => '/app/phalcon/Mvc/Model/MetaData.zep',
                          'line' => 759,
                          'char' => 35,
                        ),
                        'file' => '/app/phalcon/Mvc/Model/MetaData.zep',
                        'line' => 759,
                        'char' => 35,
                      ),
                      1 => 
                      array (
                        'parameter' => 
                        array (
                          'type' => 'variable',
                          'value' => 'key',
                          'file' => '/app/phalcon/Mvc/Model/MetaData.zep',
                          'line' => 759,
                          'char' => 40,
                        ),
                        'file' => '/app/phalcon/Mvc/Model/MetaData.zep',
                        'line' => 759,
                        'char' => 40,
                      ),
                      2 => 
                      array (
                        'parameter' => 
                        array (
                          'type' => 'variable',
                          'value' => 'source',
                          'file' => '/app/phalcon/Mvc/Model/MetaData.zep',
                          'line' => 759,
                          'char' => 48,
                        ),
                        'file' => '/app/phalcon/Mvc/Model/MetaData.zep',
                        'line' => 759,
                        'char' => 48,
                      ),
                      3 => 
                      array (
                        'parameter' => 
                        array (
                          'type' => 'variable',
                          'value' => 'schema',
                          'file' => '/app/phalcon/Mvc/Model/MetaData.zep',
                          'line' => 759,
                          'char' => 56,
                        ),
                        'file' => '/app/phalcon/Mvc/Model/MetaData.zep',
                        'line' => 759,
                        'char' => 56,
                      ),
                    ),
                    'file' => '/app/phalcon/Mvc/Model/MetaData.zep',
                    'line' => 759,
                    'char' => 57,
                  ),
                  'file' => '/app/phalcon/Mvc/Model/MetaData.zep',
                  'line' => 760,
                  'char' => 9,
                ),
              ),
              'file' => '/app/phalcon/Mvc/Model/MetaData.zep',
              'line' => 762,
              'char' => 11,
            ),
            6 => 
            array (
              'type' => 'let',
              'assignments' => 
              array (
                0 => 
                array (
                  'assign-type' => 'object-property-array-index',
                  'operator' => 'assign',
                  'variable' => 'this',
                  'property' => 'metaData',
                  'index-expr' => 
                  array (
                    0 => 
                    array (
                      'type' => 'variable',
                      'value' => 'key',
                      'file' => '/app/phalcon/Mvc/Model/MetaData.zep',
                      'line' => 762,
                      'char' => 31,
                    ),
                    1 => 
                    array (
                      'type' => 'variable',
                      'value' => 'index',
                      'file' => '/app/phalcon/Mvc/Model/MetaData.zep',
                      'line' => 762,
                      'char' => 38,
                    ),
                  ),
                  'expr' => 
                  array (
                    'type' => 'variable',
                    'value' => 'data',
                    'file' => '/app/phalcon/Mvc/Model/MetaData.zep',
                    'line' => 762,
                    'char' => 46,
                  ),
                  'file' => '/app/phalcon/Mvc/Model/MetaData.zep',
                  'line' => 762,
                  'char' => 46,
                ),
              ),
              'file' => '/app/phalcon/Mvc/Model/MetaData.zep',
              'line' => 763,
              'char' => 5,
            ),
          ),
          'docblock' => '**
     * Writes meta-data for certain model using a MODEL_* constant
     *
     *```php
     * print_r(
     *     $metaData->writeColumnMapIndex(
     *         new Robots(),
     *         MetaData::MODELS_REVERSE_COLUMN_MAP,
     *         [
     *             "leName" => "name",
     *         ]
     *     )
     * );
     *```
     *',
          'return-type' => 
          array (
            'type' => 'return-type',
            'void' => 1,
            'file' => '/app/phalcon/Mvc/Model/MetaData.zep',
            'line' => 742,
            'char' => 5,
          ),
          'file' => '/app/phalcon/Mvc/Model/MetaData.zep',
          'line' => 741,
          'last-line' => 767,
          'char' => 25,
        ),
        31 => 
        array (
          'visibility' => 
          array (
            0 => 'final',
            1 => 'protected',
          ),
          'type' => 'method',
          'name' => 'initialize',
          'parameters' => 
          array (
            0 => 
            array (
              'type' => 'parameter',
              'name' => 'model',
              'const' => 0,
              'data-type' => 'variable',
              'mandatory' => 0,
              'cast' => 
              array (
                'type' => 'variable',
                'value' => 'ModelInterface',
                'file' => '/app/phalcon/Mvc/Model/MetaData.zep',
                'line' => 768,
                'char' => 62,
              ),
              'reference' => 0,
              'file' => '/app/phalcon/Mvc/Model/MetaData.zep',
              'line' => 768,
              'char' => 63,
            ),
            1 => 
            array (
              'type' => 'parameter',
              'name' => 'key',
              'const' => 0,
              'data-type' => 'variable',
              'mandatory' => 0,
              'reference' => 0,
              'file' => '/app/phalcon/Mvc/Model/MetaData.zep',
              'line' => 768,
              'char' => 72,
            ),
            2 => 
            array (
              'type' => 'parameter',
              'name' => 'table',
              'const' => 0,
              'data-type' => 'variable',
              'mandatory' => 0,
              'reference' => 0,
              'file' => '/app/phalcon/Mvc/Model/MetaData.zep',
              'line' => 768,
              'char' => 83,
            ),
            3 => 
            array (
              'type' => 'parameter',
              'name' => 'schema',
              'const' => 0,
              'data-type' => 'variable',
              'mandatory' => 0,
              'reference' => 0,
              'file' => '/app/phalcon/Mvc/Model/MetaData.zep',
              'line' => 768,
              'char' => 95,
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
                  'variable' => 'strategy',
                  'file' => '/app/phalcon/Mvc/Model/MetaData.zep',
                  'line' => 770,
                  'char' => 21,
                ),
                1 => 
                array (
                  'variable' => 'className',
                  'file' => '/app/phalcon/Mvc/Model/MetaData.zep',
                  'line' => 770,
                  'char' => 32,
                ),
                2 => 
                array (
                  'variable' => 'metaData',
                  'file' => '/app/phalcon/Mvc/Model/MetaData.zep',
                  'line' => 770,
                  'char' => 42,
                ),
                3 => 
                array (
                  'variable' => 'data',
                  'file' => '/app/phalcon/Mvc/Model/MetaData.zep',
                  'line' => 770,
                  'char' => 48,
                ),
                4 => 
                array (
                  'variable' => 'modelMetadata',
                  'file' => '/app/phalcon/Mvc/Model/MetaData.zep',
                  'line' => 770,
                  'char' => 63,
                ),
                5 => 
                array (
                  'variable' => 'modelColumnMap',
                  'file' => '/app/phalcon/Mvc/Model/MetaData.zep',
                  'line' => 770,
                  'char' => 79,
                ),
                6 => 
                array (
                  'variable' => 'container',
                  'file' => '/app/phalcon/Mvc/Model/MetaData.zep',
                  'line' => 771,
                  'char' => 22,
                ),
                7 => 
                array (
                  'variable' => 'keyName',
                  'file' => '/app/phalcon/Mvc/Model/MetaData.zep',
                  'line' => 771,
                  'char' => 31,
                ),
              ),
              'file' => '/app/phalcon/Mvc/Model/MetaData.zep',
              'line' => 772,
              'char' => 14,
            ),
            1 => 
            array (
              'type' => 'declare',
              'data-type' => 'string',
              'variables' => 
              array (
                0 => 
                array (
                  'variable' => 'prefixKey',
                  'file' => '/app/phalcon/Mvc/Model/MetaData.zep',
                  'line' => 772,
                  'char' => 25,
                ),
              ),
              'file' => '/app/phalcon/Mvc/Model/MetaData.zep',
              'line' => 774,
              'char' => 11,
            ),
            2 => 
            array (
              'type' => 'let',
              'assignments' => 
              array (
                0 => 
                array (
                  'assign-type' => 'variable',
                  'operator' => 'assign',
                  'variable' => 'strategy',
                  'expr' => 
                  array (
                    'type' => 'null',
                    'file' => '/app/phalcon/Mvc/Model/MetaData.zep',
                    'line' => 774,
                    'char' => 28,
                  ),
                  'file' => '/app/phalcon/Mvc/Model/MetaData.zep',
                  'line' => 774,
                  'char' => 28,
                ),
                1 => 
                array (
                  'assign-type' => 'variable',
                  'operator' => 'assign',
                  'variable' => 'className',
                  'expr' => 
                  array (
                    'type' => 'fcall',
                    'name' => 'get_class',
                    'call-type' => 1,
                    'parameters' => 
                    array (
                      0 => 
                      array (
                        'parameter' => 
                        array (
                          'type' => 'variable',
                          'value' => 'model',
                          'file' => '/app/phalcon/Mvc/Model/MetaData.zep',
                          'line' => 775,
                          'char' => 40,
                        ),
                        'file' => '/app/phalcon/Mvc/Model/MetaData.zep',
                        'line' => 775,
                        'char' => 40,
                      ),
                    ),
                    'file' => '/app/phalcon/Mvc/Model/MetaData.zep',
                    'line' => 775,
                    'char' => 41,
                  ),
                  'file' => '/app/phalcon/Mvc/Model/MetaData.zep',
                  'line' => 775,
                  'char' => 41,
                ),
              ),
              'file' => '/app/phalcon/Mvc/Model/MetaData.zep',
              'line' => 777,
              'char' => 10,
            ),
            3 => 
            array (
              'type' => 'if',
              'expr' => 
              array (
                'type' => 'not-identical',
                'left' => 
                array (
                  'type' => 'variable',
                  'value' => 'key',
                  'file' => '/app/phalcon/Mvc/Model/MetaData.zep',
                  'line' => 777,
                  'char' => 18,
                ),
                'right' => 
                array (
                  'type' => 'null',
                  'file' => '/app/phalcon/Mvc/Model/MetaData.zep',
                  'line' => 777,
                  'char' => 25,
                ),
                'file' => '/app/phalcon/Mvc/Model/MetaData.zep',
                'line' => 777,
                'char' => 25,
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
                      'variable' => 'metaData',
                      'expr' => 
                      array (
                        'type' => 'property-access',
                        'left' => 
                        array (
                          'type' => 'variable',
                          'value' => 'this',
                          'file' => '/app/phalcon/Mvc/Model/MetaData.zep',
                          'line' => 778,
                          'char' => 33,
                        ),
                        'right' => 
                        array (
                          'type' => 'variable',
                          'value' => 'metaData',
                          'file' => '/app/phalcon/Mvc/Model/MetaData.zep',
                          'line' => 778,
                          'char' => 42,
                        ),
                        'file' => '/app/phalcon/Mvc/Model/MetaData.zep',
                        'line' => 778,
                        'char' => 42,
                      ),
                      'file' => '/app/phalcon/Mvc/Model/MetaData.zep',
                      'line' => 778,
                      'char' => 42,
                    ),
                  ),
                  'file' => '/app/phalcon/Mvc/Model/MetaData.zep',
                  'line' => 780,
                  'char' => 14,
                ),
                1 => 
                array (
                  'type' => 'if',
                  'expr' => 
                  array (
                    'type' => 'not',
                    'left' => 
                    array (
                      'type' => 'isset',
                      'left' => 
                      array (
                        'type' => 'array-access',
                        'left' => 
                        array (
                          'type' => 'variable',
                          'value' => 'metaData',
                          'file' => '/app/phalcon/Mvc/Model/MetaData.zep',
                          'line' => 780,
                          'char' => 31,
                        ),
                        'right' => 
                        array (
                          'type' => 'variable',
                          'value' => 'key',
                          'file' => '/app/phalcon/Mvc/Model/MetaData.zep',
                          'line' => 780,
                          'char' => 35,
                        ),
                        'file' => '/app/phalcon/Mvc/Model/MetaData.zep',
                        'line' => 780,
                        'char' => 37,
                      ),
                      'file' => '/app/phalcon/Mvc/Model/MetaData.zep',
                      'line' => 780,
                      'char' => 37,
                    ),
                    'file' => '/app/phalcon/Mvc/Model/MetaData.zep',
                    'line' => 780,
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
                          'variable' => 'prefixKey',
                          'expr' => 
                          array (
                            'type' => 'concat',
                            'left' => 
                            array (
                              'type' => 'string',
                              'value' => 'meta-',
                              'file' => '/app/phalcon/Mvc/Model/MetaData.zep',
                              'line' => 784,
                              'char' => 39,
                            ),
                            'right' => 
                            array (
                              'type' => 'variable',
                              'value' => 'key',
                              'file' => '/app/phalcon/Mvc/Model/MetaData.zep',
                              'line' => 784,
                              'char' => 44,
                            ),
                            'file' => '/app/phalcon/Mvc/Model/MetaData.zep',
                            'line' => 784,
                            'char' => 44,
                          ),
                          'file' => '/app/phalcon/Mvc/Model/MetaData.zep',
                          'line' => 784,
                          'char' => 44,
                        ),
                        1 => 
                        array (
                          'assign-type' => 'variable',
                          'operator' => 'assign',
                          'variable' => 'data',
                          'expr' => 
                          array (
                            'type' => 'mcall',
                            'variable' => 
                            array (
                              'type' => 'variable',
                              'value' => 'this',
                              'file' => '/app/phalcon/Mvc/Model/MetaData.zep',
                              'line' => 785,
                              'char' => 33,
                            ),
                            'name' => 'read',
                            'call-type' => 3,
                            'parameters' => 
                            array (
                              0 => 
                              array (
                                'parameter' => 
                                array (
                                  'type' => 'variable',
                                  'value' => 'prefixKey',
                                  'file' => '/app/phalcon/Mvc/Model/MetaData.zep',
                                  'line' => 785,
                                  'char' => 50,
                                ),
                                'file' => '/app/phalcon/Mvc/Model/MetaData.zep',
                                'line' => 785,
                                'char' => 50,
                              ),
                            ),
                            'file' => '/app/phalcon/Mvc/Model/MetaData.zep',
                            'line' => 785,
                            'char' => 51,
                          ),
                          'file' => '/app/phalcon/Mvc/Model/MetaData.zep',
                          'line' => 785,
                          'char' => 51,
                        ),
                      ),
                      'file' => '/app/phalcon/Mvc/Model/MetaData.zep',
                      'line' => 787,
                      'char' => 18,
                    ),
                    1 => 
                    array (
                      'type' => 'if',
                      'expr' => 
                      array (
                        'type' => 'not-identical',
                        'left' => 
                        array (
                          'type' => 'variable',
                          'value' => 'data',
                          'file' => '/app/phalcon/Mvc/Model/MetaData.zep',
                          'line' => 787,
                          'char' => 27,
                        ),
                        'right' => 
                        array (
                          'type' => 'null',
                          'file' => '/app/phalcon/Mvc/Model/MetaData.zep',
                          'line' => 787,
                          'char' => 34,
                        ),
                        'file' => '/app/phalcon/Mvc/Model/MetaData.zep',
                        'line' => 787,
                        'char' => 34,
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
                              'assign-type' => 'object-property-array-index',
                              'operator' => 'assign',
                              'variable' => 'this',
                              'property' => 'metaData',
                              'index-expr' => 
                              array (
                                0 => 
                                array (
                                  'type' => 'variable',
                                  'value' => 'key',
                                  'file' => '/app/phalcon/Mvc/Model/MetaData.zep',
                                  'line' => 788,
                                  'char' => 43,
                                ),
                              ),
                              'expr' => 
                              array (
                                'type' => 'variable',
                                'value' => 'data',
                                'file' => '/app/phalcon/Mvc/Model/MetaData.zep',
                                'line' => 788,
                                'char' => 51,
                              ),
                              'file' => '/app/phalcon/Mvc/Model/MetaData.zep',
                              'line' => 788,
                              'char' => 51,
                            ),
                          ),
                          'file' => '/app/phalcon/Mvc/Model/MetaData.zep',
                          'line' => 789,
                          'char' => 17,
                        ),
                      ),
                      'else_statements' => 
                      array (
                        0 => 
                        array (
                          'type' => 'if',
                          'expr' => 
                          array (
                            'type' => 'fcall',
                            'name' => 'method_exists',
                            'call-type' => 1,
                            'parameters' => 
                            array (
                              0 => 
                              array (
                                'parameter' => 
                                array (
                                  'type' => 'variable',
                                  'value' => 'model',
                                  'file' => '/app/phalcon/Mvc/Model/MetaData.zep',
                                  'line' => 793,
                                  'char' => 43,
                                ),
                                'file' => '/app/phalcon/Mvc/Model/MetaData.zep',
                                'line' => 793,
                                'char' => 43,
                              ),
                              1 => 
                              array (
                                'parameter' => 
                                array (
                                  'type' => 'string',
                                  'value' => 'metaData',
                                  'file' => '/app/phalcon/Mvc/Model/MetaData.zep',
                                  'line' => 793,
                                  'char' => 53,
                                ),
                                'file' => '/app/phalcon/Mvc/Model/MetaData.zep',
                                'line' => 793,
                                'char' => 53,
                              ),
                            ),
                            'file' => '/app/phalcon/Mvc/Model/MetaData.zep',
                            'line' => 793,
                            'char' => 55,
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
                                  'variable' => 'modelMetadata',
                                  'expr' => 
                                  array (
                                    'type' => 'mcall',
                                    'variable' => 
                                    array (
                                      'type' => 'variable',
                                      'value' => 'model',
                                      'file' => '/app/phalcon/Mvc/Model/MetaData.zep',
                                      'line' => 794,
                                      'char' => 51,
                                    ),
                                    'name' => 'metaData',
                                    'call-type' => 3,
                                    'file' => '/app/phalcon/Mvc/Model/MetaData.zep',
                                    'line' => 794,
                                    'char' => 64,
                                  ),
                                  'file' => '/app/phalcon/Mvc/Model/MetaData.zep',
                                  'line' => 794,
                                  'char' => 64,
                                ),
                              ),
                              'file' => '/app/phalcon/Mvc/Model/MetaData.zep',
                              'line' => 796,
                              'char' => 26,
                            ),
                            1 => 
                            array (
                              'type' => 'if',
                              'expr' => 
                              array (
                                'type' => 'unlikely',
                                'left' => 
                                array (
                                  'type' => 'not-equals',
                                  'left' => 
                                  array (
                                    'type' => 'typeof',
                                    'left' => 
                                    array (
                                      'type' => 'variable',
                                      'value' => 'modelMetadata',
                                      'file' => '/app/phalcon/Mvc/Model/MetaData.zep',
                                      'line' => 796,
                                      'char' => 59,
                                    ),
                                    'file' => '/app/phalcon/Mvc/Model/MetaData.zep',
                                    'line' => 796,
                                    'char' => 59,
                                  ),
                                  'right' => 
                                  array (
                                    'type' => 'string',
                                    'value' => 'array',
                                    'file' => '/app/phalcon/Mvc/Model/MetaData.zep',
                                    'line' => 796,
                                    'char' => 67,
                                  ),
                                  'file' => '/app/phalcon/Mvc/Model/MetaData.zep',
                                  'line' => 796,
                                  'char' => 67,
                                ),
                                'file' => '/app/phalcon/Mvc/Model/MetaData.zep',
                                'line' => 796,
                                'char' => 67,
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
                                          'type' => 'concat',
                                          'left' => 
                                          array (
                                            'type' => 'string',
                                            'value' => 'Invalid meta-data for model ',
                                            'file' => '/app/phalcon/Mvc/Model/MetaData.zep',
                                            'line' => 798,
                                            'char' => 62,
                                          ),
                                          'right' => 
                                          array (
                                            'type' => 'variable',
                                            'value' => 'className',
                                            'file' => '/app/phalcon/Mvc/Model/MetaData.zep',
                                            'line' => 799,
                                            'char' => 29,
                                          ),
                                          'file' => '/app/phalcon/Mvc/Model/MetaData.zep',
                                          'line' => 799,
                                          'char' => 29,
                                        ),
                                        'file' => '/app/phalcon/Mvc/Model/MetaData.zep',
                                        'line' => 799,
                                        'char' => 29,
                                      ),
                                    ),
                                    'file' => '/app/phalcon/Mvc/Model/MetaData.zep',
                                    'line' => 799,
                                    'char' => 30,
                                  ),
                                  'file' => '/app/phalcon/Mvc/Model/MetaData.zep',
                                  'line' => 800,
                                  'char' => 25,
                                ),
                              ),
                              'file' => '/app/phalcon/Mvc/Model/MetaData.zep',
                              'line' => 801,
                              'char' => 21,
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
                                  'assign-type' => 'variable',
                                  'operator' => 'assign',
                                  'variable' => 'container',
                                  'expr' => 
                                  array (
                                    'type' => 'property-access',
                                    'left' => 
                                    array (
                                      'type' => 'variable',
                                      'value' => 'this',
                                      'file' => '/app/phalcon/Mvc/Model/MetaData.zep',
                                      'line' => 805,
                                      'char' => 46,
                                    ),
                                    'right' => 
                                    array (
                                      'type' => 'variable',
                                      'value' => 'container',
                                      'file' => '/app/phalcon/Mvc/Model/MetaData.zep',
                                      'line' => 805,
                                      'char' => 56,
                                    ),
                                    'file' => '/app/phalcon/Mvc/Model/MetaData.zep',
                                    'line' => 805,
                                    'char' => 56,
                                  ),
                                  'file' => '/app/phalcon/Mvc/Model/MetaData.zep',
                                  'line' => 805,
                                  'char' => 56,
                                ),
                                1 => 
                                array (
                                  'assign-type' => 'variable',
                                  'operator' => 'assign',
                                  'variable' => 'strategy',
                                  'expr' => 
                                  array (
                                    'type' => 'mcall',
                                    'variable' => 
                                    array (
                                      'type' => 'variable',
                                      'value' => 'this',
                                      'file' => '/app/phalcon/Mvc/Model/MetaData.zep',
                                      'line' => 806,
                                      'char' => 45,
                                    ),
                                    'name' => 'getStrategy',
                                    'call-type' => 1,
                                    'file' => '/app/phalcon/Mvc/Model/MetaData.zep',
                                    'line' => 806,
                                    'char' => 59,
                                  ),
                                  'file' => '/app/phalcon/Mvc/Model/MetaData.zep',
                                  'line' => 806,
                                  'char' => 59,
                                ),
                                2 => 
                                array (
                                  'assign-type' => 'variable',
                                  'operator' => 'assign',
                                  'variable' => 'modelMetadata',
                                  'expr' => 
                                  array (
                                    'type' => 'mcall',
                                    'variable' => 
                                    array (
                                      'type' => 'variable',
                                      'value' => 'strategy',
                                      'file' => '/app/phalcon/Mvc/Model/MetaData.zep',
                                      'line' => 807,
                                      'char' => 54,
                                    ),
                                    'name' => 'getMetaData',
                                    'call-type' => 1,
                                    'parameters' => 
                                    array (
                                      0 => 
                                      array (
                                        'parameter' => 
                                        array (
                                          'type' => 'variable',
                                          'value' => 'model',
                                          'file' => '/app/phalcon/Mvc/Model/MetaData.zep',
                                          'line' => 808,
                                          'char' => 38,
                                        ),
                                        'file' => '/app/phalcon/Mvc/Model/MetaData.zep',
                                        'line' => 808,
                                        'char' => 38,
                                      ),
                                      1 => 
                                      array (
                                        'parameter' => 
                                        array (
                                          'type' => 'variable',
                                          'value' => 'container',
                                          'file' => '/app/phalcon/Mvc/Model/MetaData.zep',
                                          'line' => 810,
                                          'char' => 29,
                                        ),
                                        'file' => '/app/phalcon/Mvc/Model/MetaData.zep',
                                        'line' => 810,
                                        'char' => 29,
                                      ),
                                    ),
                                    'file' => '/app/phalcon/Mvc/Model/MetaData.zep',
                                    'line' => 810,
                                    'char' => 30,
                                  ),
                                  'file' => '/app/phalcon/Mvc/Model/MetaData.zep',
                                  'line' => 810,
                                  'char' => 30,
                                ),
                              ),
                              'file' => '/app/phalcon/Mvc/Model/MetaData.zep',
                              'line' => 811,
                              'char' => 21,
                            ),
                          ),
                          'file' => '/app/phalcon/Mvc/Model/MetaData.zep',
                          'line' => 816,
                          'char' => 23,
                        ),
                        1 => 
                        array (
                          'type' => 'let',
                          'assignments' => 
                          array (
                            0 => 
                            array (
                              'assign-type' => 'object-property-array-index',
                              'operator' => 'assign',
                              'variable' => 'this',
                              'property' => 'metaData',
                              'index-expr' => 
                              array (
                                0 => 
                                array (
                                  'type' => 'variable',
                                  'value' => 'key',
                                  'file' => '/app/phalcon/Mvc/Model/MetaData.zep',
                                  'line' => 816,
                                  'char' => 43,
                                ),
                              ),
                              'expr' => 
                              array (
                                'type' => 'variable',
                                'value' => 'modelMetadata',
                                'file' => '/app/phalcon/Mvc/Model/MetaData.zep',
                                'line' => 816,
                                'char' => 60,
                              ),
                              'file' => '/app/phalcon/Mvc/Model/MetaData.zep',
                              'line' => 816,
                              'char' => 60,
                            ),
                          ),
                          'file' => '/app/phalcon/Mvc/Model/MetaData.zep',
                          'line' => 821,
                          'char' => 24,
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
                              'file' => '/app/phalcon/Mvc/Model/MetaData.zep',
                              'line' => 821,
                              'char' => 26,
                            ),
                            'name' => 'write',
                            'call-type' => 3,
                            'parameters' => 
                            array (
                              0 => 
                              array (
                                'parameter' => 
                                array (
                                  'type' => 'variable',
                                  'value' => 'prefixKey',
                                  'file' => '/app/phalcon/Mvc/Model/MetaData.zep',
                                  'line' => 821,
                                  'char' => 44,
                                ),
                                'file' => '/app/phalcon/Mvc/Model/MetaData.zep',
                                'line' => 821,
                                'char' => 44,
                              ),
                              1 => 
                              array (
                                'parameter' => 
                                array (
                                  'type' => 'variable',
                                  'value' => 'modelMetadata',
                                  'file' => '/app/phalcon/Mvc/Model/MetaData.zep',
                                  'line' => 821,
                                  'char' => 59,
                                ),
                                'file' => '/app/phalcon/Mvc/Model/MetaData.zep',
                                'line' => 821,
                                'char' => 59,
                              ),
                            ),
                            'file' => '/app/phalcon/Mvc/Model/MetaData.zep',
                            'line' => 821,
                            'char' => 60,
                          ),
                          'file' => '/app/phalcon/Mvc/Model/MetaData.zep',
                          'line' => 822,
                          'char' => 17,
                        ),
                      ),
                      'file' => '/app/phalcon/Mvc/Model/MetaData.zep',
                      'line' => 823,
                      'char' => 13,
                    ),
                  ),
                  'file' => '/app/phalcon/Mvc/Model/MetaData.zep',
                  'line' => 824,
                  'char' => 9,
                ),
              ),
              'file' => '/app/phalcon/Mvc/Model/MetaData.zep',
              'line' => 829,
              'char' => 10,
            ),
            4 => 
            array (
              'type' => 'if',
              'expr' => 
              array (
                'type' => 'not',
                'left' => 
                array (
                  'type' => 'fcall',
                  'name' => 'globals_get',
                  'call-type' => 1,
                  'parameters' => 
                  array (
                    0 => 
                    array (
                      'parameter' => 
                      array (
                        'type' => 'string',
                        'value' => 'orm.column_renaming',
                        'file' => '/app/phalcon/Mvc/Model/MetaData.zep',
                        'line' => 829,
                        'char' => 44,
                      ),
                      'file' => '/app/phalcon/Mvc/Model/MetaData.zep',
                      'line' => 829,
                      'char' => 44,
                    ),
                  ),
                  'file' => '/app/phalcon/Mvc/Model/MetaData.zep',
                  'line' => 829,
                  'char' => 46,
                ),
                'file' => '/app/phalcon/Mvc/Model/MetaData.zep',
                'line' => 829,
                'char' => 46,
              ),
              'statements' => 
              array (
                0 => 
                array (
                  'type' => 'return',
                  'expr' => 
                  array (
                    'type' => 'null',
                    'file' => '/app/phalcon/Mvc/Model/MetaData.zep',
                    'line' => 830,
                    'char' => 24,
                  ),
                  'file' => '/app/phalcon/Mvc/Model/MetaData.zep',
                  'line' => 831,
                  'char' => 9,
                ),
              ),
              'file' => '/app/phalcon/Mvc/Model/MetaData.zep',
              'line' => 833,
              'char' => 11,
            ),
            5 => 
            array (
              'type' => 'let',
              'assignments' => 
              array (
                0 => 
                array (
                  'assign-type' => 'variable',
                  'operator' => 'assign',
                  'variable' => 'keyName',
                  'expr' => 
                  array (
                    'type' => 'fcall',
                    'name' => 'strtolower',
                    'call-type' => 1,
                    'parameters' => 
                    array (
                      0 => 
                      array (
                        'parameter' => 
                        array (
                          'type' => 'variable',
                          'value' => 'className',
                          'file' => '/app/phalcon/Mvc/Model/MetaData.zep',
                          'line' => 833,
                          'char' => 43,
                        ),
                        'file' => '/app/phalcon/Mvc/Model/MetaData.zep',
                        'line' => 833,
                        'char' => 43,
                      ),
                    ),
                    'file' => '/app/phalcon/Mvc/Model/MetaData.zep',
                    'line' => 833,
                    'char' => 44,
                  ),
                  'file' => '/app/phalcon/Mvc/Model/MetaData.zep',
                  'line' => 833,
                  'char' => 44,
                ),
              ),
              'file' => '/app/phalcon/Mvc/Model/MetaData.zep',
              'line' => 835,
              'char' => 10,
            ),
            6 => 
            array (
              'type' => 'if',
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
                      'file' => '/app/phalcon/Mvc/Model/MetaData.zep',
                      'line' => 835,
                      'char' => 23,
                    ),
                    'right' => 
                    array (
                      'type' => 'variable',
                      'value' => 'columnMap',
                      'file' => '/app/phalcon/Mvc/Model/MetaData.zep',
                      'line' => 835,
                      'char' => 33,
                    ),
                    'file' => '/app/phalcon/Mvc/Model/MetaData.zep',
                    'line' => 835,
                    'char' => 33,
                  ),
                  'right' => 
                  array (
                    'type' => 'variable',
                    'value' => 'keyName',
                    'file' => '/app/phalcon/Mvc/Model/MetaData.zep',
                    'line' => 835,
                    'char' => 41,
                  ),
                  'file' => '/app/phalcon/Mvc/Model/MetaData.zep',
                  'line' => 835,
                  'char' => 43,
                ),
                'file' => '/app/phalcon/Mvc/Model/MetaData.zep',
                'line' => 835,
                'char' => 43,
              ),
              'statements' => 
              array (
                0 => 
                array (
                  'type' => 'return',
                  'expr' => 
                  array (
                    'type' => 'null',
                    'file' => '/app/phalcon/Mvc/Model/MetaData.zep',
                    'line' => 836,
                    'char' => 24,
                  ),
                  'file' => '/app/phalcon/Mvc/Model/MetaData.zep',
                  'line' => 837,
                  'char' => 9,
                ),
              ),
              'file' => '/app/phalcon/Mvc/Model/MetaData.zep',
              'line' => 843,
              'char' => 11,
            ),
            7 => 
            array (
              'type' => 'let',
              'assignments' => 
              array (
                0 => 
                array (
                  'assign-type' => 'variable',
                  'operator' => 'assign',
                  'variable' => 'prefixKey',
                  'expr' => 
                  array (
                    'type' => 'concat',
                    'left' => 
                    array (
                      'type' => 'string',
                      'value' => 'map-',
                      'file' => '/app/phalcon/Mvc/Model/MetaData.zep',
                      'line' => 843,
                      'char' => 30,
                    ),
                    'right' => 
                    array (
                      'type' => 'variable',
                      'value' => 'keyName',
                      'file' => '/app/phalcon/Mvc/Model/MetaData.zep',
                      'line' => 843,
                      'char' => 39,
                    ),
                    'file' => '/app/phalcon/Mvc/Model/MetaData.zep',
                    'line' => 843,
                    'char' => 39,
                  ),
                  'file' => '/app/phalcon/Mvc/Model/MetaData.zep',
                  'line' => 843,
                  'char' => 39,
                ),
                1 => 
                array (
                  'assign-type' => 'variable',
                  'operator' => 'assign',
                  'variable' => 'data',
                  'expr' => 
                  array (
                    'type' => 'mcall',
                    'variable' => 
                    array (
                      'type' => 'variable',
                      'value' => 'this',
                      'file' => '/app/phalcon/Mvc/Model/MetaData.zep',
                      'line' => 844,
                      'char' => 25,
                    ),
                    'name' => 'read',
                    'call-type' => 3,
                    'parameters' => 
                    array (
                      0 => 
                      array (
                        'parameter' => 
                        array (
                          'type' => 'variable',
                          'value' => 'prefixKey',
                          'file' => '/app/phalcon/Mvc/Model/MetaData.zep',
                          'line' => 844,
                          'char' => 42,
                        ),
                        'file' => '/app/phalcon/Mvc/Model/MetaData.zep',
                        'line' => 844,
                        'char' => 42,
                      ),
                    ),
                    'file' => '/app/phalcon/Mvc/Model/MetaData.zep',
                    'line' => 844,
                    'char' => 43,
                  ),
                  'file' => '/app/phalcon/Mvc/Model/MetaData.zep',
                  'line' => 844,
                  'char' => 43,
                ),
              ),
              'file' => '/app/phalcon/Mvc/Model/MetaData.zep',
              'line' => 846,
              'char' => 10,
            ),
            8 => 
            array (
              'type' => 'if',
              'expr' => 
              array (
                'type' => 'not-identical',
                'left' => 
                array (
                  'type' => 'variable',
                  'value' => 'data',
                  'file' => '/app/phalcon/Mvc/Model/MetaData.zep',
                  'line' => 846,
                  'char' => 19,
                ),
                'right' => 
                array (
                  'type' => 'null',
                  'file' => '/app/phalcon/Mvc/Model/MetaData.zep',
                  'line' => 846,
                  'char' => 26,
                ),
                'file' => '/app/phalcon/Mvc/Model/MetaData.zep',
                'line' => 846,
                'char' => 26,
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
                      'assign-type' => 'object-property-array-index',
                      'operator' => 'assign',
                      'variable' => 'this',
                      'property' => 'columnMap',
                      'index-expr' => 
                      array (
                        0 => 
                        array (
                          'type' => 'variable',
                          'value' => 'keyName',
                          'file' => '/app/phalcon/Mvc/Model/MetaData.zep',
                          'line' => 847,
                          'char' => 40,
                        ),
                      ),
                      'expr' => 
                      array (
                        'type' => 'variable',
                        'value' => 'data',
                        'file' => '/app/phalcon/Mvc/Model/MetaData.zep',
                        'line' => 847,
                        'char' => 48,
                      ),
                      'file' => '/app/phalcon/Mvc/Model/MetaData.zep',
                      'line' => 847,
                      'char' => 48,
                    ),
                  ),
                  'file' => '/app/phalcon/Mvc/Model/MetaData.zep',
                  'line' => 849,
                  'char' => 18,
                ),
                1 => 
                array (
                  'type' => 'return',
                  'expr' => 
                  array (
                    'type' => 'null',
                    'file' => '/app/phalcon/Mvc/Model/MetaData.zep',
                    'line' => 849,
                    'char' => 24,
                  ),
                  'file' => '/app/phalcon/Mvc/Model/MetaData.zep',
                  'line' => 850,
                  'char' => 9,
                ),
              ),
              'file' => '/app/phalcon/Mvc/Model/MetaData.zep',
              'line' => 855,
              'char' => 10,
            ),
            9 => 
            array (
              'type' => 'if',
              'expr' => 
              array (
                'type' => 'not-equals',
                'left' => 
                array (
                  'type' => 'typeof',
                  'left' => 
                  array (
                    'type' => 'variable',
                    'value' => 'strategy',
                    'file' => '/app/phalcon/Mvc/Model/MetaData.zep',
                    'line' => 855,
                    'char' => 29,
                  ),
                  'file' => '/app/phalcon/Mvc/Model/MetaData.zep',
                  'line' => 855,
                  'char' => 29,
                ),
                'right' => 
                array (
                  'type' => 'string',
                  'value' => 'object',
                  'file' => '/app/phalcon/Mvc/Model/MetaData.zep',
                  'line' => 855,
                  'char' => 38,
                ),
                'file' => '/app/phalcon/Mvc/Model/MetaData.zep',
                'line' => 855,
                'char' => 38,
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
                      'variable' => 'container',
                      'expr' => 
                      array (
                        'type' => 'property-access',
                        'left' => 
                        array (
                          'type' => 'variable',
                          'value' => 'this',
                          'file' => '/app/phalcon/Mvc/Model/MetaData.zep',
                          'line' => 856,
                          'char' => 34,
                        ),
                        'right' => 
                        array (
                          'type' => 'variable',
                          'value' => 'container',
                          'file' => '/app/phalcon/Mvc/Model/MetaData.zep',
                          'line' => 856,
                          'char' => 44,
                        ),
                        'file' => '/app/phalcon/Mvc/Model/MetaData.zep',
                        'line' => 856,
                        'char' => 44,
                      ),
                      'file' => '/app/phalcon/Mvc/Model/MetaData.zep',
                      'line' => 856,
                      'char' => 44,
                    ),
                    1 => 
                    array (
                      'assign-type' => 'variable',
                      'operator' => 'assign',
                      'variable' => 'strategy',
                      'expr' => 
                      array (
                        'type' => 'mcall',
                        'variable' => 
                        array (
                          'type' => 'variable',
                          'value' => 'this',
                          'file' => '/app/phalcon/Mvc/Model/MetaData.zep',
                          'line' => 857,
                          'char' => 33,
                        ),
                        'name' => 'getStrategy',
                        'call-type' => 1,
                        'file' => '/app/phalcon/Mvc/Model/MetaData.zep',
                        'line' => 857,
                        'char' => 47,
                      ),
                      'file' => '/app/phalcon/Mvc/Model/MetaData.zep',
                      'line' => 857,
                      'char' => 47,
                    ),
                  ),
                  'file' => '/app/phalcon/Mvc/Model/MetaData.zep',
                  'line' => 858,
                  'char' => 9,
                ),
              ),
              'file' => '/app/phalcon/Mvc/Model/MetaData.zep',
              'line' => 864,
              'char' => 11,
            ),
            10 => 
            array (
              'type' => 'let',
              'assignments' => 
              array (
                0 => 
                array (
                  'assign-type' => 'variable',
                  'operator' => 'assign',
                  'variable' => 'modelColumnMap',
                  'expr' => 
                  array (
                    'type' => 'mcall',
                    'variable' => 
                    array (
                      'type' => 'variable',
                      'value' => 'strategy',
                      'file' => '/app/phalcon/Mvc/Model/MetaData.zep',
                      'line' => 864,
                      'char' => 39,
                    ),
                    'name' => 'getColumnMaps',
                    'call-type' => 1,
                    'parameters' => 
                    array (
                      0 => 
                      array (
                        'parameter' => 
                        array (
                          'type' => 'variable',
                          'value' => 'model',
                          'file' => '/app/phalcon/Mvc/Model/MetaData.zep',
                          'line' => 864,
                          'char' => 59,
                        ),
                        'file' => '/app/phalcon/Mvc/Model/MetaData.zep',
                        'line' => 864,
                        'char' => 59,
                      ),
                      1 => 
                      array (
                        'parameter' => 
                        array (
                          'type' => 'variable',
                          'value' => 'container',
                          'file' => '/app/phalcon/Mvc/Model/MetaData.zep',
                          'line' => 864,
                          'char' => 70,
                        ),
                        'file' => '/app/phalcon/Mvc/Model/MetaData.zep',
                        'line' => 864,
                        'char' => 70,
                      ),
                    ),
                    'file' => '/app/phalcon/Mvc/Model/MetaData.zep',
                    'line' => 864,
                    'char' => 71,
                  ),
                  'file' => '/app/phalcon/Mvc/Model/MetaData.zep',
                  'line' => 864,
                  'char' => 71,
                ),
                1 => 
                array (
                  'assign-type' => 'object-property-array-index',
                  'operator' => 'assign',
                  'variable' => 'this',
                  'property' => 'columnMap',
                  'index-expr' => 
                  array (
                    0 => 
                    array (
                      'type' => 'variable',
                      'value' => 'keyName',
                      'file' => '/app/phalcon/Mvc/Model/MetaData.zep',
                      'line' => 865,
                      'char' => 36,
                    ),
                  ),
                  'expr' => 
                  array (
                    'type' => 'variable',
                    'value' => 'modelColumnMap',
                    'file' => '/app/phalcon/Mvc/Model/MetaData.zep',
                    'line' => 865,
                    'char' => 54,
                  ),
                  'file' => '/app/phalcon/Mvc/Model/MetaData.zep',
                  'line' => 865,
                  'char' => 54,
                ),
              ),
              'file' => '/app/phalcon/Mvc/Model/MetaData.zep',
              'line' => 870,
              'char' => 12,
            ),
            11 => 
            array (
              'type' => 'mcall',
              'expr' => 
              array (
                'type' => 'mcall',
                'variable' => 
                array (
                  'type' => 'variable',
                  'value' => 'this',
                  'file' => '/app/phalcon/Mvc/Model/MetaData.zep',
                  'line' => 870,
                  'char' => 14,
                ),
                'name' => 'write',
                'call-type' => 3,
                'parameters' => 
                array (
                  0 => 
                  array (
                    'parameter' => 
                    array (
                      'type' => 'variable',
                      'value' => 'prefixKey',
                      'file' => '/app/phalcon/Mvc/Model/MetaData.zep',
                      'line' => 870,
                      'char' => 32,
                    ),
                    'file' => '/app/phalcon/Mvc/Model/MetaData.zep',
                    'line' => 870,
                    'char' => 32,
                  ),
                  1 => 
                  array (
                    'parameter' => 
                    array (
                      'type' => 'variable',
                      'value' => 'modelColumnMap',
                      'file' => '/app/phalcon/Mvc/Model/MetaData.zep',
                      'line' => 870,
                      'char' => 48,
                    ),
                    'file' => '/app/phalcon/Mvc/Model/MetaData.zep',
                    'line' => 870,
                    'char' => 48,
                  ),
                ),
                'file' => '/app/phalcon/Mvc/Model/MetaData.zep',
                'line' => 870,
                'char' => 49,
              ),
              'file' => '/app/phalcon/Mvc/Model/MetaData.zep',
              'line' => 871,
              'char' => 5,
            ),
          ),
          'docblock' => '**
     * Initialize the metadata for certain table
     *',
          'file' => '/app/phalcon/Mvc/Model/MetaData.zep',
          'line' => 768,
          'last-line' => 875,
          'char' => 28,
        ),
        32 => 
        array (
          'visibility' => 
          array (
            0 => 'private',
          ),
          'type' => 'method',
          'name' => 'throwWriteException',
          'parameters' => 
          array (
            0 => 
            array (
              'type' => 'parameter',
              'name' => 'option',
              'const' => 0,
              'data-type' => 'variable',
              'mandatory' => 0,
              'reference' => 0,
              'file' => '/app/phalcon/Mvc/Model/MetaData.zep',
              'line' => 876,
              'char' => 52,
            ),
          ),
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
                  'variable' => 'message',
                  'file' => '/app/phalcon/Mvc/Model/MetaData.zep',
                  'line' => 878,
                  'char' => 23,
                ),
              ),
              'file' => '/app/phalcon/Mvc/Model/MetaData.zep',
              'line' => 880,
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
                  'variable' => 'message',
                  'expr' => 
                  array (
                    'type' => 'string',
                    'value' => 'Failed to store metaData to the cache adapter',
                    'file' => '/app/phalcon/Mvc/Model/MetaData.zep',
                    'line' => 880,
                    'char' => 68,
                  ),
                  'file' => '/app/phalcon/Mvc/Model/MetaData.zep',
                  'line' => 880,
                  'char' => 68,
                ),
              ),
              'file' => '/app/phalcon/Mvc/Model/MetaData.zep',
              'line' => 882,
              'char' => 10,
            ),
            2 => 
            array (
              'type' => 'if',
              'expr' => 
              array (
                'type' => 'variable',
                'value' => 'option',
                'file' => '/app/phalcon/Mvc/Model/MetaData.zep',
                'line' => 882,
                'char' => 19,
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
                          'type' => 'variable',
                          'value' => 'message',
                          'file' => '/app/phalcon/Mvc/Model/MetaData.zep',
                          'line' => 883,
                          'char' => 40,
                        ),
                        'file' => '/app/phalcon/Mvc/Model/MetaData.zep',
                        'line' => 883,
                        'char' => 40,
                      ),
                    ),
                    'file' => '/app/phalcon/Mvc/Model/MetaData.zep',
                    'line' => 883,
                    'char' => 41,
                  ),
                  'file' => '/app/phalcon/Mvc/Model/MetaData.zep',
                  'line' => 884,
                  'char' => 9,
                ),
              ),
              'else_statements' => 
              array (
                0 => 
                array (
                  'type' => 'fcall',
                  'expr' => 
                  array (
                    'type' => 'fcall',
                    'name' => 'trigger_error',
                    'call-type' => 1,
                    'parameters' => 
                    array (
                      0 => 
                      array (
                        'parameter' => 
                        array (
                          'type' => 'variable',
                          'value' => 'message',
                          'file' => '/app/phalcon/Mvc/Model/MetaData.zep',
                          'line' => 885,
                          'char' => 34,
                        ),
                        'file' => '/app/phalcon/Mvc/Model/MetaData.zep',
                        'line' => 885,
                        'char' => 34,
                      ),
                    ),
                    'file' => '/app/phalcon/Mvc/Model/MetaData.zep',
                    'line' => 885,
                    'char' => 35,
                  ),
                  'file' => '/app/phalcon/Mvc/Model/MetaData.zep',
                  'line' => 886,
                  'char' => 9,
                ),
              ),
              'file' => '/app/phalcon/Mvc/Model/MetaData.zep',
              'line' => 887,
              'char' => 5,
            ),
          ),
          'docblock' => '**
     * Throws an exception when the metadata cannot be written
     *',
          'return-type' => 
          array (
            'type' => 'return-type',
            'void' => 1,
            'file' => '/app/phalcon/Mvc/Model/MetaData.zep',
            'line' => 877,
            'char' => 5,
          ),
          'file' => '/app/phalcon/Mvc/Model/MetaData.zep',
          'line' => 876,
          'last-line' => 888,
          'char' => 20,
        ),
      ),
      'constants' => 
      array (
        0 => 
        array (
          'type' => 'const',
          'name' => 'MODELS_ATTRIBUTES',
          'default' => 
          array (
            'type' => 'int',
            'value' => '0',
            'file' => '/app/phalcon/Mvc/Model/MetaData.zep',
            'line' => 43,
            'char' => 32,
          ),
          'file' => '/app/phalcon/Mvc/Model/MetaData.zep',
          'line' => 44,
          'char' => 9,
        ),
        1 => 
        array (
          'type' => 'const',
          'name' => 'MODELS_AUTOMATIC_DEFAULT_INSERT',
          'default' => 
          array (
            'type' => 'int',
            'value' => '10',
            'file' => '/app/phalcon/Mvc/Model/MetaData.zep',
            'line' => 44,
            'char' => 47,
          ),
          'file' => '/app/phalcon/Mvc/Model/MetaData.zep',
          'line' => 45,
          'char' => 9,
        ),
        2 => 
        array (
          'type' => 'const',
          'name' => 'MODELS_AUTOMATIC_DEFAULT_UPDATE',
          'default' => 
          array (
            'type' => 'int',
            'value' => '11',
            'file' => '/app/phalcon/Mvc/Model/MetaData.zep',
            'line' => 45,
            'char' => 47,
          ),
          'file' => '/app/phalcon/Mvc/Model/MetaData.zep',
          'line' => 46,
          'char' => 9,
        ),
        3 => 
        array (
          'type' => 'const',
          'name' => 'MODELS_COLUMN_MAP',
          'default' => 
          array (
            'type' => 'int',
            'value' => '0',
            'file' => '/app/phalcon/Mvc/Model/MetaData.zep',
            'line' => 46,
            'char' => 32,
          ),
          'file' => '/app/phalcon/Mvc/Model/MetaData.zep',
          'line' => 47,
          'char' => 9,
        ),
        4 => 
        array (
          'type' => 'const',
          'name' => 'MODELS_DATE_AT',
          'default' => 
          array (
            'type' => 'int',
            'value' => '6',
            'file' => '/app/phalcon/Mvc/Model/MetaData.zep',
            'line' => 47,
            'char' => 29,
          ),
          'file' => '/app/phalcon/Mvc/Model/MetaData.zep',
          'line' => 48,
          'char' => 9,
        ),
        5 => 
        array (
          'type' => 'const',
          'name' => 'MODELS_DATE_IN',
          'default' => 
          array (
            'type' => 'int',
            'value' => '7',
            'file' => '/app/phalcon/Mvc/Model/MetaData.zep',
            'line' => 48,
            'char' => 29,
          ),
          'file' => '/app/phalcon/Mvc/Model/MetaData.zep',
          'line' => 49,
          'char' => 9,
        ),
        6 => 
        array (
          'type' => 'const',
          'name' => 'MODELS_DATA_TYPES',
          'default' => 
          array (
            'type' => 'int',
            'value' => '4',
            'file' => '/app/phalcon/Mvc/Model/MetaData.zep',
            'line' => 49,
            'char' => 32,
          ),
          'file' => '/app/phalcon/Mvc/Model/MetaData.zep',
          'line' => 50,
          'char' => 9,
        ),
        7 => 
        array (
          'type' => 'const',
          'name' => 'MODELS_DATA_TYPES_BIND',
          'default' => 
          array (
            'type' => 'int',
            'value' => '9',
            'file' => '/app/phalcon/Mvc/Model/MetaData.zep',
            'line' => 50,
            'char' => 37,
          ),
          'file' => '/app/phalcon/Mvc/Model/MetaData.zep',
          'line' => 51,
          'char' => 9,
        ),
        8 => 
        array (
          'type' => 'const',
          'name' => 'MODELS_DATA_TYPES_NUMERIC',
          'default' => 
          array (
            'type' => 'int',
            'value' => '5',
            'file' => '/app/phalcon/Mvc/Model/MetaData.zep',
            'line' => 51,
            'char' => 40,
          ),
          'file' => '/app/phalcon/Mvc/Model/MetaData.zep',
          'line' => 52,
          'char' => 9,
        ),
        9 => 
        array (
          'type' => 'const',
          'name' => 'MODELS_DEFAULT_VALUES',
          'default' => 
          array (
            'type' => 'int',
            'value' => '12',
            'file' => '/app/phalcon/Mvc/Model/MetaData.zep',
            'line' => 52,
            'char' => 37,
          ),
          'file' => '/app/phalcon/Mvc/Model/MetaData.zep',
          'line' => 53,
          'char' => 9,
        ),
        10 => 
        array (
          'type' => 'const',
          'name' => 'MODELS_EMPTY_STRING_VALUES',
          'default' => 
          array (
            'type' => 'int',
            'value' => '13',
            'file' => '/app/phalcon/Mvc/Model/MetaData.zep',
            'line' => 53,
            'char' => 42,
          ),
          'file' => '/app/phalcon/Mvc/Model/MetaData.zep',
          'line' => 54,
          'char' => 9,
        ),
        11 => 
        array (
          'type' => 'const',
          'name' => 'MODELS_IDENTITY_COLUMN',
          'default' => 
          array (
            'type' => 'int',
            'value' => '8',
            'file' => '/app/phalcon/Mvc/Model/MetaData.zep',
            'line' => 54,
            'char' => 37,
          ),
          'file' => '/app/phalcon/Mvc/Model/MetaData.zep',
          'line' => 55,
          'char' => 9,
        ),
        12 => 
        array (
          'type' => 'const',
          'name' => 'MODELS_NON_PRIMARY_KEY',
          'default' => 
          array (
            'type' => 'int',
            'value' => '2',
            'file' => '/app/phalcon/Mvc/Model/MetaData.zep',
            'line' => 55,
            'char' => 37,
          ),
          'file' => '/app/phalcon/Mvc/Model/MetaData.zep',
          'line' => 56,
          'char' => 9,
        ),
        13 => 
        array (
          'type' => 'const',
          'name' => 'MODELS_NOT_NULL',
          'default' => 
          array (
            'type' => 'int',
            'value' => '3',
            'file' => '/app/phalcon/Mvc/Model/MetaData.zep',
            'line' => 56,
            'char' => 30,
          ),
          'file' => '/app/phalcon/Mvc/Model/MetaData.zep',
          'line' => 57,
          'char' => 9,
        ),
        14 => 
        array (
          'type' => 'const',
          'name' => 'MODELS_PRIMARY_KEY',
          'default' => 
          array (
            'type' => 'int',
            'value' => '1',
            'file' => '/app/phalcon/Mvc/Model/MetaData.zep',
            'line' => 57,
            'char' => 33,
          ),
          'file' => '/app/phalcon/Mvc/Model/MetaData.zep',
          'line' => 58,
          'char' => 9,
        ),
        15 => 
        array (
          'type' => 'const',
          'name' => 'MODELS_REVERSE_COLUMN_MAP',
          'default' => 
          array (
            'type' => 'int',
            'value' => '1',
            'file' => '/app/phalcon/Mvc/Model/MetaData.zep',
            'line' => 58,
            'char' => 40,
          ),
          'file' => '/app/phalcon/Mvc/Model/MetaData.zep',
          'line' => 62,
          'char' => 6,
        ),
      ),
      'file' => '/app/phalcon/Mvc/Model/MetaData.zep',
      'line' => 41,
      'char' => 14,
    ),
    'file' => '/app/phalcon/Mvc/Model/MetaData.zep',
    'line' => 41,
    'char' => 14,
  ),
);