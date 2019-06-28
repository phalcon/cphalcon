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
    'file' => '/app/phalcon/Annotations/Collection.zep',
    'line' => 11,
    'char' => 9,
  ),
  1 => 
  array (
    'type' => 'namespace',
    'name' => 'Phalcon\\Annotations',
    'file' => '/app/phalcon/Annotations/Collection.zep',
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
        'name' => 'Countable',
        'file' => '/app/phalcon/Annotations/Collection.zep',
        'line' => 13,
        'char' => 14,
      ),
    ),
    'file' => '/app/phalcon/Annotations/Collection.zep',
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
        'name' => 'Iterator',
        'file' => '/app/phalcon/Annotations/Collection.zep',
        'line' => 14,
        'char' => 13,
      ),
    ),
    'file' => '/app/phalcon/Annotations/Collection.zep',
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
        'name' => 'Phalcon\\Annotations\\Annotation',
        'file' => '/app/phalcon/Annotations/Collection.zep',
        'line' => 15,
        'char' => 35,
      ),
    ),
    'file' => '/app/phalcon/Annotations/Collection.zep',
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
        'name' => 'Phalcon\\Annotations\\Exception',
        'file' => '/app/phalcon/Annotations/Collection.zep',
        'line' => 16,
        'char' => 34,
      ),
    ),
    'file' => '/app/phalcon/Annotations/Collection.zep',
    'line' => 34,
    'char' => 2,
  ),
  6 => 
  array (
    'type' => 'comment',
    'value' => '**
 * Represents a collection of annotations. This class allows to traverse a group
 * of annotations easily
 *
 *```php
 * // Traverse annotations
 * foreach ($classAnnotations as $annotation) {
 *     echo "Name=", $annotation->getName(), PHP_EOL;
 * }
 *
 * // Check if the annotations has a specific
 * var_dump($classAnnotations->has("Cacheable"));
 *
 * // Get an specific annotation in the collection
 * $annotation = $classAnnotations->get("Cacheable");
 *```
 *',
    'file' => '/app/phalcon/Annotations/Collection.zep',
    'line' => 35,
    'char' => 5,
  ),
  7 => 
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
        'value' => 'Iterator',
        'file' => '/app/phalcon/Annotations/Collection.zep',
        'line' => 35,
        'char' => 37,
      ),
      1 => 
      array (
        'type' => 'variable',
        'value' => 'Countable',
        'file' => '/app/phalcon/Annotations/Collection.zep',
        'line' => 36,
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
          'name' => 'annotations',
          'docblock' => '**
     * @var array
     *',
          'file' => '/app/phalcon/Annotations/Collection.zep',
          'line' => 44,
          'char' => 6,
        ),
        1 => 
        array (
          'visibility' => 
          array (
            0 => 'protected',
          ),
          'type' => 'property',
          'name' => 'position',
          'default' => 
          array (
            'type' => 'int',
            'value' => '0',
            'file' => '/app/phalcon/Annotations/Collection.zep',
            'line' => 45,
            'char' => 27,
          ),
          'docblock' => '**
     * @var int
     *',
          'file' => '/app/phalcon/Annotations/Collection.zep',
          'line' => 49,
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
              'name' => 'reflectionData',
              'const' => 0,
              'data-type' => 'array',
              'mandatory' => 0,
              'default' => 
              array (
                'type' => 'empty-array',
                'file' => '/app/phalcon/Annotations/Collection.zep',
                'line' => 50,
                'char' => 58,
              ),
              'reference' => 0,
              'file' => '/app/phalcon/Annotations/Collection.zep',
              'line' => 50,
              'char' => 58,
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
                  'variable' => 'annotations',
                  'file' => '/app/phalcon/Annotations/Collection.zep',
                  'line' => 52,
                  'char' => 24,
                ),
                1 => 
                array (
                  'variable' => 'annotationData',
                  'file' => '/app/phalcon/Annotations/Collection.zep',
                  'line' => 52,
                  'char' => 40,
                ),
              ),
              'file' => '/app/phalcon/Annotations/Collection.zep',
              'line' => 54,
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
                  'variable' => 'annotations',
                  'expr' => 
                  array (
                    'type' => 'empty-array',
                    'file' => '/app/phalcon/Annotations/Collection.zep',
                    'line' => 54,
                    'char' => 29,
                  ),
                  'file' => '/app/phalcon/Annotations/Collection.zep',
                  'line' => 54,
                  'char' => 29,
                ),
              ),
              'file' => '/app/phalcon/Annotations/Collection.zep',
              'line' => 56,
              'char' => 11,
            ),
            2 => 
            array (
              'type' => 'for',
              'expr' => 
              array (
                'type' => 'variable',
                'value' => 'reflectionData',
                'file' => '/app/phalcon/Annotations/Collection.zep',
                'line' => 56,
                'char' => 46,
              ),
              'value' => 'annotationData',
              'reverse' => 0,
              'statements' => 
              array (
                0 => 
                array (
                  'type' => 'let',
                  'assignments' => 
                  array (
                    0 => 
                    array (
                      'assign-type' => 'variable-append',
                      'operator' => 'assign',
                      'variable' => 'annotations',
                      'expr' => 
                      array (
                        'type' => 'new',
                        'class' => 'Annotation',
                        'dynamic' => 0,
                        'parameters' => 
                        array (
                          0 => 
                          array (
                            'parameter' => 
                            array (
                              'type' => 'variable',
                              'value' => 'annotationData',
                              'file' => '/app/phalcon/Annotations/Collection.zep',
                              'line' => 57,
                              'char' => 62,
                            ),
                            'file' => '/app/phalcon/Annotations/Collection.zep',
                            'line' => 57,
                            'char' => 62,
                          ),
                        ),
                        'file' => '/app/phalcon/Annotations/Collection.zep',
                        'line' => 57,
                        'char' => 63,
                      ),
                      'file' => '/app/phalcon/Annotations/Collection.zep',
                      'line' => 57,
                      'char' => 63,
                    ),
                  ),
                  'file' => '/app/phalcon/Annotations/Collection.zep',
                  'line' => 58,
                  'char' => 9,
                ),
              ),
              'file' => '/app/phalcon/Annotations/Collection.zep',
              'line' => 60,
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
                  'property' => 'annotations',
                  'expr' => 
                  array (
                    'type' => 'variable',
                    'value' => 'annotations',
                    'file' => '/app/phalcon/Annotations/Collection.zep',
                    'line' => 60,
                    'char' => 44,
                  ),
                  'file' => '/app/phalcon/Annotations/Collection.zep',
                  'line' => 60,
                  'char' => 44,
                ),
              ),
              'file' => '/app/phalcon/Annotations/Collection.zep',
              'line' => 61,
              'char' => 5,
            ),
          ),
          'docblock' => '**
     * Phalcon\\Annotations\\Collection constructor
     *',
          'return-type' => 
          array (
            'type' => 'return-type',
            'void' => 1,
            'file' => '/app/phalcon/Annotations/Collection.zep',
            'line' => 51,
            'char' => 5,
          ),
          'file' => '/app/phalcon/Annotations/Collection.zep',
          'line' => 50,
          'last-line' => 65,
          'char' => 19,
        ),
        1 => 
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
                        'file' => '/app/phalcon/Annotations/Collection.zep',
                        'line' => 68,
                        'char' => 27,
                      ),
                      'right' => 
                      array (
                        'type' => 'variable',
                        'value' => 'annotations',
                        'file' => '/app/phalcon/Annotations/Collection.zep',
                        'line' => 68,
                        'char' => 39,
                      ),
                      'file' => '/app/phalcon/Annotations/Collection.zep',
                      'line' => 68,
                      'char' => 39,
                    ),
                    'file' => '/app/phalcon/Annotations/Collection.zep',
                    'line' => 68,
                    'char' => 39,
                  ),
                ),
                'file' => '/app/phalcon/Annotations/Collection.zep',
                'line' => 68,
                'char' => 40,
              ),
              'file' => '/app/phalcon/Annotations/Collection.zep',
              'line' => 69,
              'char' => 5,
            ),
          ),
          'docblock' => '**
     * Returns the number of annotations in the collection
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
                'file' => '/app/phalcon/Annotations/Collection.zep',
                'line' => 67,
                'char' => 5,
              ),
            ),
            'void' => 0,
            'file' => '/app/phalcon/Annotations/Collection.zep',
            'line' => 67,
            'char' => 5,
          ),
          'file' => '/app/phalcon/Annotations/Collection.zep',
          'line' => 66,
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
          'name' => 'current',
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
                  'variable' => 'annotation',
                  'file' => '/app/phalcon/Annotations/Collection.zep',
                  'line' => 76,
                  'char' => 23,
                ),
              ),
              'file' => '/app/phalcon/Annotations/Collection.zep',
              'line' => 78,
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
                    'value' => 'annotation',
                    'file' => '/app/phalcon/Annotations/Collection.zep',
                    'line' => 78,
                    'char' => 65,
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
                        'file' => '/app/phalcon/Annotations/Collection.zep',
                        'line' => 78,
                        'char' => 36,
                      ),
                      'right' => 
                      array (
                        'type' => 'variable',
                        'value' => 'annotations',
                        'file' => '/app/phalcon/Annotations/Collection.zep',
                        'line' => 78,
                        'char' => 48,
                      ),
                      'file' => '/app/phalcon/Annotations/Collection.zep',
                      'line' => 78,
                      'char' => 48,
                    ),
                    'right' => 
                    array (
                      'type' => 'property-access',
                      'left' => 
                      array (
                        'type' => 'variable',
                        'value' => 'this',
                        'file' => '/app/phalcon/Annotations/Collection.zep',
                        'line' => 78,
                        'char' => 54,
                      ),
                      'right' => 
                      array (
                        'type' => 'variable',
                        'value' => 'position',
                        'file' => '/app/phalcon/Annotations/Collection.zep',
                        'line' => 78,
                        'char' => 63,
                      ),
                      'file' => '/app/phalcon/Annotations/Collection.zep',
                      'line' => 78,
                      'char' => 63,
                    ),
                    'file' => '/app/phalcon/Annotations/Collection.zep',
                    'line' => 78,
                    'char' => 65,
                  ),
                  'file' => '/app/phalcon/Annotations/Collection.zep',
                  'line' => 78,
                  'char' => 65,
                ),
                'file' => '/app/phalcon/Annotations/Collection.zep',
                'line' => 78,
                'char' => 65,
              ),
              'statements' => 
              array (
                0 => 
                array (
                  'type' => 'return',
                  'expr' => 
                  array (
                    'type' => 'bool',
                    'value' => 'false',
                    'file' => '/app/phalcon/Annotations/Collection.zep',
                    'line' => 79,
                    'char' => 25,
                  ),
                  'file' => '/app/phalcon/Annotations/Collection.zep',
                  'line' => 80,
                  'char' => 9,
                ),
              ),
              'file' => '/app/phalcon/Annotations/Collection.zep',
              'line' => 82,
              'char' => 14,
            ),
            2 => 
            array (
              'type' => 'return',
              'expr' => 
              array (
                'type' => 'variable',
                'value' => 'annotation',
                'file' => '/app/phalcon/Annotations/Collection.zep',
                'line' => 82,
                'char' => 26,
              ),
              'file' => '/app/phalcon/Annotations/Collection.zep',
              'line' => 83,
              'char' => 5,
            ),
          ),
          'docblock' => '**
     * Returns the current annotation in the iterator
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
                  'value' => 'Annotation',
                  'file' => '/app/phalcon/Annotations/Collection.zep',
                  'line' => 74,
                  'char' => 47,
                ),
                'collection' => 0,
                'file' => '/app/phalcon/Annotations/Collection.zep',
                'line' => 74,
                'char' => 47,
              ),
              1 => 
              array (
                'type' => 'return-type-parameter',
                'data-type' => 'bool',
                'mandatory' => 0,
                'file' => '/app/phalcon/Annotations/Collection.zep',
                'line' => 75,
                'char' => 5,
              ),
            ),
            'void' => 0,
            'file' => '/app/phalcon/Annotations/Collection.zep',
            'line' => 75,
            'char' => 5,
          ),
          'file' => '/app/phalcon/Annotations/Collection.zep',
          'line' => 74,
          'last-line' => 87,
          'char' => 19,
        ),
        3 => 
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
              'mandatory' => 0,
              'reference' => 0,
              'file' => '/app/phalcon/Annotations/Collection.zep',
              'line' => 88,
              'char' => 36,
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
                  'variable' => 'annotation',
                  'file' => '/app/phalcon/Annotations/Collection.zep',
                  'line' => 90,
                  'char' => 23,
                ),
                1 => 
                array (
                  'variable' => 'annotations',
                  'file' => '/app/phalcon/Annotations/Collection.zep',
                  'line' => 90,
                  'char' => 36,
                ),
              ),
              'file' => '/app/phalcon/Annotations/Collection.zep',
              'line' => 92,
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
                  'variable' => 'annotations',
                  'expr' => 
                  array (
                    'type' => 'property-access',
                    'left' => 
                    array (
                      'type' => 'variable',
                      'value' => 'this',
                      'file' => '/app/phalcon/Annotations/Collection.zep',
                      'line' => 92,
                      'char' => 32,
                    ),
                    'right' => 
                    array (
                      'type' => 'variable',
                      'value' => 'annotations',
                      'file' => '/app/phalcon/Annotations/Collection.zep',
                      'line' => 92,
                      'char' => 44,
                    ),
                    'file' => '/app/phalcon/Annotations/Collection.zep',
                    'line' => 92,
                    'char' => 44,
                  ),
                  'file' => '/app/phalcon/Annotations/Collection.zep',
                  'line' => 92,
                  'char' => 44,
                ),
              ),
              'file' => '/app/phalcon/Annotations/Collection.zep',
              'line' => 94,
              'char' => 11,
            ),
            2 => 
            array (
              'type' => 'for',
              'expr' => 
              array (
                'type' => 'variable',
                'value' => 'annotations',
                'file' => '/app/phalcon/Annotations/Collection.zep',
                'line' => 94,
                'char' => 39,
              ),
              'value' => 'annotation',
              'reverse' => 0,
              'statements' => 
              array (
                0 => 
                array (
                  'type' => 'if',
                  'expr' => 
                  array (
                    'type' => 'equals',
                    'left' => 
                    array (
                      'type' => 'variable',
                      'value' => 'name',
                      'file' => '/app/phalcon/Annotations/Collection.zep',
                      'line' => 95,
                      'char' => 22,
                    ),
                    'right' => 
                    array (
                      'type' => 'mcall',
                      'variable' => 
                      array (
                        'type' => 'variable',
                        'value' => 'annotation',
                        'file' => '/app/phalcon/Annotations/Collection.zep',
                        'line' => 95,
                        'char' => 35,
                      ),
                      'name' => 'getName',
                      'call-type' => 1,
                      'file' => '/app/phalcon/Annotations/Collection.zep',
                      'line' => 95,
                      'char' => 46,
                    ),
                    'file' => '/app/phalcon/Annotations/Collection.zep',
                    'line' => 95,
                    'char' => 46,
                  ),
                  'statements' => 
                  array (
                    0 => 
                    array (
                      'type' => 'return',
                      'expr' => 
                      array (
                        'type' => 'variable',
                        'value' => 'annotation',
                        'file' => '/app/phalcon/Annotations/Collection.zep',
                        'line' => 96,
                        'char' => 34,
                      ),
                      'file' => '/app/phalcon/Annotations/Collection.zep',
                      'line' => 97,
                      'char' => 13,
                    ),
                  ),
                  'file' => '/app/phalcon/Annotations/Collection.zep',
                  'line' => 98,
                  'char' => 9,
                ),
              ),
              'file' => '/app/phalcon/Annotations/Collection.zep',
              'line' => 100,
              'char' => 13,
            ),
            3 => 
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
                        'type' => 'concat',
                        'left' => 
                        array (
                          'type' => 'string',
                          'value' => 'Collection doesn\'t have an annotation called \'',
                          'file' => '/app/phalcon/Annotations/Collection.zep',
                          'line' => 101,
                          'char' => 60,
                        ),
                        'right' => 
                        array (
                          'type' => 'variable',
                          'value' => 'name',
                          'file' => '/app/phalcon/Annotations/Collection.zep',
                          'line' => 101,
                          'char' => 67,
                        ),
                        'file' => '/app/phalcon/Annotations/Collection.zep',
                        'line' => 101,
                        'char' => 67,
                      ),
                      'right' => 
                      array (
                        'type' => 'string',
                        'value' => '\'',
                        'file' => '/app/phalcon/Annotations/Collection.zep',
                        'line' => 102,
                        'char' => 9,
                      ),
                      'file' => '/app/phalcon/Annotations/Collection.zep',
                      'line' => 102,
                      'char' => 9,
                    ),
                    'file' => '/app/phalcon/Annotations/Collection.zep',
                    'line' => 102,
                    'char' => 9,
                  ),
                ),
                'file' => '/app/phalcon/Annotations/Collection.zep',
                'line' => 102,
                'char' => 10,
              ),
              'file' => '/app/phalcon/Annotations/Collection.zep',
              'line' => 103,
              'char' => 5,
            ),
          ),
          'docblock' => '**
     * Returns the first annotation that match a name
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
                  'value' => 'Annotation',
                  'file' => '/app/phalcon/Annotations/Collection.zep',
                  'line' => 89,
                  'char' => 5,
                ),
                'collection' => 0,
                'file' => '/app/phalcon/Annotations/Collection.zep',
                'line' => 89,
                'char' => 5,
              ),
            ),
            'void' => 0,
            'file' => '/app/phalcon/Annotations/Collection.zep',
            'line' => 89,
            'char' => 5,
          ),
          'file' => '/app/phalcon/Annotations/Collection.zep',
          'line' => 88,
          'last-line' => 107,
          'char' => 19,
        ),
        4 => 
        array (
          'visibility' => 
          array (
            0 => 'public',
          ),
          'type' => 'method',
          'name' => 'getAll',
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
              'file' => '/app/phalcon/Annotations/Collection.zep',
              'line' => 108,
              'char' => 39,
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
                  'variable' => 'annotations',
                  'file' => '/app/phalcon/Annotations/Collection.zep',
                  'line' => 110,
                  'char' => 24,
                ),
                1 => 
                array (
                  'variable' => 'annotation',
                  'file' => '/app/phalcon/Annotations/Collection.zep',
                  'line' => 110,
                  'char' => 36,
                ),
              ),
              'file' => '/app/phalcon/Annotations/Collection.zep',
              'line' => 111,
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
                  'variable' => 'found',
                  'file' => '/app/phalcon/Annotations/Collection.zep',
                  'line' => 111,
                  'char' => 20,
                ),
              ),
              'file' => '/app/phalcon/Annotations/Collection.zep',
              'line' => 113,
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
                  'variable' => 'found',
                  'expr' => 
                  array (
                    'type' => 'empty-array',
                    'file' => '/app/phalcon/Annotations/Collection.zep',
                    'line' => 113,
                    'char' => 23,
                  ),
                  'file' => '/app/phalcon/Annotations/Collection.zep',
                  'line' => 113,
                  'char' => 23,
                ),
                1 => 
                array (
                  'assign-type' => 'variable',
                  'operator' => 'assign',
                  'variable' => 'annotations',
                  'expr' => 
                  array (
                    'type' => 'property-access',
                    'left' => 
                    array (
                      'type' => 'variable',
                      'value' => 'this',
                      'file' => '/app/phalcon/Annotations/Collection.zep',
                      'line' => 114,
                      'char' => 32,
                    ),
                    'right' => 
                    array (
                      'type' => 'variable',
                      'value' => 'annotations',
                      'file' => '/app/phalcon/Annotations/Collection.zep',
                      'line' => 114,
                      'char' => 44,
                    ),
                    'file' => '/app/phalcon/Annotations/Collection.zep',
                    'line' => 114,
                    'char' => 44,
                  ),
                  'file' => '/app/phalcon/Annotations/Collection.zep',
                  'line' => 114,
                  'char' => 44,
                ),
              ),
              'file' => '/app/phalcon/Annotations/Collection.zep',
              'line' => 116,
              'char' => 11,
            ),
            3 => 
            array (
              'type' => 'for',
              'expr' => 
              array (
                'type' => 'variable',
                'value' => 'annotations',
                'file' => '/app/phalcon/Annotations/Collection.zep',
                'line' => 116,
                'char' => 39,
              ),
              'value' => 'annotation',
              'reverse' => 0,
              'statements' => 
              array (
                0 => 
                array (
                  'type' => 'if',
                  'expr' => 
                  array (
                    'type' => 'equals',
                    'left' => 
                    array (
                      'type' => 'variable',
                      'value' => 'name',
                      'file' => '/app/phalcon/Annotations/Collection.zep',
                      'line' => 117,
                      'char' => 22,
                    ),
                    'right' => 
                    array (
                      'type' => 'mcall',
                      'variable' => 
                      array (
                        'type' => 'variable',
                        'value' => 'annotation',
                        'file' => '/app/phalcon/Annotations/Collection.zep',
                        'line' => 117,
                        'char' => 35,
                      ),
                      'name' => 'getName',
                      'call-type' => 1,
                      'file' => '/app/phalcon/Annotations/Collection.zep',
                      'line' => 117,
                      'char' => 46,
                    ),
                    'file' => '/app/phalcon/Annotations/Collection.zep',
                    'line' => 117,
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
                          'assign-type' => 'variable-append',
                          'operator' => 'assign',
                          'variable' => 'found',
                          'expr' => 
                          array (
                            'type' => 'variable',
                            'value' => 'annotation',
                            'file' => '/app/phalcon/Annotations/Collection.zep',
                            'line' => 118,
                            'char' => 41,
                          ),
                          'file' => '/app/phalcon/Annotations/Collection.zep',
                          'line' => 118,
                          'char' => 41,
                        ),
                      ),
                      'file' => '/app/phalcon/Annotations/Collection.zep',
                      'line' => 119,
                      'char' => 13,
                    ),
                  ),
                  'file' => '/app/phalcon/Annotations/Collection.zep',
                  'line' => 120,
                  'char' => 9,
                ),
              ),
              'file' => '/app/phalcon/Annotations/Collection.zep',
              'line' => 122,
              'char' => 14,
            ),
            4 => 
            array (
              'type' => 'return',
              'expr' => 
              array (
                'type' => 'variable',
                'value' => 'found',
                'file' => '/app/phalcon/Annotations/Collection.zep',
                'line' => 122,
                'char' => 21,
              ),
              'file' => '/app/phalcon/Annotations/Collection.zep',
              'line' => 123,
              'char' => 5,
            ),
          ),
          'docblock' => '**
     * Returns all the annotations that match a name
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
                  'value' => 'Annotation',
                  'file' => '/app/phalcon/Annotations/Collection.zep',
                  'line' => 109,
                  'char' => 5,
                ),
                'collection' => 1,
                'file' => '/app/phalcon/Annotations/Collection.zep',
                'line' => 109,
                'char' => 5,
              ),
            ),
            'void' => 0,
            'file' => '/app/phalcon/Annotations/Collection.zep',
            'line' => 109,
            'char' => 5,
          ),
          'file' => '/app/phalcon/Annotations/Collection.zep',
          'line' => 108,
          'last-line' => 127,
          'char' => 19,
        ),
        5 => 
        array (
          'visibility' => 
          array (
            0 => 'public',
          ),
          'type' => 'method',
          'name' => 'getAnnotations',
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
                  'file' => '/app/phalcon/Annotations/Collection.zep',
                  'line' => 130,
                  'char' => 21,
                ),
                'right' => 
                array (
                  'type' => 'variable',
                  'value' => 'annotations',
                  'file' => '/app/phalcon/Annotations/Collection.zep',
                  'line' => 130,
                  'char' => 33,
                ),
                'file' => '/app/phalcon/Annotations/Collection.zep',
                'line' => 130,
                'char' => 33,
              ),
              'file' => '/app/phalcon/Annotations/Collection.zep',
              'line' => 131,
              'char' => 5,
            ),
          ),
          'docblock' => '**
     * Returns the internal annotations as an array
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
                  'value' => 'Annotation',
                  'file' => '/app/phalcon/Annotations/Collection.zep',
                  'line' => 129,
                  'char' => 5,
                ),
                'collection' => 1,
                'file' => '/app/phalcon/Annotations/Collection.zep',
                'line' => 129,
                'char' => 5,
              ),
            ),
            'void' => 0,
            'file' => '/app/phalcon/Annotations/Collection.zep',
            'line' => 129,
            'char' => 5,
          ),
          'file' => '/app/phalcon/Annotations/Collection.zep',
          'line' => 128,
          'last-line' => 135,
          'char' => 19,
        ),
        6 => 
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
              'mandatory' => 0,
              'reference' => 0,
              'file' => '/app/phalcon/Annotations/Collection.zep',
              'line' => 136,
              'char' => 36,
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
                  'variable' => 'annotations',
                  'file' => '/app/phalcon/Annotations/Collection.zep',
                  'line' => 138,
                  'char' => 24,
                ),
                1 => 
                array (
                  'variable' => 'annotation',
                  'file' => '/app/phalcon/Annotations/Collection.zep',
                  'line' => 138,
                  'char' => 36,
                ),
              ),
              'file' => '/app/phalcon/Annotations/Collection.zep',
              'line' => 140,
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
                  'variable' => 'annotations',
                  'expr' => 
                  array (
                    'type' => 'property-access',
                    'left' => 
                    array (
                      'type' => 'variable',
                      'value' => 'this',
                      'file' => '/app/phalcon/Annotations/Collection.zep',
                      'line' => 140,
                      'char' => 32,
                    ),
                    'right' => 
                    array (
                      'type' => 'variable',
                      'value' => 'annotations',
                      'file' => '/app/phalcon/Annotations/Collection.zep',
                      'line' => 140,
                      'char' => 44,
                    ),
                    'file' => '/app/phalcon/Annotations/Collection.zep',
                    'line' => 140,
                    'char' => 44,
                  ),
                  'file' => '/app/phalcon/Annotations/Collection.zep',
                  'line' => 140,
                  'char' => 44,
                ),
              ),
              'file' => '/app/phalcon/Annotations/Collection.zep',
              'line' => 142,
              'char' => 11,
            ),
            2 => 
            array (
              'type' => 'for',
              'expr' => 
              array (
                'type' => 'variable',
                'value' => 'annotations',
                'file' => '/app/phalcon/Annotations/Collection.zep',
                'line' => 142,
                'char' => 39,
              ),
              'value' => 'annotation',
              'reverse' => 0,
              'statements' => 
              array (
                0 => 
                array (
                  'type' => 'if',
                  'expr' => 
                  array (
                    'type' => 'equals',
                    'left' => 
                    array (
                      'type' => 'variable',
                      'value' => 'name',
                      'file' => '/app/phalcon/Annotations/Collection.zep',
                      'line' => 143,
                      'char' => 22,
                    ),
                    'right' => 
                    array (
                      'type' => 'mcall',
                      'variable' => 
                      array (
                        'type' => 'variable',
                        'value' => 'annotation',
                        'file' => '/app/phalcon/Annotations/Collection.zep',
                        'line' => 143,
                        'char' => 35,
                      ),
                      'name' => 'getName',
                      'call-type' => 1,
                      'file' => '/app/phalcon/Annotations/Collection.zep',
                      'line' => 143,
                      'char' => 46,
                    ),
                    'file' => '/app/phalcon/Annotations/Collection.zep',
                    'line' => 143,
                    'char' => 46,
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
                        'file' => '/app/phalcon/Annotations/Collection.zep',
                        'line' => 144,
                        'char' => 28,
                      ),
                      'file' => '/app/phalcon/Annotations/Collection.zep',
                      'line' => 145,
                      'char' => 13,
                    ),
                  ),
                  'file' => '/app/phalcon/Annotations/Collection.zep',
                  'line' => 146,
                  'char' => 9,
                ),
              ),
              'file' => '/app/phalcon/Annotations/Collection.zep',
              'line' => 148,
              'char' => 14,
            ),
            3 => 
            array (
              'type' => 'return',
              'expr' => 
              array (
                'type' => 'bool',
                'value' => 'false',
                'file' => '/app/phalcon/Annotations/Collection.zep',
                'line' => 148,
                'char' => 21,
              ),
              'file' => '/app/phalcon/Annotations/Collection.zep',
              'line' => 149,
              'char' => 5,
            ),
          ),
          'docblock' => '**
     * Check if an annotation exists in a collection
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
                'file' => '/app/phalcon/Annotations/Collection.zep',
                'line' => 137,
                'char' => 5,
              ),
            ),
            'void' => 0,
            'file' => '/app/phalcon/Annotations/Collection.zep',
            'line' => 137,
            'char' => 5,
          ),
          'file' => '/app/phalcon/Annotations/Collection.zep',
          'line' => 136,
          'last-line' => 153,
          'char' => 19,
        ),
        7 => 
        array (
          'visibility' => 
          array (
            0 => 'public',
          ),
          'type' => 'method',
          'name' => 'key',
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
                  'file' => '/app/phalcon/Annotations/Collection.zep',
                  'line' => 156,
                  'char' => 21,
                ),
                'right' => 
                array (
                  'type' => 'variable',
                  'value' => 'position',
                  'file' => '/app/phalcon/Annotations/Collection.zep',
                  'line' => 156,
                  'char' => 30,
                ),
                'file' => '/app/phalcon/Annotations/Collection.zep',
                'line' => 156,
                'char' => 30,
              ),
              'file' => '/app/phalcon/Annotations/Collection.zep',
              'line' => 157,
              'char' => 5,
            ),
          ),
          'docblock' => '**
     * Returns the current position/key in the iterator
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
                'file' => '/app/phalcon/Annotations/Collection.zep',
                'line' => 155,
                'char' => 5,
              ),
            ),
            'void' => 0,
            'file' => '/app/phalcon/Annotations/Collection.zep',
            'line' => 155,
            'char' => 5,
          ),
          'file' => '/app/phalcon/Annotations/Collection.zep',
          'line' => 154,
          'last-line' => 161,
          'char' => 19,
        ),
        8 => 
        array (
          'visibility' => 
          array (
            0 => 'public',
          ),
          'type' => 'method',
          'name' => 'next',
          'statements' => 
          array (
            0 => 
            array (
              'type' => 'let',
              'assignments' => 
              array (
                0 => 
                array (
                  'assign-type' => 'object-property-incr',
                  'variable' => 'this',
                  'property' => 'position',
                  'file' => '/app/phalcon/Annotations/Collection.zep',
                  'line' => 164,
                  'char' => 29,
                ),
              ),
              'file' => '/app/phalcon/Annotations/Collection.zep',
              'line' => 165,
              'char' => 5,
            ),
          ),
          'docblock' => '**
     * Moves the internal iteration pointer to the next position
     *',
          'return-type' => 
          array (
            'type' => 'return-type',
            'void' => 1,
            'file' => '/app/phalcon/Annotations/Collection.zep',
            'line' => 163,
            'char' => 5,
          ),
          'file' => '/app/phalcon/Annotations/Collection.zep',
          'line' => 162,
          'last-line' => 169,
          'char' => 19,
        ),
        9 => 
        array (
          'visibility' => 
          array (
            0 => 'public',
          ),
          'type' => 'method',
          'name' => 'rewind',
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
                  'property' => 'position',
                  'expr' => 
                  array (
                    'type' => 'int',
                    'value' => '0',
                    'file' => '/app/phalcon/Annotations/Collection.zep',
                    'line' => 172,
                    'char' => 31,
                  ),
                  'file' => '/app/phalcon/Annotations/Collection.zep',
                  'line' => 172,
                  'char' => 31,
                ),
              ),
              'file' => '/app/phalcon/Annotations/Collection.zep',
              'line' => 173,
              'char' => 5,
            ),
          ),
          'docblock' => '**
     * Rewinds the internal iterator
     *',
          'return-type' => 
          array (
            'type' => 'return-type',
            'void' => 1,
            'file' => '/app/phalcon/Annotations/Collection.zep',
            'line' => 171,
            'char' => 5,
          ),
          'file' => '/app/phalcon/Annotations/Collection.zep',
          'line' => 170,
          'last-line' => 177,
          'char' => 19,
        ),
        10 => 
        array (
          'visibility' => 
          array (
            0 => 'public',
          ),
          'type' => 'method',
          'name' => 'valid',
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
                    'type' => 'property-access',
                    'left' => 
                    array (
                      'type' => 'variable',
                      'value' => 'this',
                      'file' => '/app/phalcon/Annotations/Collection.zep',
                      'line' => 180,
                      'char' => 27,
                    ),
                    'right' => 
                    array (
                      'type' => 'variable',
                      'value' => 'annotations',
                      'file' => '/app/phalcon/Annotations/Collection.zep',
                      'line' => 180,
                      'char' => 39,
                    ),
                    'file' => '/app/phalcon/Annotations/Collection.zep',
                    'line' => 180,
                    'char' => 39,
                  ),
                  'right' => 
                  array (
                    'type' => 'property-access',
                    'left' => 
                    array (
                      'type' => 'variable',
                      'value' => 'this',
                      'file' => '/app/phalcon/Annotations/Collection.zep',
                      'line' => 180,
                      'char' => 45,
                    ),
                    'right' => 
                    array (
                      'type' => 'variable',
                      'value' => 'position',
                      'file' => '/app/phalcon/Annotations/Collection.zep',
                      'line' => 180,
                      'char' => 54,
                    ),
                    'file' => '/app/phalcon/Annotations/Collection.zep',
                    'line' => 180,
                    'char' => 54,
                  ),
                  'file' => '/app/phalcon/Annotations/Collection.zep',
                  'line' => 180,
                  'char' => 55,
                ),
                'file' => '/app/phalcon/Annotations/Collection.zep',
                'line' => 180,
                'char' => 55,
              ),
              'file' => '/app/phalcon/Annotations/Collection.zep',
              'line' => 181,
              'char' => 5,
            ),
          ),
          'docblock' => '**
     * Check if the current annotation in the iterator is valid
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
                'file' => '/app/phalcon/Annotations/Collection.zep',
                'line' => 179,
                'char' => 5,
              ),
            ),
            'void' => 0,
            'file' => '/app/phalcon/Annotations/Collection.zep',
            'line' => 179,
            'char' => 5,
          ),
          'file' => '/app/phalcon/Annotations/Collection.zep',
          'line' => 178,
          'last-line' => 182,
          'char' => 19,
        ),
      ),
      'file' => '/app/phalcon/Annotations/Collection.zep',
      'line' => 35,
      'char' => 5,
    ),
    'file' => '/app/phalcon/Annotations/Collection.zep',
    'line' => 35,
    'char' => 5,
  ),
);