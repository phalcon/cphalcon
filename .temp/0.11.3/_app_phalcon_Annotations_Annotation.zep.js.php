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
    'file' => '/app/phalcon/Annotations/Annotation.zep',
    'line' => 11,
    'char' => 9,
  ),
  1 => 
  array (
    'type' => 'namespace',
    'name' => 'Phalcon\\Annotations',
    'file' => '/app/phalcon/Annotations/Annotation.zep',
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
        'name' => 'Phalcon\\Annotations\\Annotation',
        'file' => '/app/phalcon/Annotations/Annotation.zep',
        'line' => 13,
        'char' => 35,
      ),
    ),
    'file' => '/app/phalcon/Annotations/Annotation.zep',
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
        'name' => 'Phalcon\\Annotations\\Exception',
        'file' => '/app/phalcon/Annotations/Annotation.zep',
        'line' => 14,
        'char' => 34,
      ),
    ),
    'file' => '/app/phalcon/Annotations/Annotation.zep',
    'line' => 18,
    'char' => 2,
  ),
  4 => 
  array (
    'type' => 'comment',
    'value' => '**
 * Represents a single annotation in an annotations collection
 *',
    'file' => '/app/phalcon/Annotations/Annotation.zep',
    'line' => 19,
    'char' => 5,
  ),
  5 => 
  array (
    'type' => 'class',
    'name' => 'Annotation',
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
          'name' => 'arguments',
          'docblock' => '**
     * Annotation Arguments
     *
     * @var array
     *',
          'file' => '/app/phalcon/Annotations/Annotation.zep',
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
          'name' => 'exprArguments',
          'docblock' => '**
     * Annotation ExprArguments
     *
     * @var string
     *',
          'file' => '/app/phalcon/Annotations/Annotation.zep',
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
          'name' => 'name',
          'docblock' => '**
     * Annotation Name
     *
     * @var string
     *',
          'file' => '/app/phalcon/Annotations/Annotation.zep',
          'line' => 44,
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
              'mandatory' => 1,
              'reference' => 0,
              'file' => '/app/phalcon/Annotations/Annotation.zep',
              'line' => 45,
              'char' => 54,
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
                  'variable' => 'name',
                  'file' => '/app/phalcon/Annotations/Annotation.zep',
                  'line' => 47,
                  'char' => 17,
                ),
                1 => 
                array (
                  'variable' => 'exprArguments',
                  'file' => '/app/phalcon/Annotations/Annotation.zep',
                  'line' => 47,
                  'char' => 32,
                ),
                2 => 
                array (
                  'variable' => 'argument',
                  'file' => '/app/phalcon/Annotations/Annotation.zep',
                  'line' => 47,
                  'char' => 42,
                ),
                3 => 
                array (
                  'variable' => 'resolvedArgument',
                  'file' => '/app/phalcon/Annotations/Annotation.zep',
                  'line' => 47,
                  'char' => 60,
                ),
              ),
              'file' => '/app/phalcon/Annotations/Annotation.zep',
              'line' => 48,
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
                  'variable' => 'arguments',
                  'file' => '/app/phalcon/Annotations/Annotation.zep',
                  'line' => 48,
                  'char' => 24,
                ),
              ),
              'file' => '/app/phalcon/Annotations/Annotation.zep',
              'line' => 50,
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
                  'property' => 'name',
                  'expr' => 
                  array (
                    'type' => 'array-access',
                    'left' => 
                    array (
                      'type' => 'variable',
                      'value' => 'reflectionData',
                      'file' => '/app/phalcon/Annotations/Annotation.zep',
                      'line' => 50,
                      'char' => 40,
                    ),
                    'right' => 
                    array (
                      'type' => 'string',
                      'value' => 'name',
                      'file' => '/app/phalcon/Annotations/Annotation.zep',
                      'line' => 50,
                      'char' => 45,
                    ),
                    'file' => '/app/phalcon/Annotations/Annotation.zep',
                    'line' => 50,
                    'char' => 46,
                  ),
                  'file' => '/app/phalcon/Annotations/Annotation.zep',
                  'line' => 50,
                  'char' => 46,
                ),
              ),
              'file' => '/app/phalcon/Annotations/Annotation.zep',
              'line' => 55,
              'char' => 10,
            ),
            3 => 
            array (
              'type' => 'if',
              'expr' => 
              array (
                'type' => 'fetch',
                'left' => 
                array (
                  'type' => 'variable',
                  'value' => 'exprArguments',
                  'file' => '/app/phalcon/Annotations/Annotation.zep',
                  'line' => 55,
                  'char' => 59,
                ),
                'right' => 
                array (
                  'type' => 'array-access',
                  'left' => 
                  array (
                    'type' => 'variable',
                    'value' => 'reflectionData',
                    'file' => '/app/phalcon/Annotations/Annotation.zep',
                    'line' => 55,
                    'char' => 47,
                  ),
                  'right' => 
                  array (
                    'type' => 'string',
                    'value' => 'arguments',
                    'file' => '/app/phalcon/Annotations/Annotation.zep',
                    'line' => 55,
                    'char' => 57,
                  ),
                  'file' => '/app/phalcon/Annotations/Annotation.zep',
                  'line' => 55,
                  'char' => 59,
                ),
                'file' => '/app/phalcon/Annotations/Annotation.zep',
                'line' => 55,
                'char' => 59,
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
                      'variable' => 'arguments',
                      'expr' => 
                      array (
                        'type' => 'empty-array',
                        'file' => '/app/phalcon/Annotations/Annotation.zep',
                        'line' => 56,
                        'char' => 31,
                      ),
                      'file' => '/app/phalcon/Annotations/Annotation.zep',
                      'line' => 56,
                      'char' => 31,
                    ),
                  ),
                  'file' => '/app/phalcon/Annotations/Annotation.zep',
                  'line' => 58,
                  'char' => 15,
                ),
                1 => 
                array (
                  'type' => 'for',
                  'expr' => 
                  array (
                    'type' => 'variable',
                    'value' => 'exprArguments',
                    'file' => '/app/phalcon/Annotations/Annotation.zep',
                    'line' => 58,
                    'char' => 43,
                  ),
                  'value' => 'argument',
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
                          'assign-type' => 'variable',
                          'operator' => 'assign',
                          'variable' => 'resolvedArgument',
                          'expr' => 
                          array (
                            'type' => 'mcall',
                            'variable' => 
                            array (
                              'type' => 'variable',
                              'value' => 'this',
                              'file' => '/app/phalcon/Annotations/Annotation.zep',
                              'line' => 59,
                              'char' => 46,
                            ),
                            'name' => 'getExpression',
                            'call-type' => 1,
                            'parameters' => 
                            array (
                              0 => 
                              array (
                                'parameter' => 
                                array (
                                  'type' => 'array-access',
                                  'left' => 
                                  array (
                                    'type' => 'variable',
                                    'value' => 'argument',
                                    'file' => '/app/phalcon/Annotations/Annotation.zep',
                                    'line' => 60,
                                    'char' => 29,
                                  ),
                                  'right' => 
                                  array (
                                    'type' => 'string',
                                    'value' => 'expr',
                                    'file' => '/app/phalcon/Annotations/Annotation.zep',
                                    'line' => 60,
                                    'char' => 34,
                                  ),
                                  'file' => '/app/phalcon/Annotations/Annotation.zep',
                                  'line' => 61,
                                  'char' => 17,
                                ),
                                'file' => '/app/phalcon/Annotations/Annotation.zep',
                                'line' => 61,
                                'char' => 17,
                              ),
                            ),
                            'file' => '/app/phalcon/Annotations/Annotation.zep',
                            'line' => 61,
                            'char' => 18,
                          ),
                          'file' => '/app/phalcon/Annotations/Annotation.zep',
                          'line' => 61,
                          'char' => 18,
                        ),
                      ),
                      'file' => '/app/phalcon/Annotations/Annotation.zep',
                      'line' => 63,
                      'char' => 18,
                    ),
                    1 => 
                    array (
                      'type' => 'if',
                      'expr' => 
                      array (
                        'type' => 'fetch',
                        'left' => 
                        array (
                          'type' => 'variable',
                          'value' => 'name',
                          'file' => '/app/phalcon/Annotations/Annotation.zep',
                          'line' => 63,
                          'char' => 47,
                        ),
                        'right' => 
                        array (
                          'type' => 'array-access',
                          'left' => 
                          array (
                            'type' => 'variable',
                            'value' => 'argument',
                            'file' => '/app/phalcon/Annotations/Annotation.zep',
                            'line' => 63,
                            'char' => 40,
                          ),
                          'right' => 
                          array (
                            'type' => 'string',
                            'value' => 'name',
                            'file' => '/app/phalcon/Annotations/Annotation.zep',
                            'line' => 63,
                            'char' => 45,
                          ),
                          'file' => '/app/phalcon/Annotations/Annotation.zep',
                          'line' => 63,
                          'char' => 47,
                        ),
                        'file' => '/app/phalcon/Annotations/Annotation.zep',
                        'line' => 63,
                        'char' => 47,
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
                              'assign-type' => 'array-index',
                              'operator' => 'assign',
                              'variable' => 'arguments',
                              'index-expr' => 
                              array (
                                0 => 
                                array (
                                  'type' => 'variable',
                                  'value' => 'name',
                                  'file' => '/app/phalcon/Annotations/Annotation.zep',
                                  'line' => 64,
                                  'char' => 39,
                                ),
                              ),
                              'expr' => 
                              array (
                                'type' => 'variable',
                                'value' => 'resolvedArgument',
                                'file' => '/app/phalcon/Annotations/Annotation.zep',
                                'line' => 64,
                                'char' => 59,
                              ),
                              'file' => '/app/phalcon/Annotations/Annotation.zep',
                              'line' => 64,
                              'char' => 59,
                            ),
                          ),
                          'file' => '/app/phalcon/Annotations/Annotation.zep',
                          'line' => 65,
                          'char' => 17,
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
                              'assign-type' => 'variable-append',
                              'operator' => 'assign',
                              'variable' => 'arguments',
                              'expr' => 
                              array (
                                'type' => 'variable',
                                'value' => 'resolvedArgument',
                                'file' => '/app/phalcon/Annotations/Annotation.zep',
                                'line' => 66,
                                'char' => 55,
                              ),
                              'file' => '/app/phalcon/Annotations/Annotation.zep',
                              'line' => 66,
                              'char' => 55,
                            ),
                          ),
                          'file' => '/app/phalcon/Annotations/Annotation.zep',
                          'line' => 67,
                          'char' => 17,
                        ),
                      ),
                      'file' => '/app/phalcon/Annotations/Annotation.zep',
                      'line' => 68,
                      'char' => 13,
                    ),
                  ),
                  'file' => '/app/phalcon/Annotations/Annotation.zep',
                  'line' => 70,
                  'char' => 15,
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
                      'property' => 'arguments',
                      'expr' => 
                      array (
                        'type' => 'variable',
                        'value' => 'arguments',
                        'file' => '/app/phalcon/Annotations/Annotation.zep',
                        'line' => 70,
                        'char' => 44,
                      ),
                      'file' => '/app/phalcon/Annotations/Annotation.zep',
                      'line' => 70,
                      'char' => 44,
                    ),
                  ),
                  'file' => '/app/phalcon/Annotations/Annotation.zep',
                  'line' => 71,
                  'char' => 15,
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
                      'property' => 'exprArguments',
                      'expr' => 
                      array (
                        'type' => 'variable',
                        'value' => 'exprArguments',
                        'file' => '/app/phalcon/Annotations/Annotation.zep',
                        'line' => 71,
                        'char' => 52,
                      ),
                      'file' => '/app/phalcon/Annotations/Annotation.zep',
                      'line' => 71,
                      'char' => 52,
                    ),
                  ),
                  'file' => '/app/phalcon/Annotations/Annotation.zep',
                  'line' => 72,
                  'char' => 9,
                ),
              ),
              'file' => '/app/phalcon/Annotations/Annotation.zep',
              'line' => 73,
              'char' => 5,
            ),
          ),
          'docblock' => '**
     * Phalcon\\Annotations\\Annotation constructor
     *',
          'return-type' => 
          array (
            'type' => 'return-type',
            'void' => 1,
            'file' => '/app/phalcon/Annotations/Annotation.zep',
            'line' => 46,
            'char' => 5,
          ),
          'file' => '/app/phalcon/Annotations/Annotation.zep',
          'line' => 45,
          'last-line' => 77,
          'char' => 19,
        ),
        1 => 
        array (
          'visibility' => 
          array (
            0 => 'public',
          ),
          'type' => 'method',
          'name' => 'getArgument',
          'parameters' => 
          array (
            0 => 
            array (
              'type' => 'parameter',
              'name' => 'position',
              'const' => 0,
              'data-type' => 'variable',
              'mandatory' => 0,
              'reference' => 0,
              'file' => '/app/phalcon/Annotations/Annotation.zep',
              'line' => 78,
              'char' => 45,
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
                  'variable' => 'argument',
                  'file' => '/app/phalcon/Annotations/Annotation.zep',
                  'line' => 80,
                  'char' => 21,
                ),
              ),
              'file' => '/app/phalcon/Annotations/Annotation.zep',
              'line' => 82,
              'char' => 10,
            ),
            1 => 
            array (
              'type' => 'if',
              'expr' => 
              array (
                'type' => 'fetch',
                'left' => 
                array (
                  'type' => 'variable',
                  'value' => 'argument',
                  'file' => '/app/phalcon/Annotations/Annotation.zep',
                  'line' => 82,
                  'char' => 54,
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
                      'file' => '/app/phalcon/Annotations/Annotation.zep',
                      'line' => 82,
                      'char' => 33,
                    ),
                    'right' => 
                    array (
                      'type' => 'variable',
                      'value' => 'arguments',
                      'file' => '/app/phalcon/Annotations/Annotation.zep',
                      'line' => 82,
                      'char' => 43,
                    ),
                    'file' => '/app/phalcon/Annotations/Annotation.zep',
                    'line' => 82,
                    'char' => 43,
                  ),
                  'right' => 
                  array (
                    'type' => 'variable',
                    'value' => 'position',
                    'file' => '/app/phalcon/Annotations/Annotation.zep',
                    'line' => 82,
                    'char' => 52,
                  ),
                  'file' => '/app/phalcon/Annotations/Annotation.zep',
                  'line' => 82,
                  'char' => 54,
                ),
                'file' => '/app/phalcon/Annotations/Annotation.zep',
                'line' => 82,
                'char' => 54,
              ),
              'statements' => 
              array (
                0 => 
                array (
                  'type' => 'return',
                  'expr' => 
                  array (
                    'type' => 'variable',
                    'value' => 'argument',
                    'file' => '/app/phalcon/Annotations/Annotation.zep',
                    'line' => 83,
                    'char' => 28,
                  ),
                  'file' => '/app/phalcon/Annotations/Annotation.zep',
                  'line' => 84,
                  'char' => 9,
                ),
              ),
              'file' => '/app/phalcon/Annotations/Annotation.zep',
              'line' => 85,
              'char' => 5,
            ),
          ),
          'docblock' => '**
     * Returns an argument in a specific position
     *',
          'file' => '/app/phalcon/Annotations/Annotation.zep',
          'line' => 78,
          'last-line' => 89,
          'char' => 19,
        ),
        2 => 
        array (
          'visibility' => 
          array (
            0 => 'public',
          ),
          'type' => 'method',
          'name' => 'getArguments',
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
                  'file' => '/app/phalcon/Annotations/Annotation.zep',
                  'line' => 92,
                  'char' => 21,
                ),
                'right' => 
                array (
                  'type' => 'variable',
                  'value' => 'arguments',
                  'file' => '/app/phalcon/Annotations/Annotation.zep',
                  'line' => 92,
                  'char' => 31,
                ),
                'file' => '/app/phalcon/Annotations/Annotation.zep',
                'line' => 92,
                'char' => 31,
              ),
              'file' => '/app/phalcon/Annotations/Annotation.zep',
              'line' => 93,
              'char' => 5,
            ),
          ),
          'docblock' => '**
     * Returns the expression arguments
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
                'file' => '/app/phalcon/Annotations/Annotation.zep',
                'line' => 91,
                'char' => 5,
              ),
            ),
            'void' => 0,
            'file' => '/app/phalcon/Annotations/Annotation.zep',
            'line' => 91,
            'char' => 5,
          ),
          'file' => '/app/phalcon/Annotations/Annotation.zep',
          'line' => 90,
          'last-line' => 97,
          'char' => 19,
        ),
        3 => 
        array (
          'visibility' => 
          array (
            0 => 'public',
          ),
          'type' => 'method',
          'name' => 'getExprArguments',
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
                  'file' => '/app/phalcon/Annotations/Annotation.zep',
                  'line' => 100,
                  'char' => 21,
                ),
                'right' => 
                array (
                  'type' => 'variable',
                  'value' => 'exprArguments',
                  'file' => '/app/phalcon/Annotations/Annotation.zep',
                  'line' => 100,
                  'char' => 35,
                ),
                'file' => '/app/phalcon/Annotations/Annotation.zep',
                'line' => 100,
                'char' => 35,
              ),
              'file' => '/app/phalcon/Annotations/Annotation.zep',
              'line' => 101,
              'char' => 5,
            ),
          ),
          'docblock' => '**
     * Returns the expression arguments without resolving
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
                'file' => '/app/phalcon/Annotations/Annotation.zep',
                'line' => 99,
                'char' => 5,
              ),
            ),
            'void' => 0,
            'file' => '/app/phalcon/Annotations/Annotation.zep',
            'line' => 99,
            'char' => 5,
          ),
          'file' => '/app/phalcon/Annotations/Annotation.zep',
          'line' => 98,
          'last-line' => 105,
          'char' => 19,
        ),
        4 => 
        array (
          'visibility' => 
          array (
            0 => 'public',
          ),
          'type' => 'method',
          'name' => 'getExpression',
          'parameters' => 
          array (
            0 => 
            array (
              'type' => 'parameter',
              'name' => 'expr',
              'const' => 0,
              'data-type' => 'array',
              'mandatory' => 1,
              'reference' => 0,
              'file' => '/app/phalcon/Annotations/Annotation.zep',
              'line' => 106,
              'char' => 46,
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
                  'variable' => 'value',
                  'file' => '/app/phalcon/Annotations/Annotation.zep',
                  'line' => 108,
                  'char' => 18,
                ),
                1 => 
                array (
                  'variable' => 'item',
                  'file' => '/app/phalcon/Annotations/Annotation.zep',
                  'line' => 108,
                  'char' => 24,
                ),
                2 => 
                array (
                  'variable' => 'resolvedItem',
                  'file' => '/app/phalcon/Annotations/Annotation.zep',
                  'line' => 108,
                  'char' => 38,
                ),
                3 => 
                array (
                  'variable' => 'arrayValue',
                  'file' => '/app/phalcon/Annotations/Annotation.zep',
                  'line' => 108,
                  'char' => 50,
                ),
                4 => 
                array (
                  'variable' => 'name',
                  'file' => '/app/phalcon/Annotations/Annotation.zep',
                  'line' => 108,
                  'char' => 56,
                ),
                5 => 
                array (
                  'variable' => 'type',
                  'file' => '/app/phalcon/Annotations/Annotation.zep',
                  'line' => 108,
                  'char' => 62,
                ),
              ),
              'file' => '/app/phalcon/Annotations/Annotation.zep',
              'line' => 110,
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
                  'variable' => 'type',
                  'expr' => 
                  array (
                    'type' => 'array-access',
                    'left' => 
                    array (
                      'type' => 'variable',
                      'value' => 'expr',
                      'file' => '/app/phalcon/Annotations/Annotation.zep',
                      'line' => 110,
                      'char' => 24,
                    ),
                    'right' => 
                    array (
                      'type' => 'string',
                      'value' => 'type',
                      'file' => '/app/phalcon/Annotations/Annotation.zep',
                      'line' => 110,
                      'char' => 29,
                    ),
                    'file' => '/app/phalcon/Annotations/Annotation.zep',
                    'line' => 110,
                    'char' => 30,
                  ),
                  'file' => '/app/phalcon/Annotations/Annotation.zep',
                  'line' => 110,
                  'char' => 30,
                ),
              ),
              'file' => '/app/phalcon/Annotations/Annotation.zep',
              'line' => 112,
              'char' => 14,
            ),
            2 => 
            array (
              'type' => 'switch',
              'expr' => 
              array (
                'type' => 'variable',
                'value' => 'type',
                'file' => '/app/phalcon/Annotations/Annotation.zep',
                'line' => 112,
                'char' => 21,
              ),
              'clauses' => 
              array (
                0 => 
                array (
                  'type' => 'case',
                  'expr' => 
                  array (
                    'type' => 'constant',
                    'value' => 'PHANNOT_T_INTEGER',
                    'file' => '/app/phalcon/Annotations/Annotation.zep',
                    'line' => 113,
                    'char' => 35,
                  ),
                  'file' => '/app/phalcon/Annotations/Annotation.zep',
                  'line' => 114,
                  'char' => 16,
                ),
                1 => 
                array (
                  'type' => 'case',
                  'expr' => 
                  array (
                    'type' => 'constant',
                    'value' => 'PHANNOT_T_DOUBLE',
                    'file' => '/app/phalcon/Annotations/Annotation.zep',
                    'line' => 114,
                    'char' => 34,
                  ),
                  'file' => '/app/phalcon/Annotations/Annotation.zep',
                  'line' => 115,
                  'char' => 16,
                ),
                2 => 
                array (
                  'type' => 'case',
                  'expr' => 
                  array (
                    'type' => 'constant',
                    'value' => 'PHANNOT_T_STRING',
                    'file' => '/app/phalcon/Annotations/Annotation.zep',
                    'line' => 115,
                    'char' => 34,
                  ),
                  'file' => '/app/phalcon/Annotations/Annotation.zep',
                  'line' => 116,
                  'char' => 16,
                ),
                3 => 
                array (
                  'type' => 'case',
                  'expr' => 
                  array (
                    'type' => 'constant',
                    'value' => 'PHANNOT_T_IDENTIFIER',
                    'file' => '/app/phalcon/Annotations/Annotation.zep',
                    'line' => 116,
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
                          'variable' => 'value',
                          'expr' => 
                          array (
                            'type' => 'array-access',
                            'left' => 
                            array (
                              'type' => 'variable',
                              'value' => 'expr',
                              'file' => '/app/phalcon/Annotations/Annotation.zep',
                              'line' => 117,
                              'char' => 33,
                            ),
                            'right' => 
                            array (
                              'type' => 'string',
                              'value' => 'value',
                              'file' => '/app/phalcon/Annotations/Annotation.zep',
                              'line' => 117,
                              'char' => 39,
                            ),
                            'file' => '/app/phalcon/Annotations/Annotation.zep',
                            'line' => 117,
                            'char' => 40,
                          ),
                          'file' => '/app/phalcon/Annotations/Annotation.zep',
                          'line' => 117,
                          'char' => 40,
                        ),
                      ),
                      'file' => '/app/phalcon/Annotations/Annotation.zep',
                      'line' => 118,
                      'char' => 21,
                    ),
                    1 => 
                    array (
                      'type' => 'break',
                      'file' => '/app/phalcon/Annotations/Annotation.zep',
                      'line' => 120,
                      'char' => 16,
                    ),
                  ),
                  'file' => '/app/phalcon/Annotations/Annotation.zep',
                  'line' => 120,
                  'char' => 16,
                ),
                4 => 
                array (
                  'type' => 'case',
                  'expr' => 
                  array (
                    'type' => 'constant',
                    'value' => 'PHANNOT_T_NULL',
                    'file' => '/app/phalcon/Annotations/Annotation.zep',
                    'line' => 120,
                    'char' => 32,
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
                          'variable' => 'value',
                          'expr' => 
                          array (
                            'type' => 'null',
                            'file' => '/app/phalcon/Annotations/Annotation.zep',
                            'line' => 121,
                            'char' => 33,
                          ),
                          'file' => '/app/phalcon/Annotations/Annotation.zep',
                          'line' => 121,
                          'char' => 33,
                        ),
                      ),
                      'file' => '/app/phalcon/Annotations/Annotation.zep',
                      'line' => 122,
                      'char' => 21,
                    ),
                    1 => 
                    array (
                      'type' => 'break',
                      'file' => '/app/phalcon/Annotations/Annotation.zep',
                      'line' => 124,
                      'char' => 16,
                    ),
                  ),
                  'file' => '/app/phalcon/Annotations/Annotation.zep',
                  'line' => 124,
                  'char' => 16,
                ),
                5 => 
                array (
                  'type' => 'case',
                  'expr' => 
                  array (
                    'type' => 'constant',
                    'value' => 'PHANNOT_T_FALSE',
                    'file' => '/app/phalcon/Annotations/Annotation.zep',
                    'line' => 124,
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
                          'assign-type' => 'variable',
                          'operator' => 'assign',
                          'variable' => 'value',
                          'expr' => 
                          array (
                            'type' => 'bool',
                            'value' => 'false',
                            'file' => '/app/phalcon/Annotations/Annotation.zep',
                            'line' => 125,
                            'char' => 34,
                          ),
                          'file' => '/app/phalcon/Annotations/Annotation.zep',
                          'line' => 125,
                          'char' => 34,
                        ),
                      ),
                      'file' => '/app/phalcon/Annotations/Annotation.zep',
                      'line' => 126,
                      'char' => 21,
                    ),
                    1 => 
                    array (
                      'type' => 'break',
                      'file' => '/app/phalcon/Annotations/Annotation.zep',
                      'line' => 128,
                      'char' => 16,
                    ),
                  ),
                  'file' => '/app/phalcon/Annotations/Annotation.zep',
                  'line' => 128,
                  'char' => 16,
                ),
                6 => 
                array (
                  'type' => 'case',
                  'expr' => 
                  array (
                    'type' => 'constant',
                    'value' => 'PHANNOT_T_TRUE',
                    'file' => '/app/phalcon/Annotations/Annotation.zep',
                    'line' => 128,
                    'char' => 32,
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
                          'variable' => 'value',
                          'expr' => 
                          array (
                            'type' => 'bool',
                            'value' => 'true',
                            'file' => '/app/phalcon/Annotations/Annotation.zep',
                            'line' => 129,
                            'char' => 33,
                          ),
                          'file' => '/app/phalcon/Annotations/Annotation.zep',
                          'line' => 129,
                          'char' => 33,
                        ),
                      ),
                      'file' => '/app/phalcon/Annotations/Annotation.zep',
                      'line' => 130,
                      'char' => 21,
                    ),
                    1 => 
                    array (
                      'type' => 'break',
                      'file' => '/app/phalcon/Annotations/Annotation.zep',
                      'line' => 132,
                      'char' => 16,
                    ),
                  ),
                  'file' => '/app/phalcon/Annotations/Annotation.zep',
                  'line' => 132,
                  'char' => 16,
                ),
                7 => 
                array (
                  'type' => 'case',
                  'expr' => 
                  array (
                    'type' => 'constant',
                    'value' => 'PHANNOT_T_ARRAY',
                    'file' => '/app/phalcon/Annotations/Annotation.zep',
                    'line' => 132,
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
                          'assign-type' => 'variable',
                          'operator' => 'assign',
                          'variable' => 'arrayValue',
                          'expr' => 
                          array (
                            'type' => 'empty-array',
                            'file' => '/app/phalcon/Annotations/Annotation.zep',
                            'line' => 133,
                            'char' => 36,
                          ),
                          'file' => '/app/phalcon/Annotations/Annotation.zep',
                          'line' => 133,
                          'char' => 36,
                        ),
                      ),
                      'file' => '/app/phalcon/Annotations/Annotation.zep',
                      'line' => 135,
                      'char' => 19,
                    ),
                    1 => 
                    array (
                      'type' => 'for',
                      'expr' => 
                      array (
                        'type' => 'array-access',
                        'left' => 
                        array (
                          'type' => 'variable',
                          'value' => 'expr',
                          'file' => '/app/phalcon/Annotations/Annotation.zep',
                          'line' => 135,
                          'char' => 33,
                        ),
                        'right' => 
                        array (
                          'type' => 'string',
                          'value' => 'items',
                          'file' => '/app/phalcon/Annotations/Annotation.zep',
                          'line' => 135,
                          'char' => 39,
                        ),
                        'file' => '/app/phalcon/Annotations/Annotation.zep',
                        'line' => 135,
                        'char' => 41,
                      ),
                      'value' => 'item',
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
                              'assign-type' => 'variable',
                              'operator' => 'assign',
                              'variable' => 'resolvedItem',
                              'expr' => 
                              array (
                                'type' => 'mcall',
                                'variable' => 
                                array (
                                  'type' => 'variable',
                                  'value' => 'this',
                                  'file' => '/app/phalcon/Annotations/Annotation.zep',
                                  'line' => 136,
                                  'char' => 45,
                                ),
                                'name' => 'getExpression',
                                'call-type' => 1,
                                'parameters' => 
                                array (
                                  0 => 
                                  array (
                                    'parameter' => 
                                    array (
                                      'type' => 'array-access',
                                      'left' => 
                                      array (
                                        'type' => 'variable',
                                        'value' => 'item',
                                        'file' => '/app/phalcon/Annotations/Annotation.zep',
                                        'line' => 137,
                                        'char' => 29,
                                      ),
                                      'right' => 
                                      array (
                                        'type' => 'string',
                                        'value' => 'expr',
                                        'file' => '/app/phalcon/Annotations/Annotation.zep',
                                        'line' => 137,
                                        'char' => 34,
                                      ),
                                      'file' => '/app/phalcon/Annotations/Annotation.zep',
                                      'line' => 138,
                                      'char' => 21,
                                    ),
                                    'file' => '/app/phalcon/Annotations/Annotation.zep',
                                    'line' => 138,
                                    'char' => 21,
                                  ),
                                ),
                                'file' => '/app/phalcon/Annotations/Annotation.zep',
                                'line' => 138,
                                'char' => 22,
                              ),
                              'file' => '/app/phalcon/Annotations/Annotation.zep',
                              'line' => 138,
                              'char' => 22,
                            ),
                          ),
                          'file' => '/app/phalcon/Annotations/Annotation.zep',
                          'line' => 140,
                          'char' => 22,
                        ),
                        1 => 
                        array (
                          'type' => 'if',
                          'expr' => 
                          array (
                            'type' => 'fetch',
                            'left' => 
                            array (
                              'type' => 'variable',
                              'value' => 'name',
                              'file' => '/app/phalcon/Annotations/Annotation.zep',
                              'line' => 140,
                              'char' => 47,
                            ),
                            'right' => 
                            array (
                              'type' => 'array-access',
                              'left' => 
                              array (
                                'type' => 'variable',
                                'value' => 'item',
                                'file' => '/app/phalcon/Annotations/Annotation.zep',
                                'line' => 140,
                                'char' => 40,
                              ),
                              'right' => 
                              array (
                                'type' => 'string',
                                'value' => 'name',
                                'file' => '/app/phalcon/Annotations/Annotation.zep',
                                'line' => 140,
                                'char' => 45,
                              ),
                              'file' => '/app/phalcon/Annotations/Annotation.zep',
                              'line' => 140,
                              'char' => 47,
                            ),
                            'file' => '/app/phalcon/Annotations/Annotation.zep',
                            'line' => 140,
                            'char' => 47,
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
                                  'assign-type' => 'array-index',
                                  'operator' => 'assign',
                                  'variable' => 'arrayValue',
                                  'index-expr' => 
                                  array (
                                    0 => 
                                    array (
                                      'type' => 'variable',
                                      'value' => 'name',
                                      'file' => '/app/phalcon/Annotations/Annotation.zep',
                                      'line' => 141,
                                      'char' => 44,
                                    ),
                                  ),
                                  'expr' => 
                                  array (
                                    'type' => 'variable',
                                    'value' => 'resolvedItem',
                                    'file' => '/app/phalcon/Annotations/Annotation.zep',
                                    'line' => 141,
                                    'char' => 60,
                                  ),
                                  'file' => '/app/phalcon/Annotations/Annotation.zep',
                                  'line' => 141,
                                  'char' => 60,
                                ),
                              ),
                              'file' => '/app/phalcon/Annotations/Annotation.zep',
                              'line' => 142,
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
                                  'assign-type' => 'variable-append',
                                  'operator' => 'assign',
                                  'variable' => 'arrayValue',
                                  'expr' => 
                                  array (
                                    'type' => 'variable',
                                    'value' => 'resolvedItem',
                                    'file' => '/app/phalcon/Annotations/Annotation.zep',
                                    'line' => 143,
                                    'char' => 56,
                                  ),
                                  'file' => '/app/phalcon/Annotations/Annotation.zep',
                                  'line' => 143,
                                  'char' => 56,
                                ),
                              ),
                              'file' => '/app/phalcon/Annotations/Annotation.zep',
                              'line' => 144,
                              'char' => 21,
                            ),
                          ),
                          'file' => '/app/phalcon/Annotations/Annotation.zep',
                          'line' => 145,
                          'char' => 17,
                        ),
                      ),
                      'file' => '/app/phalcon/Annotations/Annotation.zep',
                      'line' => 147,
                      'char' => 22,
                    ),
                    2 => 
                    array (
                      'type' => 'return',
                      'expr' => 
                      array (
                        'type' => 'variable',
                        'value' => 'arrayValue',
                        'file' => '/app/phalcon/Annotations/Annotation.zep',
                        'line' => 147,
                        'char' => 34,
                      ),
                      'file' => '/app/phalcon/Annotations/Annotation.zep',
                      'line' => 149,
                      'char' => 16,
                    ),
                  ),
                  'file' => '/app/phalcon/Annotations/Annotation.zep',
                  'line' => 149,
                  'char' => 16,
                ),
                8 => 
                array (
                  'type' => 'case',
                  'expr' => 
                  array (
                    'type' => 'constant',
                    'value' => 'PHANNOT_T_ANNOTATION',
                    'file' => '/app/phalcon/Annotations/Annotation.zep',
                    'line' => 149,
                    'char' => 38,
                  ),
                  'statements' => 
                  array (
                    0 => 
                    array (
                      'type' => 'return',
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
                              'value' => 'expr',
                              'file' => '/app/phalcon/Annotations/Annotation.zep',
                              'line' => 150,
                              'char' => 43,
                            ),
                            'file' => '/app/phalcon/Annotations/Annotation.zep',
                            'line' => 150,
                            'char' => 43,
                          ),
                        ),
                        'file' => '/app/phalcon/Annotations/Annotation.zep',
                        'line' => 150,
                        'char' => 44,
                      ),
                      'file' => '/app/phalcon/Annotations/Annotation.zep',
                      'line' => 152,
                      'char' => 19,
                    ),
                  ),
                  'file' => '/app/phalcon/Annotations/Annotation.zep',
                  'line' => 152,
                  'char' => 19,
                ),
                9 => 
                array (
                  'type' => 'default',
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
                                'type' => 'concat',
                                'left' => 
                                array (
                                  'type' => 'string',
                                  'value' => 'The expression ',
                                  'file' => '/app/phalcon/Annotations/Annotation.zep',
                                  'line' => 153,
                                  'char' => 52,
                                ),
                                'right' => 
                                array (
                                  'type' => 'variable',
                                  'value' => 'type',
                                  'file' => '/app/phalcon/Annotations/Annotation.zep',
                                  'line' => 153,
                                  'char' => 58,
                                ),
                                'file' => '/app/phalcon/Annotations/Annotation.zep',
                                'line' => 153,
                                'char' => 58,
                              ),
                              'right' => 
                              array (
                                'type' => 'string',
                                'value' => ' is unknown',
                                'file' => '/app/phalcon/Annotations/Annotation.zep',
                                'line' => 153,
                                'char' => 71,
                              ),
                              'file' => '/app/phalcon/Annotations/Annotation.zep',
                              'line' => 153,
                              'char' => 71,
                            ),
                            'file' => '/app/phalcon/Annotations/Annotation.zep',
                            'line' => 153,
                            'char' => 71,
                          ),
                        ),
                        'file' => '/app/phalcon/Annotations/Annotation.zep',
                        'line' => 153,
                        'char' => 72,
                      ),
                      'file' => '/app/phalcon/Annotations/Annotation.zep',
                      'line' => 154,
                      'char' => 9,
                    ),
                  ),
                  'file' => '/app/phalcon/Annotations/Annotation.zep',
                  'line' => 154,
                  'char' => 9,
                ),
              ),
              'file' => '/app/phalcon/Annotations/Annotation.zep',
              'line' => 156,
              'char' => 14,
            ),
            3 => 
            array (
              'type' => 'return',
              'expr' => 
              array (
                'type' => 'variable',
                'value' => 'value',
                'file' => '/app/phalcon/Annotations/Annotation.zep',
                'line' => 156,
                'char' => 21,
              ),
              'file' => '/app/phalcon/Annotations/Annotation.zep',
              'line' => 157,
              'char' => 5,
            ),
          ),
          'docblock' => '**
     * Resolves an annotation expression
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
                'file' => '/app/phalcon/Annotations/Annotation.zep',
                'line' => 107,
                'char' => 5,
              ),
            ),
            'void' => 0,
            'file' => '/app/phalcon/Annotations/Annotation.zep',
            'line' => 107,
            'char' => 5,
          ),
          'file' => '/app/phalcon/Annotations/Annotation.zep',
          'line' => 106,
          'last-line' => 161,
          'char' => 19,
        ),
        5 => 
        array (
          'visibility' => 
          array (
            0 => 'public',
          ),
          'type' => 'method',
          'name' => 'getName',
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
                  'file' => '/app/phalcon/Annotations/Annotation.zep',
                  'line' => 164,
                  'char' => 21,
                ),
                'right' => 
                array (
                  'type' => 'variable',
                  'value' => 'name',
                  'file' => '/app/phalcon/Annotations/Annotation.zep',
                  'line' => 164,
                  'char' => 26,
                ),
                'file' => '/app/phalcon/Annotations/Annotation.zep',
                'line' => 164,
                'char' => 26,
              ),
              'file' => '/app/phalcon/Annotations/Annotation.zep',
              'line' => 165,
              'char' => 5,
            ),
          ),
          'docblock' => '**
     * Returns the annotation\'s name
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
                'file' => '/app/phalcon/Annotations/Annotation.zep',
                'line' => 163,
                'char' => 5,
              ),
            ),
            'void' => 0,
            'file' => '/app/phalcon/Annotations/Annotation.zep',
            'line' => 163,
            'char' => 5,
          ),
          'file' => '/app/phalcon/Annotations/Annotation.zep',
          'line' => 162,
          'last-line' => 169,
          'char' => 19,
        ),
        6 => 
        array (
          'visibility' => 
          array (
            0 => 'public',
          ),
          'type' => 'method',
          'name' => 'getNamedArgument',
          'parameters' => 
          array (
            0 => 
            array (
              'type' => 'parameter',
              'name' => 'name',
              'const' => 0,
              'data-type' => 'string',
              'mandatory' => 1,
              'reference' => 0,
              'file' => '/app/phalcon/Annotations/Annotation.zep',
              'line' => 170,
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
                  'variable' => 'argument',
                  'file' => '/app/phalcon/Annotations/Annotation.zep',
                  'line' => 172,
                  'char' => 21,
                ),
              ),
              'file' => '/app/phalcon/Annotations/Annotation.zep',
              'line' => 174,
              'char' => 10,
            ),
            1 => 
            array (
              'type' => 'if',
              'expr' => 
              array (
                'type' => 'fetch',
                'left' => 
                array (
                  'type' => 'variable',
                  'value' => 'argument',
                  'file' => '/app/phalcon/Annotations/Annotation.zep',
                  'line' => 174,
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
                      'file' => '/app/phalcon/Annotations/Annotation.zep',
                      'line' => 174,
                      'char' => 33,
                    ),
                    'right' => 
                    array (
                      'type' => 'variable',
                      'value' => 'arguments',
                      'file' => '/app/phalcon/Annotations/Annotation.zep',
                      'line' => 174,
                      'char' => 43,
                    ),
                    'file' => '/app/phalcon/Annotations/Annotation.zep',
                    'line' => 174,
                    'char' => 43,
                  ),
                  'right' => 
                  array (
                    'type' => 'variable',
                    'value' => 'name',
                    'file' => '/app/phalcon/Annotations/Annotation.zep',
                    'line' => 174,
                    'char' => 48,
                  ),
                  'file' => '/app/phalcon/Annotations/Annotation.zep',
                  'line' => 174,
                  'char' => 50,
                ),
                'file' => '/app/phalcon/Annotations/Annotation.zep',
                'line' => 174,
                'char' => 50,
              ),
              'statements' => 
              array (
                0 => 
                array (
                  'type' => 'return',
                  'expr' => 
                  array (
                    'type' => 'variable',
                    'value' => 'argument',
                    'file' => '/app/phalcon/Annotations/Annotation.zep',
                    'line' => 175,
                    'char' => 28,
                  ),
                  'file' => '/app/phalcon/Annotations/Annotation.zep',
                  'line' => 176,
                  'char' => 9,
                ),
              ),
              'file' => '/app/phalcon/Annotations/Annotation.zep',
              'line' => 177,
              'char' => 5,
            ),
          ),
          'docblock' => '**
     * Returns a named argument
     *',
          'file' => '/app/phalcon/Annotations/Annotation.zep',
          'line' => 170,
          'last-line' => 181,
          'char' => 19,
        ),
        7 => 
        array (
          'visibility' => 
          array (
            0 => 'public',
          ),
          'type' => 'method',
          'name' => 'getNamedParameter',
          'parameters' => 
          array (
            0 => 
            array (
              'type' => 'parameter',
              'name' => 'name',
              'const' => 0,
              'data-type' => 'string',
              'mandatory' => 1,
              'reference' => 0,
              'file' => '/app/phalcon/Annotations/Annotation.zep',
              'line' => 182,
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
                'type' => 'mcall',
                'variable' => 
                array (
                  'type' => 'variable',
                  'value' => 'this',
                  'file' => '/app/phalcon/Annotations/Annotation.zep',
                  'line' => 184,
                  'char' => 21,
                ),
                'name' => 'getNamedArgument',
                'call-type' => 1,
                'parameters' => 
                array (
                  0 => 
                  array (
                    'parameter' => 
                    array (
                      'type' => 'variable',
                      'value' => 'name',
                      'file' => '/app/phalcon/Annotations/Annotation.zep',
                      'line' => 184,
                      'char' => 43,
                    ),
                    'file' => '/app/phalcon/Annotations/Annotation.zep',
                    'line' => 184,
                    'char' => 43,
                  ),
                ),
                'file' => '/app/phalcon/Annotations/Annotation.zep',
                'line' => 184,
                'char' => 44,
              ),
              'file' => '/app/phalcon/Annotations/Annotation.zep',
              'line' => 185,
              'char' => 5,
            ),
          ),
          'docblock' => '**
     * Returns a named parameter
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
                'file' => '/app/phalcon/Annotations/Annotation.zep',
                'line' => 183,
                'char' => 5,
              ),
            ),
            'void' => 0,
            'file' => '/app/phalcon/Annotations/Annotation.zep',
            'line' => 183,
            'char' => 5,
          ),
          'file' => '/app/phalcon/Annotations/Annotation.zep',
          'line' => 182,
          'last-line' => 189,
          'char' => 19,
        ),
        8 => 
        array (
          'visibility' => 
          array (
            0 => 'public',
          ),
          'type' => 'method',
          'name' => 'hasArgument',
          'parameters' => 
          array (
            0 => 
            array (
              'type' => 'parameter',
              'name' => 'position',
              'const' => 0,
              'data-type' => 'variable',
              'mandatory' => 0,
              'reference' => 0,
              'file' => '/app/phalcon/Annotations/Annotation.zep',
              'line' => 190,
              'char' => 45,
            ),
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
                    'type' => 'property-access',
                    'left' => 
                    array (
                      'type' => 'variable',
                      'value' => 'this',
                      'file' => '/app/phalcon/Annotations/Annotation.zep',
                      'line' => 192,
                      'char' => 27,
                    ),
                    'right' => 
                    array (
                      'type' => 'variable',
                      'value' => 'arguments',
                      'file' => '/app/phalcon/Annotations/Annotation.zep',
                      'line' => 192,
                      'char' => 37,
                    ),
                    'file' => '/app/phalcon/Annotations/Annotation.zep',
                    'line' => 192,
                    'char' => 37,
                  ),
                  'right' => 
                  array (
                    'type' => 'variable',
                    'value' => 'position',
                    'file' => '/app/phalcon/Annotations/Annotation.zep',
                    'line' => 192,
                    'char' => 46,
                  ),
                  'file' => '/app/phalcon/Annotations/Annotation.zep',
                  'line' => 192,
                  'char' => 47,
                ),
                'file' => '/app/phalcon/Annotations/Annotation.zep',
                'line' => 192,
                'char' => 47,
              ),
              'file' => '/app/phalcon/Annotations/Annotation.zep',
              'line' => 193,
              'char' => 5,
            ),
          ),
          'docblock' => '**
     * Returns an argument in a specific position
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
                'file' => '/app/phalcon/Annotations/Annotation.zep',
                'line' => 191,
                'char' => 5,
              ),
            ),
            'void' => 0,
            'file' => '/app/phalcon/Annotations/Annotation.zep',
            'line' => 191,
            'char' => 5,
          ),
          'file' => '/app/phalcon/Annotations/Annotation.zep',
          'line' => 190,
          'last-line' => 197,
          'char' => 19,
        ),
        9 => 
        array (
          'visibility' => 
          array (
            0 => 'public',
          ),
          'type' => 'method',
          'name' => 'numberArguments',
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
                        'file' => '/app/phalcon/Annotations/Annotation.zep',
                        'line' => 200,
                        'char' => 27,
                      ),
                      'right' => 
                      array (
                        'type' => 'variable',
                        'value' => 'arguments',
                        'file' => '/app/phalcon/Annotations/Annotation.zep',
                        'line' => 200,
                        'char' => 37,
                      ),
                      'file' => '/app/phalcon/Annotations/Annotation.zep',
                      'line' => 200,
                      'char' => 37,
                    ),
                    'file' => '/app/phalcon/Annotations/Annotation.zep',
                    'line' => 200,
                    'char' => 37,
                  ),
                ),
                'file' => '/app/phalcon/Annotations/Annotation.zep',
                'line' => 200,
                'char' => 38,
              ),
              'file' => '/app/phalcon/Annotations/Annotation.zep',
              'line' => 201,
              'char' => 5,
            ),
          ),
          'docblock' => '**
     * Returns the number of arguments that the annotation has
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
                'file' => '/app/phalcon/Annotations/Annotation.zep',
                'line' => 199,
                'char' => 5,
              ),
            ),
            'void' => 0,
            'file' => '/app/phalcon/Annotations/Annotation.zep',
            'line' => 199,
            'char' => 5,
          ),
          'file' => '/app/phalcon/Annotations/Annotation.zep',
          'line' => 198,
          'last-line' => 202,
          'char' => 19,
        ),
      ),
      'file' => '/app/phalcon/Annotations/Annotation.zep',
      'line' => 19,
      'char' => 5,
    ),
    'file' => '/app/phalcon/Annotations/Annotation.zep',
    'line' => 19,
    'char' => 5,
  ),
);