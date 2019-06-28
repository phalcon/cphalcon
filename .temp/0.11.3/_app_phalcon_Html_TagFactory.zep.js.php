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
    'file' => '/app/phalcon/Html/TagFactory.zep',
    'line' => 11,
    'char' => 9,
  ),
  1 => 
  array (
    'type' => 'namespace',
    'name' => 'Phalcon\\Html',
    'file' => '/app/phalcon/Html/TagFactory.zep',
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
        'name' => 'Phalcon\\Escaper',
        'file' => '/app/phalcon/Html/TagFactory.zep',
        'line' => 13,
        'char' => 20,
      ),
    ),
    'file' => '/app/phalcon/Html/TagFactory.zep',
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
        'name' => 'Phalcon\\EscaperInterface',
        'file' => '/app/phalcon/Html/TagFactory.zep',
        'line' => 14,
        'char' => 29,
      ),
    ),
    'file' => '/app/phalcon/Html/TagFactory.zep',
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
        'name' => 'Phalcon\\Factory\\AbstractFactory',
        'file' => '/app/phalcon/Html/TagFactory.zep',
        'line' => 15,
        'char' => 36,
      ),
    ),
    'file' => '/app/phalcon/Html/TagFactory.zep',
    'line' => 19,
    'char' => 2,
  ),
  5 => 
  array (
    'type' => 'comment',
    'value' => '**
 * ServiceLocator implementation for Tag helpers
 *',
    'file' => '/app/phalcon/Html/TagFactory.zep',
    'line' => 20,
    'char' => 5,
  ),
  6 => 
  array (
    'type' => 'class',
    'name' => 'TagFactory',
    'abstract' => 0,
    'final' => 0,
    'extends' => 'AbstractFactory',
    'definition' => 
    array (
      'properties' => 
      array (
        0 => 
        array (
          'visibility' => 
          array (
            0 => 'private',
          ),
          'type' => 'property',
          'name' => 'escaper',
          'docblock' => '**
     * @var <EscaperInterface>
     *',
          'file' => '/app/phalcon/Html/TagFactory.zep',
          'line' => 29,
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
              'name' => 'escaper',
              'const' => 0,
              'data-type' => 'variable',
              'mandatory' => 0,
              'cast' => 
              array (
                'type' => 'variable',
                'value' => 'EscaperInterface',
                'file' => '/app/phalcon/Html/TagFactory.zep',
                'line' => 30,
                'char' => 58,
              ),
              'reference' => 0,
              'file' => '/app/phalcon/Html/TagFactory.zep',
              'line' => 30,
              'char' => 59,
            ),
            1 => 
            array (
              'type' => 'parameter',
              'name' => 'services',
              'const' => 0,
              'data-type' => 'array',
              'mandatory' => 1,
              'default' => 
              array (
                'type' => 'empty-array',
                'file' => '/app/phalcon/Html/TagFactory.zep',
                'line' => 30,
                'char' => 81,
              ),
              'reference' => 0,
              'file' => '/app/phalcon/Html/TagFactory.zep',
              'line' => 30,
              'char' => 81,
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
                  'property' => 'escaper',
                  'expr' => 
                  array (
                    'type' => 'variable',
                    'value' => 'escaper',
                    'file' => '/app/phalcon/Html/TagFactory.zep',
                    'line' => 32,
                    'char' => 36,
                  ),
                  'file' => '/app/phalcon/Html/TagFactory.zep',
                  'line' => 32,
                  'char' => 36,
                ),
              ),
              'file' => '/app/phalcon/Html/TagFactory.zep',
              'line' => 34,
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
                  'file' => '/app/phalcon/Html/TagFactory.zep',
                  'line' => 34,
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
                      'value' => 'services',
                      'file' => '/app/phalcon/Html/TagFactory.zep',
                      'line' => 34,
                      'char' => 28,
                    ),
                    'file' => '/app/phalcon/Html/TagFactory.zep',
                    'line' => 34,
                    'char' => 28,
                  ),
                ),
                'file' => '/app/phalcon/Html/TagFactory.zep',
                'line' => 34,
                'char' => 29,
              ),
              'file' => '/app/phalcon/Html/TagFactory.zep',
              'line' => 35,
              'char' => 5,
            ),
          ),
          'docblock' => '**
     * TagFactory constructor.
     *',
          'file' => '/app/phalcon/Html/TagFactory.zep',
          'line' => 30,
          'last-line' => 42,
          'char' => 19,
        ),
        1 => 
        array (
          'visibility' => 
          array (
            0 => 'public',
          ),
          'type' => 'method',
          'name' => 'newInstance',
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
              'file' => '/app/phalcon/Html/TagFactory.zep',
              'line' => 43,
              'char' => 44,
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
                  'variable' => 'definition',
                  'file' => '/app/phalcon/Html/TagFactory.zep',
                  'line' => 45,
                  'char' => 23,
                ),
              ),
              'file' => '/app/phalcon/Html/TagFactory.zep',
              'line' => 47,
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
                  'file' => '/app/phalcon/Html/TagFactory.zep',
                  'line' => 47,
                  'char' => 14,
                ),
                'name' => 'checkService',
                'call-type' => 1,
                'parameters' => 
                array (
                  0 => 
                  array (
                    'parameter' => 
                    array (
                      'type' => 'variable',
                      'value' => 'name',
                      'file' => '/app/phalcon/Html/TagFactory.zep',
                      'line' => 47,
                      'char' => 32,
                    ),
                    'file' => '/app/phalcon/Html/TagFactory.zep',
                    'line' => 47,
                    'char' => 32,
                  ),
                ),
                'file' => '/app/phalcon/Html/TagFactory.zep',
                'line' => 47,
                'char' => 33,
              ),
              'file' => '/app/phalcon/Html/TagFactory.zep',
              'line' => 49,
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
                        'file' => '/app/phalcon/Html/TagFactory.zep',
                        'line' => 49,
                        'char' => 24,
                      ),
                      'right' => 
                      array (
                        'type' => 'variable',
                        'value' => 'services',
                        'file' => '/app/phalcon/Html/TagFactory.zep',
                        'line' => 49,
                        'char' => 33,
                      ),
                      'file' => '/app/phalcon/Html/TagFactory.zep',
                      'line' => 49,
                      'char' => 33,
                    ),
                    'right' => 
                    array (
                      'type' => 'variable',
                      'value' => 'name',
                      'file' => '/app/phalcon/Html/TagFactory.zep',
                      'line' => 49,
                      'char' => 38,
                    ),
                    'file' => '/app/phalcon/Html/TagFactory.zep',
                    'line' => 49,
                    'char' => 40,
                  ),
                  'file' => '/app/phalcon/Html/TagFactory.zep',
                  'line' => 49,
                  'char' => 40,
                ),
                'file' => '/app/phalcon/Html/TagFactory.zep',
                'line' => 49,
                'char' => 40,
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
                      'variable' => 'definition',
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
                            'file' => '/app/phalcon/Html/TagFactory.zep',
                            'line' => 50,
                            'char' => 45,
                          ),
                          'right' => 
                          array (
                            'type' => 'variable',
                            'value' => 'mapper',
                            'file' => '/app/phalcon/Html/TagFactory.zep',
                            'line' => 50,
                            'char' => 52,
                          ),
                          'file' => '/app/phalcon/Html/TagFactory.zep',
                          'line' => 50,
                          'char' => 52,
                        ),
                        'right' => 
                        array (
                          'type' => 'variable',
                          'value' => 'name',
                          'file' => '/app/phalcon/Html/TagFactory.zep',
                          'line' => 50,
                          'char' => 57,
                        ),
                        'file' => '/app/phalcon/Html/TagFactory.zep',
                        'line' => 50,
                        'char' => 58,
                      ),
                      'file' => '/app/phalcon/Html/TagFactory.zep',
                      'line' => 50,
                      'char' => 58,
                    ),
                    1 => 
                    array (
                      'assign-type' => 'object-property-array-index',
                      'operator' => 'assign',
                      'variable' => 'this',
                      'property' => 'services',
                      'index-expr' => 
                      array (
                        0 => 
                        array (
                          'type' => 'variable',
                          'value' => 'name',
                          'file' => '/app/phalcon/Html/TagFactory.zep',
                          'line' => 51,
                          'char' => 36,
                        ),
                      ),
                      'expr' => 
                      array (
                        'type' => 'new',
                        'class' => 'definition',
                        'dynamic' => 1,
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
                                'file' => '/app/phalcon/Html/TagFactory.zep',
                                'line' => 51,
                                'char' => 62,
                              ),
                              'right' => 
                              array (
                                'type' => 'variable',
                                'value' => 'escaper',
                                'file' => '/app/phalcon/Html/TagFactory.zep',
                                'line' => 51,
                                'char' => 70,
                              ),
                              'file' => '/app/phalcon/Html/TagFactory.zep',
                              'line' => 51,
                              'char' => 70,
                            ),
                            'file' => '/app/phalcon/Html/TagFactory.zep',
                            'line' => 51,
                            'char' => 70,
                          ),
                        ),
                        'file' => '/app/phalcon/Html/TagFactory.zep',
                        'line' => 51,
                        'char' => 71,
                      ),
                      'file' => '/app/phalcon/Html/TagFactory.zep',
                      'line' => 51,
                      'char' => 71,
                    ),
                  ),
                  'file' => '/app/phalcon/Html/TagFactory.zep',
                  'line' => 52,
                  'char' => 9,
                ),
              ),
              'file' => '/app/phalcon/Html/TagFactory.zep',
              'line' => 54,
              'char' => 14,
            ),
            3 => 
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
                    'file' => '/app/phalcon/Html/TagFactory.zep',
                    'line' => 54,
                    'char' => 21,
                  ),
                  'right' => 
                  array (
                    'type' => 'variable',
                    'value' => 'services',
                    'file' => '/app/phalcon/Html/TagFactory.zep',
                    'line' => 54,
                    'char' => 30,
                  ),
                  'file' => '/app/phalcon/Html/TagFactory.zep',
                  'line' => 54,
                  'char' => 30,
                ),
                'right' => 
                array (
                  'type' => 'variable',
                  'value' => 'name',
                  'file' => '/app/phalcon/Html/TagFactory.zep',
                  'line' => 54,
                  'char' => 35,
                ),
                'file' => '/app/phalcon/Html/TagFactory.zep',
                'line' => 54,
                'char' => 36,
              ),
              'file' => '/app/phalcon/Html/TagFactory.zep',
              'line' => 55,
              'char' => 5,
            ),
          ),
          'docblock' => '**
     * @param string name
     *
     * @return mixed
     * @throws Exception
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
                'file' => '/app/phalcon/Html/TagFactory.zep',
                'line' => 44,
                'char' => 5,
              ),
            ),
            'void' => 0,
            'file' => '/app/phalcon/Html/TagFactory.zep',
            'line' => 44,
            'char' => 5,
          ),
          'file' => '/app/phalcon/Html/TagFactory.zep',
          'line' => 43,
          'last-line' => 57,
          'char' => 19,
        ),
        2 => 
        array (
          'visibility' => 
          array (
            0 => 'protected',
          ),
          'type' => 'method',
          'name' => 'getAdapters',
          'statements' => 
          array (
            0 => 
            array (
              'type' => 'return',
              'expr' => 
              array (
                'type' => 'array',
                'left' => 
                array (
                  0 => 
                  array (
                    'key' => 
                    array (
                      'type' => 'string',
                      'value' => 'a',
                      'file' => '/app/phalcon/Html/TagFactory.zep',
                      'line' => 60,
                      'char' => 24,
                    ),
                    'value' => 
                    array (
                      'type' => 'string',
                      'value' => '\\\\Phalcon\\\\Html\\\\Helper\\\\Anchor',
                      'file' => '/app/phalcon/Html/TagFactory.zep',
                      'line' => 60,
                      'char' => 57,
                    ),
                    'file' => '/app/phalcon/Html/TagFactory.zep',
                    'line' => 60,
                    'char' => 57,
                  ),
                  1 => 
                  array (
                    'key' => 
                    array (
                      'type' => 'string',
                      'value' => 'aRaw',
                      'file' => '/app/phalcon/Html/TagFactory.zep',
                      'line' => 61,
                      'char' => 24,
                    ),
                    'value' => 
                    array (
                      'type' => 'string',
                      'value' => '\\\\Phalcon\\\\Html\\\\Helper\\\\AnchorRaw',
                      'file' => '/app/phalcon/Html/TagFactory.zep',
                      'line' => 61,
                      'char' => 60,
                    ),
                    'file' => '/app/phalcon/Html/TagFactory.zep',
                    'line' => 61,
                    'char' => 60,
                  ),
                  2 => 
                  array (
                    'key' => 
                    array (
                      'type' => 'string',
                      'value' => 'body',
                      'file' => '/app/phalcon/Html/TagFactory.zep',
                      'line' => 62,
                      'char' => 24,
                    ),
                    'value' => 
                    array (
                      'type' => 'string',
                      'value' => '\\\\Phalcon\\\\Html\\\\Helper\\\\Body',
                      'file' => '/app/phalcon/Html/TagFactory.zep',
                      'line' => 62,
                      'char' => 55,
                    ),
                    'file' => '/app/phalcon/Html/TagFactory.zep',
                    'line' => 62,
                    'char' => 55,
                  ),
                  3 => 
                  array (
                    'key' => 
                    array (
                      'type' => 'string',
                      'value' => 'button',
                      'file' => '/app/phalcon/Html/TagFactory.zep',
                      'line' => 63,
                      'char' => 24,
                    ),
                    'value' => 
                    array (
                      'type' => 'string',
                      'value' => '\\\\Phalcon\\\\Html\\\\Helper\\\\Button',
                      'file' => '/app/phalcon/Html/TagFactory.zep',
                      'line' => 63,
                      'char' => 57,
                    ),
                    'file' => '/app/phalcon/Html/TagFactory.zep',
                    'line' => 63,
                    'char' => 57,
                  ),
                  4 => 
                  array (
                    'key' => 
                    array (
                      'type' => 'string',
                      'value' => 'close',
                      'file' => '/app/phalcon/Html/TagFactory.zep',
                      'line' => 64,
                      'char' => 24,
                    ),
                    'value' => 
                    array (
                      'type' => 'string',
                      'value' => '\\\\Phalcon\\\\Html\\\\Helper\\\\Close',
                      'file' => '/app/phalcon/Html/TagFactory.zep',
                      'line' => 64,
                      'char' => 56,
                    ),
                    'file' => '/app/phalcon/Html/TagFactory.zep',
                    'line' => 64,
                    'char' => 56,
                  ),
                  5 => 
                  array (
                    'key' => 
                    array (
                      'type' => 'string',
                      'value' => 'element',
                      'file' => '/app/phalcon/Html/TagFactory.zep',
                      'line' => 65,
                      'char' => 24,
                    ),
                    'value' => 
                    array (
                      'type' => 'string',
                      'value' => '\\\\Phalcon\\\\Html\\\\Helper\\\\Element',
                      'file' => '/app/phalcon/Html/TagFactory.zep',
                      'line' => 65,
                      'char' => 58,
                    ),
                    'file' => '/app/phalcon/Html/TagFactory.zep',
                    'line' => 65,
                    'char' => 58,
                  ),
                  6 => 
                  array (
                    'key' => 
                    array (
                      'type' => 'string',
                      'value' => 'elementRaw',
                      'file' => '/app/phalcon/Html/TagFactory.zep',
                      'line' => 66,
                      'char' => 24,
                    ),
                    'value' => 
                    array (
                      'type' => 'string',
                      'value' => '\\\\Phalcon\\\\Html\\\\Helper\\\\ElementRaw',
                      'file' => '/app/phalcon/Html/TagFactory.zep',
                      'line' => 66,
                      'char' => 61,
                    ),
                    'file' => '/app/phalcon/Html/TagFactory.zep',
                    'line' => 66,
                    'char' => 61,
                  ),
                  7 => 
                  array (
                    'key' => 
                    array (
                      'type' => 'string',
                      'value' => 'form',
                      'file' => '/app/phalcon/Html/TagFactory.zep',
                      'line' => 67,
                      'char' => 24,
                    ),
                    'value' => 
                    array (
                      'type' => 'string',
                      'value' => '\\\\Phalcon\\\\Html\\\\Helper\\\\Form',
                      'file' => '/app/phalcon/Html/TagFactory.zep',
                      'line' => 67,
                      'char' => 55,
                    ),
                    'file' => '/app/phalcon/Html/TagFactory.zep',
                    'line' => 67,
                    'char' => 55,
                  ),
                  8 => 
                  array (
                    'key' => 
                    array (
                      'type' => 'string',
                      'value' => 'img',
                      'file' => '/app/phalcon/Html/TagFactory.zep',
                      'line' => 68,
                      'char' => 24,
                    ),
                    'value' => 
                    array (
                      'type' => 'string',
                      'value' => '\\\\Phalcon\\\\Html\\\\Helper\\\\Img',
                      'file' => '/app/phalcon/Html/TagFactory.zep',
                      'line' => 68,
                      'char' => 54,
                    ),
                    'file' => '/app/phalcon/Html/TagFactory.zep',
                    'line' => 68,
                    'char' => 54,
                  ),
                  9 => 
                  array (
                    'key' => 
                    array (
                      'type' => 'string',
                      'value' => 'label',
                      'file' => '/app/phalcon/Html/TagFactory.zep',
                      'line' => 69,
                      'char' => 24,
                    ),
                    'value' => 
                    array (
                      'type' => 'string',
                      'value' => '\\\\Phalcon\\\\Html\\\\Helper\\\\Label',
                      'file' => '/app/phalcon/Html/TagFactory.zep',
                      'line' => 69,
                      'char' => 56,
                    ),
                    'file' => '/app/phalcon/Html/TagFactory.zep',
                    'line' => 69,
                    'char' => 56,
                  ),
                  10 => 
                  array (
                    'key' => 
                    array (
                      'type' => 'string',
                      'value' => 'textarea',
                      'file' => '/app/phalcon/Html/TagFactory.zep',
                      'line' => 70,
                      'char' => 24,
                    ),
                    'value' => 
                    array (
                      'type' => 'string',
                      'value' => '\\\\Phalcon\\\\Html\\\\Helper\\\\TextArea',
                      'file' => '/app/phalcon/Html/TagFactory.zep',
                      'line' => 71,
                      'char' => 9,
                    ),
                    'file' => '/app/phalcon/Html/TagFactory.zep',
                    'line' => 71,
                    'char' => 9,
                  ),
                ),
                'file' => '/app/phalcon/Html/TagFactory.zep',
                'line' => 71,
                'char' => 10,
              ),
              'file' => '/app/phalcon/Html/TagFactory.zep',
              'line' => 72,
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
                'data-type' => 'array',
                'mandatory' => 0,
                'file' => '/app/phalcon/Html/TagFactory.zep',
                'line' => 58,
                'char' => 5,
              ),
            ),
            'void' => 0,
            'file' => '/app/phalcon/Html/TagFactory.zep',
            'line' => 58,
            'char' => 5,
          ),
          'file' => '/app/phalcon/Html/TagFactory.zep',
          'line' => 57,
          'last-line' => 73,
          'char' => 22,
        ),
      ),
      'file' => '/app/phalcon/Html/TagFactory.zep',
      'line' => 20,
      'char' => 5,
    ),
    'file' => '/app/phalcon/Html/TagFactory.zep',
    'line' => 20,
    'char' => 5,
  ),
);