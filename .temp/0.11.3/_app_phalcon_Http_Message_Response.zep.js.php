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
 *
 * Implementation of this file has been influenced by Zend Diactoros
 * @link    https://github.com/zendframework/zend-diactoros
 * @license https://github.com/zendframework/zend-diactoros/blob/master/LICENSE.md
 *',
    'file' => '/app/phalcon/Http/Message/Response.zep',
    'line' => 15,
    'char' => 9,
  ),
  1 => 
  array (
    'type' => 'namespace',
    'name' => 'Phalcon\\Http\\Message',
    'file' => '/app/phalcon/Http/Message/Response.zep',
    'line' => 17,
    'char' => 3,
  ),
  2 => 
  array (
    'type' => 'use',
    'aliases' => 
    array (
      0 => 
      array (
        'name' => 'Phalcon\\Helper\\Number',
        'file' => '/app/phalcon/Http/Message/Response.zep',
        'line' => 17,
        'char' => 26,
      ),
    ),
    'file' => '/app/phalcon/Http/Message/Response.zep',
    'line' => 18,
    'char' => 3,
  ),
  3 => 
  array (
    'type' => 'use',
    'aliases' => 
    array (
      0 => 
      array (
        'name' => 'Phalcon\\Http\\Message\\AbstractMessage',
        'file' => '/app/phalcon/Http/Message/Response.zep',
        'line' => 18,
        'char' => 41,
      ),
    ),
    'file' => '/app/phalcon/Http/Message/Response.zep',
    'line' => 19,
    'char' => 3,
  ),
  4 => 
  array (
    'type' => 'use',
    'aliases' => 
    array (
      0 => 
      array (
        'name' => 'Phalcon\\Http\\Message\\Exception\\InvalidArgumentException',
        'file' => '/app/phalcon/Http/Message/Response.zep',
        'line' => 19,
        'char' => 60,
      ),
    ),
    'file' => '/app/phalcon/Http/Message/Response.zep',
    'line' => 20,
    'char' => 3,
  ),
  5 => 
  array (
    'type' => 'use',
    'aliases' => 
    array (
      0 => 
      array (
        'name' => 'Psr\\Http\\Message\\ResponseInterface',
        'file' => '/app/phalcon/Http/Message/Response.zep',
        'line' => 20,
        'char' => 39,
      ),
    ),
    'file' => '/app/phalcon/Http/Message/Response.zep',
    'line' => 24,
    'char' => 2,
  ),
  6 => 
  array (
    'type' => 'comment',
    'value' => '**
 * PSR-7 Response
 *',
    'file' => '/app/phalcon/Http/Message/Response.zep',
    'line' => 25,
    'char' => 5,
  ),
  7 => 
  array (
    'type' => 'class',
    'name' => 'Response',
    'abstract' => 0,
    'final' => 1,
    'extends' => 'AbstractMessage',
    'implements' => 
    array (
      0 => 
      array (
        'type' => 'variable',
        'value' => 'ResponseInterface',
        'file' => '/app/phalcon/Http/Message/Response.zep',
        'line' => 26,
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
            0 => 'private',
          ),
          'type' => 'property',
          'name' => 'reasonPhrase',
          'default' => 
          array (
            'type' => 'string',
            'value' => '',
            'file' => '/app/phalcon/Http/Message/Response.zep',
            'line' => 42,
            'char' => 29,
          ),
          'docblock' => '**
     * Gets the response reason phrase associated with the status code.
     *
     * Because a reason phrase is not a required element in a response
     * status line, the reason phrase value MAY be empty. Implementations MAY
     * choose to return the default RFC 7231 recommended reason phrase (or
     * those
     * listed in the IANA HTTP Status Code Registry) for the response\'s
     * status code.
     *
     * @see http://tools.ietf.org/html/rfc7231#section-6
     * @see http://www.iana.org/assignments/http-status-codes/http-status-codes.xhtml
     *
     * @var string
     *',
          'shortcuts' => 
          array (
            0 => 
            array (
              'type' => 'shortcut',
              'name' => 'get',
              'file' => '/app/phalcon/Http/Message/Response.zep',
              'line' => 42,
              'char' => 35,
            ),
          ),
          'file' => '/app/phalcon/Http/Message/Response.zep',
          'line' => 51,
          'char' => 6,
        ),
        1 => 
        array (
          'visibility' => 
          array (
            0 => 'private',
          ),
          'type' => 'property',
          'name' => 'statusCode',
          'default' => 
          array (
            'type' => 'int',
            'value' => '200',
            'file' => '/app/phalcon/Http/Message/Response.zep',
            'line' => 52,
            'char' => 30,
          ),
          'docblock' => '**
     * Gets the response status code.
     *
     * The status code is a 3-digit integer result code of the server\'s attempt
     * to understand and satisfy the request.
     *
     * @var int
     *',
          'shortcuts' => 
          array (
            0 => 
            array (
              'type' => 'shortcut',
              'name' => 'get',
              'file' => '/app/phalcon/Http/Message/Response.zep',
              'line' => 52,
              'char' => 36,
            ),
          ),
          'file' => '/app/phalcon/Http/Message/Response.zep',
          'line' => 60,
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
              'name' => 'body',
              'const' => 0,
              'data-type' => 'variable',
              'mandatory' => 0,
              'default' => 
              array (
                'type' => 'string',
                'value' => 'php://memory',
                'file' => '/app/phalcon/Http/Message/Response.zep',
                'line' => 61,
                'char' => 56,
              ),
              'reference' => 0,
              'file' => '/app/phalcon/Http/Message/Response.zep',
              'line' => 61,
              'char' => 56,
            ),
            1 => 
            array (
              'type' => 'parameter',
              'name' => 'code',
              'const' => 0,
              'data-type' => 'int',
              'mandatory' => 0,
              'default' => 
              array (
                'type' => 'int',
                'value' => '200',
                'file' => '/app/phalcon/Http/Message/Response.zep',
                'line' => 61,
                'char' => 72,
              ),
              'reference' => 0,
              'file' => '/app/phalcon/Http/Message/Response.zep',
              'line' => 61,
              'char' => 72,
            ),
            2 => 
            array (
              'type' => 'parameter',
              'name' => 'headers',
              'const' => 0,
              'data-type' => 'array',
              'mandatory' => 0,
              'default' => 
              array (
                'type' => 'empty-array',
                'file' => '/app/phalcon/Http/Message/Response.zep',
                'line' => 61,
                'char' => 92,
              ),
              'reference' => 0,
              'file' => '/app/phalcon/Http/Message/Response.zep',
              'line' => 61,
              'char' => 92,
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
                  'file' => '/app/phalcon/Http/Message/Response.zep',
                  'line' => 63,
                  'char' => 14,
                ),
                'name' => 'processCode',
                'call-type' => 1,
                'parameters' => 
                array (
                  0 => 
                  array (
                    'parameter' => 
                    array (
                      'type' => 'variable',
                      'value' => 'code',
                      'file' => '/app/phalcon/Http/Message/Response.zep',
                      'line' => 63,
                      'char' => 31,
                    ),
                    'file' => '/app/phalcon/Http/Message/Response.zep',
                    'line' => 63,
                    'char' => 31,
                  ),
                ),
                'file' => '/app/phalcon/Http/Message/Response.zep',
                'line' => 63,
                'char' => 32,
              ),
              'file' => '/app/phalcon/Http/Message/Response.zep',
              'line' => 65,
              'char' => 11,
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
                  'property' => 'headers',
                  'expr' => 
                  array (
                    'type' => 'mcall',
                    'variable' => 
                    array (
                      'type' => 'variable',
                      'value' => 'this',
                      'file' => '/app/phalcon/Http/Message/Response.zep',
                      'line' => 65,
                      'char' => 34,
                    ),
                    'name' => 'processHeaders',
                    'call-type' => 1,
                    'parameters' => 
                    array (
                      0 => 
                      array (
                        'parameter' => 
                        array (
                          'type' => 'variable',
                          'value' => 'headers',
                          'file' => '/app/phalcon/Http/Message/Response.zep',
                          'line' => 65,
                          'char' => 57,
                        ),
                        'file' => '/app/phalcon/Http/Message/Response.zep',
                        'line' => 65,
                        'char' => 57,
                      ),
                    ),
                    'file' => '/app/phalcon/Http/Message/Response.zep',
                    'line' => 65,
                    'char' => 58,
                  ),
                  'file' => '/app/phalcon/Http/Message/Response.zep',
                  'line' => 65,
                  'char' => 58,
                ),
                1 => 
                array (
                  'assign-type' => 'object-property',
                  'operator' => 'assign',
                  'variable' => 'this',
                  'property' => 'body',
                  'expr' => 
                  array (
                    'type' => 'mcall',
                    'variable' => 
                    array (
                      'type' => 'variable',
                      'value' => 'this',
                      'file' => '/app/phalcon/Http/Message/Response.zep',
                      'line' => 66,
                      'char' => 34,
                    ),
                    'name' => 'processBody',
                    'call-type' => 1,
                    'parameters' => 
                    array (
                      0 => 
                      array (
                        'parameter' => 
                        array (
                          'type' => 'variable',
                          'value' => 'body',
                          'file' => '/app/phalcon/Http/Message/Response.zep',
                          'line' => 66,
                          'char' => 51,
                        ),
                        'file' => '/app/phalcon/Http/Message/Response.zep',
                        'line' => 66,
                        'char' => 51,
                      ),
                      1 => 
                      array (
                        'parameter' => 
                        array (
                          'type' => 'string',
                          'value' => 'w+b',
                          'file' => '/app/phalcon/Http/Message/Response.zep',
                          'line' => 66,
                          'char' => 56,
                        ),
                        'file' => '/app/phalcon/Http/Message/Response.zep',
                        'line' => 66,
                        'char' => 56,
                      ),
                    ),
                    'file' => '/app/phalcon/Http/Message/Response.zep',
                    'line' => 66,
                    'char' => 57,
                  ),
                  'file' => '/app/phalcon/Http/Message/Response.zep',
                  'line' => 66,
                  'char' => 57,
                ),
              ),
              'file' => '/app/phalcon/Http/Message/Response.zep',
              'line' => 67,
              'char' => 5,
            ),
          ),
          'docblock' => '**
     * Response constructor.
     *
     * @param string $body
     * @param int    $code
     * @param array  $headers
     *',
          'file' => '/app/phalcon/Http/Message/Response.zep',
          'line' => 61,
          'last-line' => 88,
          'char' => 19,
        ),
        1 => 
        array (
          'visibility' => 
          array (
            0 => 'public',
          ),
          'type' => 'method',
          'name' => 'withStatus',
          'parameters' => 
          array (
            0 => 
            array (
              'type' => 'parameter',
              'name' => 'code',
              'const' => 0,
              'data-type' => 'variable',
              'mandatory' => 0,
              'reference' => 0,
              'file' => '/app/phalcon/Http/Message/Response.zep',
              'line' => 89,
              'char' => 40,
            ),
            1 => 
            array (
              'type' => 'parameter',
              'name' => 'reasonPhrase',
              'const' => 0,
              'data-type' => 'variable',
              'mandatory' => 0,
              'default' => 
              array (
                'type' => 'string',
                'value' => '',
                'file' => '/app/phalcon/Http/Message/Response.zep',
                'line' => 89,
                'char' => 61,
              ),
              'reference' => 0,
              'file' => '/app/phalcon/Http/Message/Response.zep',
              'line' => 89,
              'char' => 61,
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
                  'variable' => 'newInstance',
                  'file' => '/app/phalcon/Http/Message/Response.zep',
                  'line' => 91,
                  'char' => 24,
                ),
              ),
              'file' => '/app/phalcon/Http/Message/Response.zep',
              'line' => 93,
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
                  'variable' => 'newInstance',
                  'expr' => 
                  array (
                    'type' => 'clone',
                    'left' => 
                    array (
                      'type' => 'variable',
                      'value' => 'this',
                      'file' => '/app/phalcon/Http/Message/Response.zep',
                      'line' => 93,
                      'char' => 37,
                    ),
                    'file' => '/app/phalcon/Http/Message/Response.zep',
                    'line' => 93,
                    'char' => 37,
                  ),
                  'file' => '/app/phalcon/Http/Message/Response.zep',
                  'line' => 93,
                  'char' => 37,
                ),
              ),
              'file' => '/app/phalcon/Http/Message/Response.zep',
              'line' => 95,
              'char' => 19,
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
                  'value' => 'newInstance',
                  'file' => '/app/phalcon/Http/Message/Response.zep',
                  'line' => 95,
                  'char' => 21,
                ),
                'name' => 'processCode',
                'call-type' => 1,
                'parameters' => 
                array (
                  0 => 
                  array (
                    'parameter' => 
                    array (
                      'type' => 'variable',
                      'value' => 'code',
                      'file' => '/app/phalcon/Http/Message/Response.zep',
                      'line' => 95,
                      'char' => 38,
                    ),
                    'file' => '/app/phalcon/Http/Message/Response.zep',
                    'line' => 95,
                    'char' => 38,
                  ),
                  1 => 
                  array (
                    'parameter' => 
                    array (
                      'type' => 'variable',
                      'value' => 'reasonPhrase',
                      'file' => '/app/phalcon/Http/Message/Response.zep',
                      'line' => 95,
                      'char' => 52,
                    ),
                    'file' => '/app/phalcon/Http/Message/Response.zep',
                    'line' => 95,
                    'char' => 52,
                  ),
                ),
                'file' => '/app/phalcon/Http/Message/Response.zep',
                'line' => 95,
                'char' => 53,
              ),
              'file' => '/app/phalcon/Http/Message/Response.zep',
              'line' => 97,
              'char' => 14,
            ),
            3 => 
            array (
              'type' => 'return',
              'expr' => 
              array (
                'type' => 'variable',
                'value' => 'newInstance',
                'file' => '/app/phalcon/Http/Message/Response.zep',
                'line' => 97,
                'char' => 27,
              ),
              'file' => '/app/phalcon/Http/Message/Response.zep',
              'line' => 98,
              'char' => 5,
            ),
          ),
          'docblock' => '**
     * Return an instance with the specified status code and, optionally,
     * reason phrase.
     *
     * If no reason phrase is specified, implementations MAY choose to default
     * to the RFC 7231 or IANA recommended reason phrase for the response\'s
     * status code.
     *
     * This method MUST be implemented in such a way as to retain the
     * immutability of the message, and MUST return an instance that has the
     * updated status and reason phrase.
     *
     * @see http://tools.ietf.org/html/rfc7231#section-6
     * @see http://www.iana.org/assignments/http-status-codes/http-status-codes.xhtml
     *
     * @param int    $code
     * @param string $reasonPhrase
     *
     * @return Response
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
                  'value' => 'Response',
                  'file' => '/app/phalcon/Http/Message/Response.zep',
                  'line' => 90,
                  'char' => 5,
                ),
                'collection' => 0,
                'file' => '/app/phalcon/Http/Message/Response.zep',
                'line' => 90,
                'char' => 5,
              ),
            ),
            'void' => 0,
            'file' => '/app/phalcon/Http/Message/Response.zep',
            'line' => 90,
            'char' => 5,
          ),
          'file' => '/app/phalcon/Http/Message/Response.zep',
          'line' => 89,
          'last-line' => 104,
          'char' => 19,
        ),
        2 => 
        array (
          'visibility' => 
          array (
            0 => 'private',
          ),
          'type' => 'method',
          'name' => 'checkCodeType',
          'parameters' => 
          array (
            0 => 
            array (
              'type' => 'parameter',
              'name' => 'code',
              'const' => 0,
              'data-type' => 'variable',
              'mandatory' => 0,
              'reference' => 0,
              'file' => '/app/phalcon/Http/Message/Response.zep',
              'line' => 105,
              'char' => 44,
            ),
          ),
          'statements' => 
          array (
            0 => 
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
                        'type' => 'typeof',
                        'left' => 
                        array (
                          'type' => 'variable',
                          'value' => 'code',
                          'file' => '/app/phalcon/Http/Message/Response.zep',
                          'line' => 107,
                          'char' => 36,
                        ),
                        'file' => '/app/phalcon/Http/Message/Response.zep',
                        'line' => 107,
                        'char' => 36,
                      ),
                      'right' => 
                      array (
                        'type' => 'string',
                        'value' => 'int',
                        'file' => '/app/phalcon/Http/Message/Response.zep',
                        'line' => 107,
                        'char' => 43,
                      ),
                      'file' => '/app/phalcon/Http/Message/Response.zep',
                      'line' => 107,
                      'char' => 43,
                    ),
                    'right' => 
                    array (
                      'type' => 'not-identical',
                      'left' => 
                      array (
                        'type' => 'typeof',
                        'left' => 
                        array (
                          'type' => 'variable',
                          'value' => 'code',
                          'file' => '/app/phalcon/Http/Message/Response.zep',
                          'line' => 107,
                          'char' => 59,
                        ),
                        'file' => '/app/phalcon/Http/Message/Response.zep',
                        'line' => 107,
                        'char' => 59,
                      ),
                      'right' => 
                      array (
                        'type' => 'string',
                        'value' => 'string',
                        'file' => '/app/phalcon/Http/Message/Response.zep',
                        'line' => 107,
                        'char' => 67,
                      ),
                      'file' => '/app/phalcon/Http/Message/Response.zep',
                      'line' => 107,
                      'char' => 67,
                    ),
                    'file' => '/app/phalcon/Http/Message/Response.zep',
                    'line' => 107,
                    'char' => 67,
                  ),
                  'file' => '/app/phalcon/Http/Message/Response.zep',
                  'line' => 107,
                  'char' => 69,
                ),
                'file' => '/app/phalcon/Http/Message/Response.zep',
                'line' => 107,
                'char' => 69,
              ),
              'statements' => 
              array (
                0 => 
                array (
                  'type' => 'throw',
                  'expr' => 
                  array (
                    'type' => 'new',
                    'class' => 'InvalidArgumentException',
                    'dynamic' => 0,
                    'parameters' => 
                    array (
                      0 => 
                      array (
                        'parameter' => 
                        array (
                          'type' => 'string',
                          'value' => 'Invalid status code; it must be an integer or string',
                          'file' => '/app/phalcon/Http/Message/Response.zep',
                          'line' => 110,
                          'char' => 13,
                        ),
                        'file' => '/app/phalcon/Http/Message/Response.zep',
                        'line' => 110,
                        'char' => 13,
                      ),
                    ),
                    'file' => '/app/phalcon/Http/Message/Response.zep',
                    'line' => 110,
                    'char' => 14,
                  ),
                  'file' => '/app/phalcon/Http/Message/Response.zep',
                  'line' => 111,
                  'char' => 9,
                ),
              ),
              'file' => '/app/phalcon/Http/Message/Response.zep',
              'line' => 112,
              'char' => 5,
            ),
          ),
          'docblock' => '**
     * Checks if a code is integer or string
     *
     * @param mixed $code
     *',
          'return-type' => 
          array (
            'type' => 'return-type',
            'void' => 1,
            'file' => '/app/phalcon/Http/Message/Response.zep',
            'line' => 106,
            'char' => 5,
          ),
          'file' => '/app/phalcon/Http/Message/Response.zep',
          'line' => 105,
          'last-line' => 118,
          'char' => 20,
        ),
        3 => 
        array (
          'visibility' => 
          array (
            0 => 'private',
          ),
          'type' => 'method',
          'name' => 'checkCodeValue',
          'parameters' => 
          array (
            0 => 
            array (
              'type' => 'parameter',
              'name' => 'code',
              'const' => 0,
              'data-type' => 'int',
              'mandatory' => 0,
              'reference' => 0,
              'file' => '/app/phalcon/Http/Message/Response.zep',
              'line' => 119,
              'char' => 45,
            ),
          ),
          'statements' => 
          array (
            0 => 
            array (
              'type' => 'if',
              'expr' => 
              array (
                'type' => 'list',
                'left' => 
                array (
                  'type' => 'not-identical',
                  'left' => 
                  array (
                    'type' => 'bool',
                    'value' => 'true',
                    'file' => '/app/phalcon/Http/Message/Response.zep',
                    'line' => 121,
                    'char' => 20,
                  ),
                  'right' => 
                  array (
                    'type' => 'scall',
                    'dynamic-class' => 0,
                    'class' => 'Number',
                    'dynamic' => 0,
                    'name' => 'between',
                    'parameters' => 
                    array (
                      0 => 
                      array (
                        'parameter' => 
                        array (
                          'type' => 'variable',
                          'value' => 'code',
                          'file' => '/app/phalcon/Http/Message/Response.zep',
                          'line' => 121,
                          'char' => 42,
                        ),
                        'file' => '/app/phalcon/Http/Message/Response.zep',
                        'line' => 121,
                        'char' => 42,
                      ),
                      1 => 
                      array (
                        'parameter' => 
                        array (
                          'type' => 'int',
                          'value' => '100',
                          'file' => '/app/phalcon/Http/Message/Response.zep',
                          'line' => 121,
                          'char' => 47,
                        ),
                        'file' => '/app/phalcon/Http/Message/Response.zep',
                        'line' => 121,
                        'char' => 47,
                      ),
                      2 => 
                      array (
                        'parameter' => 
                        array (
                          'type' => 'int',
                          'value' => '599',
                          'file' => '/app/phalcon/Http/Message/Response.zep',
                          'line' => 121,
                          'char' => 52,
                        ),
                        'file' => '/app/phalcon/Http/Message/Response.zep',
                        'line' => 121,
                        'char' => 52,
                      ),
                    ),
                    'file' => '/app/phalcon/Http/Message/Response.zep',
                    'line' => 121,
                    'char' => 53,
                  ),
                  'file' => '/app/phalcon/Http/Message/Response.zep',
                  'line' => 121,
                  'char' => 53,
                ),
                'file' => '/app/phalcon/Http/Message/Response.zep',
                'line' => 121,
                'char' => 55,
              ),
              'statements' => 
              array (
                0 => 
                array (
                  'type' => 'throw',
                  'expr' => 
                  array (
                    'type' => 'new',
                    'class' => 'InvalidArgumentException',
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
                              'value' => 'Invalid status code \'',
                              'file' => '/app/phalcon/Http/Message/Response.zep',
                              'line' => 123,
                              'char' => 39,
                            ),
                            'right' => 
                            array (
                              'type' => 'variable',
                              'value' => 'code',
                              'file' => '/app/phalcon/Http/Message/Response.zep',
                              'line' => 123,
                              'char' => 46,
                            ),
                            'file' => '/app/phalcon/Http/Message/Response.zep',
                            'line' => 123,
                            'char' => 46,
                          ),
                          'right' => 
                          array (
                            'type' => 'string',
                            'value' => '\', (allowed values 100-599)',
                            'file' => '/app/phalcon/Http/Message/Response.zep',
                            'line' => 124,
                            'char' => 13,
                          ),
                          'file' => '/app/phalcon/Http/Message/Response.zep',
                          'line' => 124,
                          'char' => 13,
                        ),
                        'file' => '/app/phalcon/Http/Message/Response.zep',
                        'line' => 124,
                        'char' => 13,
                      ),
                    ),
                    'file' => '/app/phalcon/Http/Message/Response.zep',
                    'line' => 124,
                    'char' => 14,
                  ),
                  'file' => '/app/phalcon/Http/Message/Response.zep',
                  'line' => 125,
                  'char' => 9,
                ),
              ),
              'file' => '/app/phalcon/Http/Message/Response.zep',
              'line' => 126,
              'char' => 5,
            ),
          ),
          'docblock' => '**
     * Checks if a code is integer or string
     *
     * @param int $code
     *',
          'return-type' => 
          array (
            'type' => 'return-type',
            'void' => 1,
            'file' => '/app/phalcon/Http/Message/Response.zep',
            'line' => 120,
            'char' => 5,
          ),
          'file' => '/app/phalcon/Http/Message/Response.zep',
          'line' => 119,
          'last-line' => 130,
          'char' => 20,
        ),
        4 => 
        array (
          'visibility' => 
          array (
            0 => 'private',
          ),
          'type' => 'method',
          'name' => 'getPhrases',
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
                      'type' => 'int',
                      'value' => '100',
                      'file' => '/app/phalcon/Http/Message/Response.zep',
                      'line' => 134,
                      'char' => 17,
                    ),
                    'value' => 
                    array (
                      'type' => 'string',
                      'value' => 'Continue',
                      'file' => '/app/phalcon/Http/Message/Response.zep',
                      'line' => 134,
                      'char' => 27,
                    ),
                    'file' => '/app/phalcon/Http/Message/Response.zep',
                    'line' => 134,
                    'char' => 27,
                  ),
                  1 => 
                  array (
                    'key' => 
                    array (
                      'type' => 'int',
                      'value' => '101',
                      'file' => '/app/phalcon/Http/Message/Response.zep',
                      'line' => 135,
                      'char' => 17,
                    ),
                    'value' => 
                    array (
                      'type' => 'string',
                      'value' => 'Switching Protocols',
                      'file' => '/app/phalcon/Http/Message/Response.zep',
                      'line' => 135,
                      'char' => 38,
                    ),
                    'file' => '/app/phalcon/Http/Message/Response.zep',
                    'line' => 135,
                    'char' => 38,
                  ),
                  2 => 
                  array (
                    'key' => 
                    array (
                      'type' => 'int',
                      'value' => '102',
                      'file' => '/app/phalcon/Http/Message/Response.zep',
                      'line' => 136,
                      'char' => 17,
                    ),
                    'value' => 
                    array (
                      'type' => 'string',
                      'value' => 'Processing',
                      'file' => '/app/phalcon/Http/Message/Response.zep',
                      'line' => 136,
                      'char' => 29,
                    ),
                    'file' => '/app/phalcon/Http/Message/Response.zep',
                    'line' => 136,
                    'char' => 29,
                  ),
                  3 => 
                  array (
                    'key' => 
                    array (
                      'type' => 'int',
                      'value' => '103',
                      'file' => '/app/phalcon/Http/Message/Response.zep',
                      'line' => 137,
                      'char' => 17,
                    ),
                    'value' => 
                    array (
                      'type' => 'string',
                      'value' => 'Early Hints',
                      'file' => '/app/phalcon/Http/Message/Response.zep',
                      'line' => 137,
                      'char' => 30,
                    ),
                    'file' => '/app/phalcon/Http/Message/Response.zep',
                    'line' => 137,
                    'char' => 30,
                  ),
                  4 => 
                  array (
                    'key' => 
                    array (
                      'type' => 'int',
                      'value' => '200',
                      'file' => '/app/phalcon/Http/Message/Response.zep',
                      'line' => 138,
                      'char' => 17,
                    ),
                    'value' => 
                    array (
                      'type' => 'string',
                      'value' => 'OK',
                      'file' => '/app/phalcon/Http/Message/Response.zep',
                      'line' => 138,
                      'char' => 21,
                    ),
                    'file' => '/app/phalcon/Http/Message/Response.zep',
                    'line' => 138,
                    'char' => 21,
                  ),
                  5 => 
                  array (
                    'key' => 
                    array (
                      'type' => 'int',
                      'value' => '201',
                      'file' => '/app/phalcon/Http/Message/Response.zep',
                      'line' => 139,
                      'char' => 17,
                    ),
                    'value' => 
                    array (
                      'type' => 'string',
                      'value' => 'Created',
                      'file' => '/app/phalcon/Http/Message/Response.zep',
                      'line' => 139,
                      'char' => 26,
                    ),
                    'file' => '/app/phalcon/Http/Message/Response.zep',
                    'line' => 139,
                    'char' => 26,
                  ),
                  6 => 
                  array (
                    'key' => 
                    array (
                      'type' => 'int',
                      'value' => '202',
                      'file' => '/app/phalcon/Http/Message/Response.zep',
                      'line' => 140,
                      'char' => 17,
                    ),
                    'value' => 
                    array (
                      'type' => 'string',
                      'value' => 'Accepted',
                      'file' => '/app/phalcon/Http/Message/Response.zep',
                      'line' => 140,
                      'char' => 27,
                    ),
                    'file' => '/app/phalcon/Http/Message/Response.zep',
                    'line' => 140,
                    'char' => 27,
                  ),
                  7 => 
                  array (
                    'key' => 
                    array (
                      'type' => 'int',
                      'value' => '203',
                      'file' => '/app/phalcon/Http/Message/Response.zep',
                      'line' => 141,
                      'char' => 17,
                    ),
                    'value' => 
                    array (
                      'type' => 'string',
                      'value' => 'Non-Authoritative Information',
                      'file' => '/app/phalcon/Http/Message/Response.zep',
                      'line' => 141,
                      'char' => 48,
                    ),
                    'file' => '/app/phalcon/Http/Message/Response.zep',
                    'line' => 141,
                    'char' => 48,
                  ),
                  8 => 
                  array (
                    'key' => 
                    array (
                      'type' => 'int',
                      'value' => '204',
                      'file' => '/app/phalcon/Http/Message/Response.zep',
                      'line' => 142,
                      'char' => 17,
                    ),
                    'value' => 
                    array (
                      'type' => 'string',
                      'value' => 'No Content',
                      'file' => '/app/phalcon/Http/Message/Response.zep',
                      'line' => 142,
                      'char' => 29,
                    ),
                    'file' => '/app/phalcon/Http/Message/Response.zep',
                    'line' => 142,
                    'char' => 29,
                  ),
                  9 => 
                  array (
                    'key' => 
                    array (
                      'type' => 'int',
                      'value' => '205',
                      'file' => '/app/phalcon/Http/Message/Response.zep',
                      'line' => 143,
                      'char' => 17,
                    ),
                    'value' => 
                    array (
                      'type' => 'string',
                      'value' => 'Reset Content',
                      'file' => '/app/phalcon/Http/Message/Response.zep',
                      'line' => 143,
                      'char' => 32,
                    ),
                    'file' => '/app/phalcon/Http/Message/Response.zep',
                    'line' => 143,
                    'char' => 32,
                  ),
                  10 => 
                  array (
                    'key' => 
                    array (
                      'type' => 'int',
                      'value' => '206',
                      'file' => '/app/phalcon/Http/Message/Response.zep',
                      'line' => 144,
                      'char' => 17,
                    ),
                    'value' => 
                    array (
                      'type' => 'string',
                      'value' => 'Partial Content',
                      'file' => '/app/phalcon/Http/Message/Response.zep',
                      'line' => 144,
                      'char' => 34,
                    ),
                    'file' => '/app/phalcon/Http/Message/Response.zep',
                    'line' => 144,
                    'char' => 34,
                  ),
                  11 => 
                  array (
                    'key' => 
                    array (
                      'type' => 'int',
                      'value' => '207',
                      'file' => '/app/phalcon/Http/Message/Response.zep',
                      'line' => 145,
                      'char' => 17,
                    ),
                    'value' => 
                    array (
                      'type' => 'string',
                      'value' => 'Multi-status',
                      'file' => '/app/phalcon/Http/Message/Response.zep',
                      'line' => 145,
                      'char' => 31,
                    ),
                    'file' => '/app/phalcon/Http/Message/Response.zep',
                    'line' => 145,
                    'char' => 31,
                  ),
                  12 => 
                  array (
                    'key' => 
                    array (
                      'type' => 'int',
                      'value' => '208',
                      'file' => '/app/phalcon/Http/Message/Response.zep',
                      'line' => 146,
                      'char' => 17,
                    ),
                    'value' => 
                    array (
                      'type' => 'string',
                      'value' => 'Already Reported',
                      'file' => '/app/phalcon/Http/Message/Response.zep',
                      'line' => 146,
                      'char' => 35,
                    ),
                    'file' => '/app/phalcon/Http/Message/Response.zep',
                    'line' => 146,
                    'char' => 35,
                  ),
                  13 => 
                  array (
                    'key' => 
                    array (
                      'type' => 'int',
                      'value' => '218',
                      'file' => '/app/phalcon/Http/Message/Response.zep',
                      'line' => 147,
                      'char' => 17,
                    ),
                    'value' => 
                    array (
                      'type' => 'string',
                      'value' => 'This is fine',
                      'file' => '/app/phalcon/Http/Message/Response.zep',
                      'line' => 147,
                      'char' => 31,
                    ),
                    'file' => '/app/phalcon/Http/Message/Response.zep',
                    'line' => 147,
                    'char' => 31,
                  ),
                  14 => 
                  array (
                    'key' => 
                    array (
                      'type' => 'int',
                      'value' => '419',
                      'file' => '/app/phalcon/Http/Message/Response.zep',
                      'line' => 148,
                      'char' => 17,
                    ),
                    'value' => 
                    array (
                      'type' => 'string',
                      'value' => 'Page Expired',
                      'file' => '/app/phalcon/Http/Message/Response.zep',
                      'line' => 148,
                      'char' => 31,
                    ),
                    'file' => '/app/phalcon/Http/Message/Response.zep',
                    'line' => 148,
                    'char' => 31,
                  ),
                  15 => 
                  array (
                    'key' => 
                    array (
                      'type' => 'int',
                      'value' => '226',
                      'file' => '/app/phalcon/Http/Message/Response.zep',
                      'line' => 149,
                      'char' => 17,
                    ),
                    'value' => 
                    array (
                      'type' => 'string',
                      'value' => 'IM Used',
                      'file' => '/app/phalcon/Http/Message/Response.zep',
                      'line' => 149,
                      'char' => 26,
                    ),
                    'file' => '/app/phalcon/Http/Message/Response.zep',
                    'line' => 149,
                    'char' => 26,
                  ),
                  16 => 
                  array (
                    'key' => 
                    array (
                      'type' => 'int',
                      'value' => '300',
                      'file' => '/app/phalcon/Http/Message/Response.zep',
                      'line' => 150,
                      'char' => 17,
                    ),
                    'value' => 
                    array (
                      'type' => 'string',
                      'value' => 'Multiple Choices',
                      'file' => '/app/phalcon/Http/Message/Response.zep',
                      'line' => 150,
                      'char' => 35,
                    ),
                    'file' => '/app/phalcon/Http/Message/Response.zep',
                    'line' => 150,
                    'char' => 35,
                  ),
                  17 => 
                  array (
                    'key' => 
                    array (
                      'type' => 'int',
                      'value' => '301',
                      'file' => '/app/phalcon/Http/Message/Response.zep',
                      'line' => 151,
                      'char' => 17,
                    ),
                    'value' => 
                    array (
                      'type' => 'string',
                      'value' => 'Moved Permanently',
                      'file' => '/app/phalcon/Http/Message/Response.zep',
                      'line' => 151,
                      'char' => 36,
                    ),
                    'file' => '/app/phalcon/Http/Message/Response.zep',
                    'line' => 151,
                    'char' => 36,
                  ),
                  18 => 
                  array (
                    'key' => 
                    array (
                      'type' => 'int',
                      'value' => '302',
                      'file' => '/app/phalcon/Http/Message/Response.zep',
                      'line' => 152,
                      'char' => 17,
                    ),
                    'value' => 
                    array (
                      'type' => 'string',
                      'value' => 'Found',
                      'file' => '/app/phalcon/Http/Message/Response.zep',
                      'line' => 152,
                      'char' => 24,
                    ),
                    'file' => '/app/phalcon/Http/Message/Response.zep',
                    'line' => 152,
                    'char' => 24,
                  ),
                  19 => 
                  array (
                    'key' => 
                    array (
                      'type' => 'int',
                      'value' => '303',
                      'file' => '/app/phalcon/Http/Message/Response.zep',
                      'line' => 153,
                      'char' => 17,
                    ),
                    'value' => 
                    array (
                      'type' => 'string',
                      'value' => 'See Other',
                      'file' => '/app/phalcon/Http/Message/Response.zep',
                      'line' => 153,
                      'char' => 28,
                    ),
                    'file' => '/app/phalcon/Http/Message/Response.zep',
                    'line' => 153,
                    'char' => 28,
                  ),
                  20 => 
                  array (
                    'key' => 
                    array (
                      'type' => 'int',
                      'value' => '304',
                      'file' => '/app/phalcon/Http/Message/Response.zep',
                      'line' => 154,
                      'char' => 17,
                    ),
                    'value' => 
                    array (
                      'type' => 'string',
                      'value' => 'Not Modified',
                      'file' => '/app/phalcon/Http/Message/Response.zep',
                      'line' => 154,
                      'char' => 31,
                    ),
                    'file' => '/app/phalcon/Http/Message/Response.zep',
                    'line' => 154,
                    'char' => 31,
                  ),
                  21 => 
                  array (
                    'key' => 
                    array (
                      'type' => 'int',
                      'value' => '305',
                      'file' => '/app/phalcon/Http/Message/Response.zep',
                      'line' => 155,
                      'char' => 17,
                    ),
                    'value' => 
                    array (
                      'type' => 'string',
                      'value' => 'Use Proxy',
                      'file' => '/app/phalcon/Http/Message/Response.zep',
                      'line' => 155,
                      'char' => 28,
                    ),
                    'file' => '/app/phalcon/Http/Message/Response.zep',
                    'line' => 155,
                    'char' => 28,
                  ),
                  22 => 
                  array (
                    'key' => 
                    array (
                      'type' => 'int',
                      'value' => '306',
                      'file' => '/app/phalcon/Http/Message/Response.zep',
                      'line' => 156,
                      'char' => 17,
                    ),
                    'value' => 
                    array (
                      'type' => 'string',
                      'value' => 'Switch Proxy',
                      'file' => '/app/phalcon/Http/Message/Response.zep',
                      'line' => 156,
                      'char' => 31,
                    ),
                    'file' => '/app/phalcon/Http/Message/Response.zep',
                    'line' => 156,
                    'char' => 31,
                  ),
                  23 => 
                  array (
                    'key' => 
                    array (
                      'type' => 'int',
                      'value' => '307',
                      'file' => '/app/phalcon/Http/Message/Response.zep',
                      'line' => 157,
                      'char' => 17,
                    ),
                    'value' => 
                    array (
                      'type' => 'string',
                      'value' => 'Temporary Redirect',
                      'file' => '/app/phalcon/Http/Message/Response.zep',
                      'line' => 157,
                      'char' => 37,
                    ),
                    'file' => '/app/phalcon/Http/Message/Response.zep',
                    'line' => 157,
                    'char' => 37,
                  ),
                  24 => 
                  array (
                    'key' => 
                    array (
                      'type' => 'int',
                      'value' => '308',
                      'file' => '/app/phalcon/Http/Message/Response.zep',
                      'line' => 158,
                      'char' => 17,
                    ),
                    'value' => 
                    array (
                      'type' => 'string',
                      'value' => 'Permanent Redirect',
                      'file' => '/app/phalcon/Http/Message/Response.zep',
                      'line' => 158,
                      'char' => 37,
                    ),
                    'file' => '/app/phalcon/Http/Message/Response.zep',
                    'line' => 158,
                    'char' => 37,
                  ),
                  25 => 
                  array (
                    'key' => 
                    array (
                      'type' => 'int',
                      'value' => '400',
                      'file' => '/app/phalcon/Http/Message/Response.zep',
                      'line' => 159,
                      'char' => 17,
                    ),
                    'value' => 
                    array (
                      'type' => 'string',
                      'value' => 'Bad Request',
                      'file' => '/app/phalcon/Http/Message/Response.zep',
                      'line' => 159,
                      'char' => 30,
                    ),
                    'file' => '/app/phalcon/Http/Message/Response.zep',
                    'line' => 159,
                    'char' => 30,
                  ),
                  26 => 
                  array (
                    'key' => 
                    array (
                      'type' => 'int',
                      'value' => '401',
                      'file' => '/app/phalcon/Http/Message/Response.zep',
                      'line' => 160,
                      'char' => 17,
                    ),
                    'value' => 
                    array (
                      'type' => 'string',
                      'value' => 'Unauthorized',
                      'file' => '/app/phalcon/Http/Message/Response.zep',
                      'line' => 160,
                      'char' => 31,
                    ),
                    'file' => '/app/phalcon/Http/Message/Response.zep',
                    'line' => 160,
                    'char' => 31,
                  ),
                  27 => 
                  array (
                    'key' => 
                    array (
                      'type' => 'int',
                      'value' => '402',
                      'file' => '/app/phalcon/Http/Message/Response.zep',
                      'line' => 161,
                      'char' => 17,
                    ),
                    'value' => 
                    array (
                      'type' => 'string',
                      'value' => 'Payment Required',
                      'file' => '/app/phalcon/Http/Message/Response.zep',
                      'line' => 161,
                      'char' => 35,
                    ),
                    'file' => '/app/phalcon/Http/Message/Response.zep',
                    'line' => 161,
                    'char' => 35,
                  ),
                  28 => 
                  array (
                    'key' => 
                    array (
                      'type' => 'int',
                      'value' => '403',
                      'file' => '/app/phalcon/Http/Message/Response.zep',
                      'line' => 162,
                      'char' => 17,
                    ),
                    'value' => 
                    array (
                      'type' => 'string',
                      'value' => 'Forbidden',
                      'file' => '/app/phalcon/Http/Message/Response.zep',
                      'line' => 162,
                      'char' => 28,
                    ),
                    'file' => '/app/phalcon/Http/Message/Response.zep',
                    'line' => 162,
                    'char' => 28,
                  ),
                  29 => 
                  array (
                    'key' => 
                    array (
                      'type' => 'int',
                      'value' => '404',
                      'file' => '/app/phalcon/Http/Message/Response.zep',
                      'line' => 163,
                      'char' => 17,
                    ),
                    'value' => 
                    array (
                      'type' => 'string',
                      'value' => 'Not Found',
                      'file' => '/app/phalcon/Http/Message/Response.zep',
                      'line' => 163,
                      'char' => 28,
                    ),
                    'file' => '/app/phalcon/Http/Message/Response.zep',
                    'line' => 163,
                    'char' => 28,
                  ),
                  30 => 
                  array (
                    'key' => 
                    array (
                      'type' => 'int',
                      'value' => '405',
                      'file' => '/app/phalcon/Http/Message/Response.zep',
                      'line' => 164,
                      'char' => 17,
                    ),
                    'value' => 
                    array (
                      'type' => 'string',
                      'value' => 'Method Not Allowed',
                      'file' => '/app/phalcon/Http/Message/Response.zep',
                      'line' => 164,
                      'char' => 37,
                    ),
                    'file' => '/app/phalcon/Http/Message/Response.zep',
                    'line' => 164,
                    'char' => 37,
                  ),
                  31 => 
                  array (
                    'key' => 
                    array (
                      'type' => 'int',
                      'value' => '406',
                      'file' => '/app/phalcon/Http/Message/Response.zep',
                      'line' => 165,
                      'char' => 17,
                    ),
                    'value' => 
                    array (
                      'type' => 'string',
                      'value' => 'Not Acceptable',
                      'file' => '/app/phalcon/Http/Message/Response.zep',
                      'line' => 165,
                      'char' => 33,
                    ),
                    'file' => '/app/phalcon/Http/Message/Response.zep',
                    'line' => 165,
                    'char' => 33,
                  ),
                  32 => 
                  array (
                    'key' => 
                    array (
                      'type' => 'int',
                      'value' => '407',
                      'file' => '/app/phalcon/Http/Message/Response.zep',
                      'line' => 166,
                      'char' => 17,
                    ),
                    'value' => 
                    array (
                      'type' => 'string',
                      'value' => 'Proxy Authentication Required',
                      'file' => '/app/phalcon/Http/Message/Response.zep',
                      'line' => 166,
                      'char' => 48,
                    ),
                    'file' => '/app/phalcon/Http/Message/Response.zep',
                    'line' => 166,
                    'char' => 48,
                  ),
                  33 => 
                  array (
                    'key' => 
                    array (
                      'type' => 'int',
                      'value' => '408',
                      'file' => '/app/phalcon/Http/Message/Response.zep',
                      'line' => 167,
                      'char' => 17,
                    ),
                    'value' => 
                    array (
                      'type' => 'string',
                      'value' => 'Request Time-out',
                      'file' => '/app/phalcon/Http/Message/Response.zep',
                      'line' => 167,
                      'char' => 35,
                    ),
                    'file' => '/app/phalcon/Http/Message/Response.zep',
                    'line' => 167,
                    'char' => 35,
                  ),
                  34 => 
                  array (
                    'key' => 
                    array (
                      'type' => 'int',
                      'value' => '409',
                      'file' => '/app/phalcon/Http/Message/Response.zep',
                      'line' => 168,
                      'char' => 17,
                    ),
                    'value' => 
                    array (
                      'type' => 'string',
                      'value' => 'Conflict',
                      'file' => '/app/phalcon/Http/Message/Response.zep',
                      'line' => 168,
                      'char' => 27,
                    ),
                    'file' => '/app/phalcon/Http/Message/Response.zep',
                    'line' => 168,
                    'char' => 27,
                  ),
                  35 => 
                  array (
                    'key' => 
                    array (
                      'type' => 'int',
                      'value' => '410',
                      'file' => '/app/phalcon/Http/Message/Response.zep',
                      'line' => 169,
                      'char' => 17,
                    ),
                    'value' => 
                    array (
                      'type' => 'string',
                      'value' => 'Gone',
                      'file' => '/app/phalcon/Http/Message/Response.zep',
                      'line' => 169,
                      'char' => 23,
                    ),
                    'file' => '/app/phalcon/Http/Message/Response.zep',
                    'line' => 169,
                    'char' => 23,
                  ),
                  36 => 
                  array (
                    'key' => 
                    array (
                      'type' => 'int',
                      'value' => '411',
                      'file' => '/app/phalcon/Http/Message/Response.zep',
                      'line' => 170,
                      'char' => 17,
                    ),
                    'value' => 
                    array (
                      'type' => 'string',
                      'value' => 'Length Required',
                      'file' => '/app/phalcon/Http/Message/Response.zep',
                      'line' => 170,
                      'char' => 34,
                    ),
                    'file' => '/app/phalcon/Http/Message/Response.zep',
                    'line' => 170,
                    'char' => 34,
                  ),
                  37 => 
                  array (
                    'key' => 
                    array (
                      'type' => 'int',
                      'value' => '412',
                      'file' => '/app/phalcon/Http/Message/Response.zep',
                      'line' => 171,
                      'char' => 17,
                    ),
                    'value' => 
                    array (
                      'type' => 'string',
                      'value' => 'Precondition Failed',
                      'file' => '/app/phalcon/Http/Message/Response.zep',
                      'line' => 171,
                      'char' => 38,
                    ),
                    'file' => '/app/phalcon/Http/Message/Response.zep',
                    'line' => 171,
                    'char' => 38,
                  ),
                  38 => 
                  array (
                    'key' => 
                    array (
                      'type' => 'int',
                      'value' => '413',
                      'file' => '/app/phalcon/Http/Message/Response.zep',
                      'line' => 172,
                      'char' => 17,
                    ),
                    'value' => 
                    array (
                      'type' => 'string',
                      'value' => 'Request Entity Too Large',
                      'file' => '/app/phalcon/Http/Message/Response.zep',
                      'line' => 172,
                      'char' => 43,
                    ),
                    'file' => '/app/phalcon/Http/Message/Response.zep',
                    'line' => 172,
                    'char' => 43,
                  ),
                  39 => 
                  array (
                    'key' => 
                    array (
                      'type' => 'int',
                      'value' => '414',
                      'file' => '/app/phalcon/Http/Message/Response.zep',
                      'line' => 173,
                      'char' => 17,
                    ),
                    'value' => 
                    array (
                      'type' => 'string',
                      'value' => 'Request-URI Too Large',
                      'file' => '/app/phalcon/Http/Message/Response.zep',
                      'line' => 173,
                      'char' => 40,
                    ),
                    'file' => '/app/phalcon/Http/Message/Response.zep',
                    'line' => 173,
                    'char' => 40,
                  ),
                  40 => 
                  array (
                    'key' => 
                    array (
                      'type' => 'int',
                      'value' => '415',
                      'file' => '/app/phalcon/Http/Message/Response.zep',
                      'line' => 174,
                      'char' => 17,
                    ),
                    'value' => 
                    array (
                      'type' => 'string',
                      'value' => 'Unsupported Media Type',
                      'file' => '/app/phalcon/Http/Message/Response.zep',
                      'line' => 174,
                      'char' => 41,
                    ),
                    'file' => '/app/phalcon/Http/Message/Response.zep',
                    'line' => 174,
                    'char' => 41,
                  ),
                  41 => 
                  array (
                    'key' => 
                    array (
                      'type' => 'int',
                      'value' => '416',
                      'file' => '/app/phalcon/Http/Message/Response.zep',
                      'line' => 175,
                      'char' => 17,
                    ),
                    'value' => 
                    array (
                      'type' => 'string',
                      'value' => 'Requested range not satisfiable',
                      'file' => '/app/phalcon/Http/Message/Response.zep',
                      'line' => 175,
                      'char' => 50,
                    ),
                    'file' => '/app/phalcon/Http/Message/Response.zep',
                    'line' => 175,
                    'char' => 50,
                  ),
                  42 => 
                  array (
                    'key' => 
                    array (
                      'type' => 'int',
                      'value' => '417',
                      'file' => '/app/phalcon/Http/Message/Response.zep',
                      'line' => 176,
                      'char' => 17,
                    ),
                    'value' => 
                    array (
                      'type' => 'string',
                      'value' => 'Expectation Failed',
                      'file' => '/app/phalcon/Http/Message/Response.zep',
                      'line' => 176,
                      'char' => 37,
                    ),
                    'file' => '/app/phalcon/Http/Message/Response.zep',
                    'line' => 176,
                    'char' => 37,
                  ),
                  43 => 
                  array (
                    'key' => 
                    array (
                      'type' => 'int',
                      'value' => '418',
                      'file' => '/app/phalcon/Http/Message/Response.zep',
                      'line' => 177,
                      'char' => 17,
                    ),
                    'value' => 
                    array (
                      'type' => 'string',
                      'value' => 'I\'m a teapot',
                      'file' => '/app/phalcon/Http/Message/Response.zep',
                      'line' => 177,
                      'char' => 31,
                    ),
                    'file' => '/app/phalcon/Http/Message/Response.zep',
                    'line' => 177,
                    'char' => 31,
                  ),
                  44 => 
                  array (
                    'key' => 
                    array (
                      'type' => 'int',
                      'value' => '420',
                      'file' => '/app/phalcon/Http/Message/Response.zep',
                      'line' => 178,
                      'char' => 17,
                    ),
                    'value' => 
                    array (
                      'type' => 'string',
                      'value' => 'Method Failure',
                      'file' => '/app/phalcon/Http/Message/Response.zep',
                      'line' => 178,
                      'char' => 33,
                    ),
                    'file' => '/app/phalcon/Http/Message/Response.zep',
                    'line' => 178,
                    'char' => 33,
                  ),
                  45 => 
                  array (
                    'key' => 
                    array (
                      'type' => 'int',
                      'value' => '421',
                      'file' => '/app/phalcon/Http/Message/Response.zep',
                      'line' => 179,
                      'char' => 17,
                    ),
                    'value' => 
                    array (
                      'type' => 'string',
                      'value' => 'Misdirected Request',
                      'file' => '/app/phalcon/Http/Message/Response.zep',
                      'line' => 179,
                      'char' => 38,
                    ),
                    'file' => '/app/phalcon/Http/Message/Response.zep',
                    'line' => 179,
                    'char' => 38,
                  ),
                  46 => 
                  array (
                    'key' => 
                    array (
                      'type' => 'int',
                      'value' => '422',
                      'file' => '/app/phalcon/Http/Message/Response.zep',
                      'line' => 180,
                      'char' => 17,
                    ),
                    'value' => 
                    array (
                      'type' => 'string',
                      'value' => 'Unprocessable Entity',
                      'file' => '/app/phalcon/Http/Message/Response.zep',
                      'line' => 180,
                      'char' => 39,
                    ),
                    'file' => '/app/phalcon/Http/Message/Response.zep',
                    'line' => 180,
                    'char' => 39,
                  ),
                  47 => 
                  array (
                    'key' => 
                    array (
                      'type' => 'int',
                      'value' => '423',
                      'file' => '/app/phalcon/Http/Message/Response.zep',
                      'line' => 181,
                      'char' => 17,
                    ),
                    'value' => 
                    array (
                      'type' => 'string',
                      'value' => 'Locked',
                      'file' => '/app/phalcon/Http/Message/Response.zep',
                      'line' => 181,
                      'char' => 25,
                    ),
                    'file' => '/app/phalcon/Http/Message/Response.zep',
                    'line' => 181,
                    'char' => 25,
                  ),
                  48 => 
                  array (
                    'key' => 
                    array (
                      'type' => 'int',
                      'value' => '424',
                      'file' => '/app/phalcon/Http/Message/Response.zep',
                      'line' => 182,
                      'char' => 17,
                    ),
                    'value' => 
                    array (
                      'type' => 'string',
                      'value' => 'Failed Dependency',
                      'file' => '/app/phalcon/Http/Message/Response.zep',
                      'line' => 182,
                      'char' => 36,
                    ),
                    'file' => '/app/phalcon/Http/Message/Response.zep',
                    'line' => 182,
                    'char' => 36,
                  ),
                  49 => 
                  array (
                    'key' => 
                    array (
                      'type' => 'int',
                      'value' => '425',
                      'file' => '/app/phalcon/Http/Message/Response.zep',
                      'line' => 183,
                      'char' => 17,
                    ),
                    'value' => 
                    array (
                      'type' => 'string',
                      'value' => 'Unordered Collection',
                      'file' => '/app/phalcon/Http/Message/Response.zep',
                      'line' => 183,
                      'char' => 39,
                    ),
                    'file' => '/app/phalcon/Http/Message/Response.zep',
                    'line' => 183,
                    'char' => 39,
                  ),
                  50 => 
                  array (
                    'key' => 
                    array (
                      'type' => 'int',
                      'value' => '426',
                      'file' => '/app/phalcon/Http/Message/Response.zep',
                      'line' => 184,
                      'char' => 17,
                    ),
                    'value' => 
                    array (
                      'type' => 'string',
                      'value' => 'Upgrade Required',
                      'file' => '/app/phalcon/Http/Message/Response.zep',
                      'line' => 184,
                      'char' => 35,
                    ),
                    'file' => '/app/phalcon/Http/Message/Response.zep',
                    'line' => 184,
                    'char' => 35,
                  ),
                  51 => 
                  array (
                    'key' => 
                    array (
                      'type' => 'int',
                      'value' => '428',
                      'file' => '/app/phalcon/Http/Message/Response.zep',
                      'line' => 185,
                      'char' => 17,
                    ),
                    'value' => 
                    array (
                      'type' => 'string',
                      'value' => 'Precondition Required',
                      'file' => '/app/phalcon/Http/Message/Response.zep',
                      'line' => 185,
                      'char' => 40,
                    ),
                    'file' => '/app/phalcon/Http/Message/Response.zep',
                    'line' => 185,
                    'char' => 40,
                  ),
                  52 => 
                  array (
                    'key' => 
                    array (
                      'type' => 'int',
                      'value' => '429',
                      'file' => '/app/phalcon/Http/Message/Response.zep',
                      'line' => 186,
                      'char' => 17,
                    ),
                    'value' => 
                    array (
                      'type' => 'string',
                      'value' => 'Too Many Requests',
                      'file' => '/app/phalcon/Http/Message/Response.zep',
                      'line' => 186,
                      'char' => 36,
                    ),
                    'file' => '/app/phalcon/Http/Message/Response.zep',
                    'line' => 186,
                    'char' => 36,
                  ),
                  53 => 
                  array (
                    'key' => 
                    array (
                      'type' => 'int',
                      'value' => '431',
                      'file' => '/app/phalcon/Http/Message/Response.zep',
                      'line' => 187,
                      'char' => 17,
                    ),
                    'value' => 
                    array (
                      'type' => 'string',
                      'value' => 'Request Header Fields Too Large',
                      'file' => '/app/phalcon/Http/Message/Response.zep',
                      'line' => 187,
                      'char' => 50,
                    ),
                    'file' => '/app/phalcon/Http/Message/Response.zep',
                    'line' => 187,
                    'char' => 50,
                  ),
                  54 => 
                  array (
                    'key' => 
                    array (
                      'type' => 'int',
                      'value' => '440',
                      'file' => '/app/phalcon/Http/Message/Response.zep',
                      'line' => 188,
                      'char' => 17,
                    ),
                    'value' => 
                    array (
                      'type' => 'string',
                      'value' => 'Login Time-out',
                      'file' => '/app/phalcon/Http/Message/Response.zep',
                      'line' => 188,
                      'char' => 33,
                    ),
                    'file' => '/app/phalcon/Http/Message/Response.zep',
                    'line' => 188,
                    'char' => 33,
                  ),
                  55 => 
                  array (
                    'key' => 
                    array (
                      'type' => 'int',
                      'value' => '444',
                      'file' => '/app/phalcon/Http/Message/Response.zep',
                      'line' => 189,
                      'char' => 17,
                    ),
                    'value' => 
                    array (
                      'type' => 'string',
                      'value' => 'No Response',
                      'file' => '/app/phalcon/Http/Message/Response.zep',
                      'line' => 189,
                      'char' => 30,
                    ),
                    'file' => '/app/phalcon/Http/Message/Response.zep',
                    'line' => 189,
                    'char' => 30,
                  ),
                  56 => 
                  array (
                    'key' => 
                    array (
                      'type' => 'int',
                      'value' => '449',
                      'file' => '/app/phalcon/Http/Message/Response.zep',
                      'line' => 190,
                      'char' => 17,
                    ),
                    'value' => 
                    array (
                      'type' => 'string',
                      'value' => 'Retry With',
                      'file' => '/app/phalcon/Http/Message/Response.zep',
                      'line' => 190,
                      'char' => 29,
                    ),
                    'file' => '/app/phalcon/Http/Message/Response.zep',
                    'line' => 190,
                    'char' => 29,
                  ),
                  57 => 
                  array (
                    'key' => 
                    array (
                      'type' => 'int',
                      'value' => '494',
                      'file' => '/app/phalcon/Http/Message/Response.zep',
                      'line' => 191,
                      'char' => 17,
                    ),
                    'value' => 
                    array (
                      'type' => 'string',
                      'value' => 'Request header too large',
                      'file' => '/app/phalcon/Http/Message/Response.zep',
                      'line' => 191,
                      'char' => 43,
                    ),
                    'file' => '/app/phalcon/Http/Message/Response.zep',
                    'line' => 191,
                    'char' => 43,
                  ),
                  58 => 
                  array (
                    'key' => 
                    array (
                      'type' => 'int',
                      'value' => '495',
                      'file' => '/app/phalcon/Http/Message/Response.zep',
                      'line' => 192,
                      'char' => 17,
                    ),
                    'value' => 
                    array (
                      'type' => 'string',
                      'value' => 'SSL Certificate Error',
                      'file' => '/app/phalcon/Http/Message/Response.zep',
                      'line' => 192,
                      'char' => 40,
                    ),
                    'file' => '/app/phalcon/Http/Message/Response.zep',
                    'line' => 192,
                    'char' => 40,
                  ),
                  59 => 
                  array (
                    'key' => 
                    array (
                      'type' => 'int',
                      'value' => '496',
                      'file' => '/app/phalcon/Http/Message/Response.zep',
                      'line' => 193,
                      'char' => 17,
                    ),
                    'value' => 
                    array (
                      'type' => 'string',
                      'value' => 'SSL Certificate Required',
                      'file' => '/app/phalcon/Http/Message/Response.zep',
                      'line' => 193,
                      'char' => 43,
                    ),
                    'file' => '/app/phalcon/Http/Message/Response.zep',
                    'line' => 193,
                    'char' => 43,
                  ),
                  60 => 
                  array (
                    'key' => 
                    array (
                      'type' => 'int',
                      'value' => '497',
                      'file' => '/app/phalcon/Http/Message/Response.zep',
                      'line' => 194,
                      'char' => 17,
                    ),
                    'value' => 
                    array (
                      'type' => 'string',
                      'value' => 'HTTP Request Sent to HTTPS Port',
                      'file' => '/app/phalcon/Http/Message/Response.zep',
                      'line' => 194,
                      'char' => 50,
                    ),
                    'file' => '/app/phalcon/Http/Message/Response.zep',
                    'line' => 194,
                    'char' => 50,
                  ),
                  61 => 
                  array (
                    'key' => 
                    array (
                      'type' => 'int',
                      'value' => '499',
                      'file' => '/app/phalcon/Http/Message/Response.zep',
                      'line' => 195,
                      'char' => 17,
                    ),
                    'value' => 
                    array (
                      'type' => 'string',
                      'value' => 'Client Closed Request',
                      'file' => '/app/phalcon/Http/Message/Response.zep',
                      'line' => 195,
                      'char' => 40,
                    ),
                    'file' => '/app/phalcon/Http/Message/Response.zep',
                    'line' => 195,
                    'char' => 40,
                  ),
                  62 => 
                  array (
                    'key' => 
                    array (
                      'type' => 'int',
                      'value' => '450',
                      'file' => '/app/phalcon/Http/Message/Response.zep',
                      'line' => 196,
                      'char' => 17,
                    ),
                    'value' => 
                    array (
                      'type' => 'string',
                      'value' => 'Blocked by Windows Parental Controls (Microsoft)',
                      'file' => '/app/phalcon/Http/Message/Response.zep',
                      'line' => 196,
                      'char' => 67,
                    ),
                    'file' => '/app/phalcon/Http/Message/Response.zep',
                    'line' => 196,
                    'char' => 67,
                  ),
                  63 => 
                  array (
                    'key' => 
                    array (
                      'type' => 'int',
                      'value' => '451',
                      'file' => '/app/phalcon/Http/Message/Response.zep',
                      'line' => 197,
                      'char' => 17,
                    ),
                    'value' => 
                    array (
                      'type' => 'string',
                      'value' => 'Unavailable For Legal Reasons',
                      'file' => '/app/phalcon/Http/Message/Response.zep',
                      'line' => 197,
                      'char' => 48,
                    ),
                    'file' => '/app/phalcon/Http/Message/Response.zep',
                    'line' => 197,
                    'char' => 48,
                  ),
                  64 => 
                  array (
                    'key' => 
                    array (
                      'type' => 'int',
                      'value' => '498',
                      'file' => '/app/phalcon/Http/Message/Response.zep',
                      'line' => 198,
                      'char' => 17,
                    ),
                    'value' => 
                    array (
                      'type' => 'string',
                      'value' => 'Invalid Token (Esri)',
                      'file' => '/app/phalcon/Http/Message/Response.zep',
                      'line' => 198,
                      'char' => 39,
                    ),
                    'file' => '/app/phalcon/Http/Message/Response.zep',
                    'line' => 198,
                    'char' => 39,
                  ),
                  65 => 
                  array (
                    'key' => 
                    array (
                      'type' => 'int',
                      'value' => '500',
                      'file' => '/app/phalcon/Http/Message/Response.zep',
                      'line' => 199,
                      'char' => 17,
                    ),
                    'value' => 
                    array (
                      'type' => 'string',
                      'value' => 'Internal Server Error',
                      'file' => '/app/phalcon/Http/Message/Response.zep',
                      'line' => 199,
                      'char' => 40,
                    ),
                    'file' => '/app/phalcon/Http/Message/Response.zep',
                    'line' => 199,
                    'char' => 40,
                  ),
                  66 => 
                  array (
                    'key' => 
                    array (
                      'type' => 'int',
                      'value' => '501',
                      'file' => '/app/phalcon/Http/Message/Response.zep',
                      'line' => 200,
                      'char' => 17,
                    ),
                    'value' => 
                    array (
                      'type' => 'string',
                      'value' => 'Not Implemented',
                      'file' => '/app/phalcon/Http/Message/Response.zep',
                      'line' => 200,
                      'char' => 34,
                    ),
                    'file' => '/app/phalcon/Http/Message/Response.zep',
                    'line' => 200,
                    'char' => 34,
                  ),
                  67 => 
                  array (
                    'key' => 
                    array (
                      'type' => 'int',
                      'value' => '502',
                      'file' => '/app/phalcon/Http/Message/Response.zep',
                      'line' => 201,
                      'char' => 17,
                    ),
                    'value' => 
                    array (
                      'type' => 'string',
                      'value' => 'Bad Gateway',
                      'file' => '/app/phalcon/Http/Message/Response.zep',
                      'line' => 201,
                      'char' => 30,
                    ),
                    'file' => '/app/phalcon/Http/Message/Response.zep',
                    'line' => 201,
                    'char' => 30,
                  ),
                  68 => 
                  array (
                    'key' => 
                    array (
                      'type' => 'int',
                      'value' => '503',
                      'file' => '/app/phalcon/Http/Message/Response.zep',
                      'line' => 202,
                      'char' => 17,
                    ),
                    'value' => 
                    array (
                      'type' => 'string',
                      'value' => 'Service Unavailable',
                      'file' => '/app/phalcon/Http/Message/Response.zep',
                      'line' => 202,
                      'char' => 38,
                    ),
                    'file' => '/app/phalcon/Http/Message/Response.zep',
                    'line' => 202,
                    'char' => 38,
                  ),
                  69 => 
                  array (
                    'key' => 
                    array (
                      'type' => 'int',
                      'value' => '504',
                      'file' => '/app/phalcon/Http/Message/Response.zep',
                      'line' => 203,
                      'char' => 17,
                    ),
                    'value' => 
                    array (
                      'type' => 'string',
                      'value' => 'Gateway Time-out',
                      'file' => '/app/phalcon/Http/Message/Response.zep',
                      'line' => 203,
                      'char' => 35,
                    ),
                    'file' => '/app/phalcon/Http/Message/Response.zep',
                    'line' => 203,
                    'char' => 35,
                  ),
                  70 => 
                  array (
                    'key' => 
                    array (
                      'type' => 'int',
                      'value' => '505',
                      'file' => '/app/phalcon/Http/Message/Response.zep',
                      'line' => 204,
                      'char' => 17,
                    ),
                    'value' => 
                    array (
                      'type' => 'string',
                      'value' => 'HTTP Version not supported',
                      'file' => '/app/phalcon/Http/Message/Response.zep',
                      'line' => 204,
                      'char' => 45,
                    ),
                    'file' => '/app/phalcon/Http/Message/Response.zep',
                    'line' => 204,
                    'char' => 45,
                  ),
                  71 => 
                  array (
                    'key' => 
                    array (
                      'type' => 'int',
                      'value' => '506',
                      'file' => '/app/phalcon/Http/Message/Response.zep',
                      'line' => 205,
                      'char' => 17,
                    ),
                    'value' => 
                    array (
                      'type' => 'string',
                      'value' => 'Variant Also Negotiates',
                      'file' => '/app/phalcon/Http/Message/Response.zep',
                      'line' => 205,
                      'char' => 42,
                    ),
                    'file' => '/app/phalcon/Http/Message/Response.zep',
                    'line' => 205,
                    'char' => 42,
                  ),
                  72 => 
                  array (
                    'key' => 
                    array (
                      'type' => 'int',
                      'value' => '507',
                      'file' => '/app/phalcon/Http/Message/Response.zep',
                      'line' => 206,
                      'char' => 17,
                    ),
                    'value' => 
                    array (
                      'type' => 'string',
                      'value' => 'Insufficient Storage',
                      'file' => '/app/phalcon/Http/Message/Response.zep',
                      'line' => 206,
                      'char' => 39,
                    ),
                    'file' => '/app/phalcon/Http/Message/Response.zep',
                    'line' => 206,
                    'char' => 39,
                  ),
                  73 => 
                  array (
                    'key' => 
                    array (
                      'type' => 'int',
                      'value' => '508',
                      'file' => '/app/phalcon/Http/Message/Response.zep',
                      'line' => 207,
                      'char' => 17,
                    ),
                    'value' => 
                    array (
                      'type' => 'string',
                      'value' => 'Loop Detected',
                      'file' => '/app/phalcon/Http/Message/Response.zep',
                      'line' => 207,
                      'char' => 32,
                    ),
                    'file' => '/app/phalcon/Http/Message/Response.zep',
                    'line' => 207,
                    'char' => 32,
                  ),
                  74 => 
                  array (
                    'key' => 
                    array (
                      'type' => 'int',
                      'value' => '509',
                      'file' => '/app/phalcon/Http/Message/Response.zep',
                      'line' => 208,
                      'char' => 17,
                    ),
                    'value' => 
                    array (
                      'type' => 'string',
                      'value' => 'Bandwidth Limit Exceeded',
                      'file' => '/app/phalcon/Http/Message/Response.zep',
                      'line' => 208,
                      'char' => 43,
                    ),
                    'file' => '/app/phalcon/Http/Message/Response.zep',
                    'line' => 208,
                    'char' => 43,
                  ),
                  75 => 
                  array (
                    'key' => 
                    array (
                      'type' => 'int',
                      'value' => '510',
                      'file' => '/app/phalcon/Http/Message/Response.zep',
                      'line' => 209,
                      'char' => 17,
                    ),
                    'value' => 
                    array (
                      'type' => 'string',
                      'value' => 'Not Extended',
                      'file' => '/app/phalcon/Http/Message/Response.zep',
                      'line' => 209,
                      'char' => 31,
                    ),
                    'file' => '/app/phalcon/Http/Message/Response.zep',
                    'line' => 209,
                    'char' => 31,
                  ),
                  76 => 
                  array (
                    'key' => 
                    array (
                      'type' => 'int',
                      'value' => '511',
                      'file' => '/app/phalcon/Http/Message/Response.zep',
                      'line' => 210,
                      'char' => 17,
                    ),
                    'value' => 
                    array (
                      'type' => 'string',
                      'value' => 'Network Authentication Required',
                      'file' => '/app/phalcon/Http/Message/Response.zep',
                      'line' => 210,
                      'char' => 50,
                    ),
                    'file' => '/app/phalcon/Http/Message/Response.zep',
                    'line' => 210,
                    'char' => 50,
                  ),
                  77 => 
                  array (
                    'key' => 
                    array (
                      'type' => 'int',
                      'value' => '520',
                      'file' => '/app/phalcon/Http/Message/Response.zep',
                      'line' => 211,
                      'char' => 17,
                    ),
                    'value' => 
                    array (
                      'type' => 'string',
                      'value' => 'Unknown Error',
                      'file' => '/app/phalcon/Http/Message/Response.zep',
                      'line' => 211,
                      'char' => 32,
                    ),
                    'file' => '/app/phalcon/Http/Message/Response.zep',
                    'line' => 211,
                    'char' => 32,
                  ),
                  78 => 
                  array (
                    'key' => 
                    array (
                      'type' => 'int',
                      'value' => '521',
                      'file' => '/app/phalcon/Http/Message/Response.zep',
                      'line' => 212,
                      'char' => 17,
                    ),
                    'value' => 
                    array (
                      'type' => 'string',
                      'value' => 'Web Server Is Down',
                      'file' => '/app/phalcon/Http/Message/Response.zep',
                      'line' => 212,
                      'char' => 37,
                    ),
                    'file' => '/app/phalcon/Http/Message/Response.zep',
                    'line' => 212,
                    'char' => 37,
                  ),
                  79 => 
                  array (
                    'key' => 
                    array (
                      'type' => 'int',
                      'value' => '522',
                      'file' => '/app/phalcon/Http/Message/Response.zep',
                      'line' => 213,
                      'char' => 17,
                    ),
                    'value' => 
                    array (
                      'type' => 'string',
                      'value' => 'Connection Timed Out',
                      'file' => '/app/phalcon/Http/Message/Response.zep',
                      'line' => 213,
                      'char' => 39,
                    ),
                    'file' => '/app/phalcon/Http/Message/Response.zep',
                    'line' => 213,
                    'char' => 39,
                  ),
                  80 => 
                  array (
                    'key' => 
                    array (
                      'type' => 'int',
                      'value' => '523',
                      'file' => '/app/phalcon/Http/Message/Response.zep',
                      'line' => 214,
                      'char' => 17,
                    ),
                    'value' => 
                    array (
                      'type' => 'string',
                      'value' => 'Origin Is Unreachable',
                      'file' => '/app/phalcon/Http/Message/Response.zep',
                      'line' => 214,
                      'char' => 40,
                    ),
                    'file' => '/app/phalcon/Http/Message/Response.zep',
                    'line' => 214,
                    'char' => 40,
                  ),
                  81 => 
                  array (
                    'key' => 
                    array (
                      'type' => 'int',
                      'value' => '524',
                      'file' => '/app/phalcon/Http/Message/Response.zep',
                      'line' => 215,
                      'char' => 17,
                    ),
                    'value' => 
                    array (
                      'type' => 'string',
                      'value' => 'A Timeout Occurred',
                      'file' => '/app/phalcon/Http/Message/Response.zep',
                      'line' => 215,
                      'char' => 37,
                    ),
                    'file' => '/app/phalcon/Http/Message/Response.zep',
                    'line' => 215,
                    'char' => 37,
                  ),
                  82 => 
                  array (
                    'key' => 
                    array (
                      'type' => 'int',
                      'value' => '525',
                      'file' => '/app/phalcon/Http/Message/Response.zep',
                      'line' => 216,
                      'char' => 17,
                    ),
                    'value' => 
                    array (
                      'type' => 'string',
                      'value' => 'SSL Handshake Failed',
                      'file' => '/app/phalcon/Http/Message/Response.zep',
                      'line' => 216,
                      'char' => 39,
                    ),
                    'file' => '/app/phalcon/Http/Message/Response.zep',
                    'line' => 216,
                    'char' => 39,
                  ),
                  83 => 
                  array (
                    'key' => 
                    array (
                      'type' => 'int',
                      'value' => '526',
                      'file' => '/app/phalcon/Http/Message/Response.zep',
                      'line' => 217,
                      'char' => 17,
                    ),
                    'value' => 
                    array (
                      'type' => 'string',
                      'value' => 'Invalid SSL Certificate',
                      'file' => '/app/phalcon/Http/Message/Response.zep',
                      'line' => 217,
                      'char' => 42,
                    ),
                    'file' => '/app/phalcon/Http/Message/Response.zep',
                    'line' => 217,
                    'char' => 42,
                  ),
                  84 => 
                  array (
                    'key' => 
                    array (
                      'type' => 'int',
                      'value' => '527',
                      'file' => '/app/phalcon/Http/Message/Response.zep',
                      'line' => 218,
                      'char' => 17,
                    ),
                    'value' => 
                    array (
                      'type' => 'string',
                      'value' => 'Railgun Error',
                      'file' => '/app/phalcon/Http/Message/Response.zep',
                      'line' => 218,
                      'char' => 32,
                    ),
                    'file' => '/app/phalcon/Http/Message/Response.zep',
                    'line' => 218,
                    'char' => 32,
                  ),
                  85 => 
                  array (
                    'key' => 
                    array (
                      'type' => 'int',
                      'value' => '530',
                      'file' => '/app/phalcon/Http/Message/Response.zep',
                      'line' => 219,
                      'char' => 17,
                    ),
                    'value' => 
                    array (
                      'type' => 'string',
                      'value' => 'Origin DNS Error',
                      'file' => '/app/phalcon/Http/Message/Response.zep',
                      'line' => 219,
                      'char' => 35,
                    ),
                    'file' => '/app/phalcon/Http/Message/Response.zep',
                    'line' => 219,
                    'char' => 35,
                  ),
                  86 => 
                  array (
                    'key' => 
                    array (
                      'type' => 'int',
                      'value' => '598',
                      'file' => '/app/phalcon/Http/Message/Response.zep',
                      'line' => 220,
                      'char' => 17,
                    ),
                    'value' => 
                    array (
                      'type' => 'string',
                      'value' => 'Network read timeout error',
                      'file' => '/app/phalcon/Http/Message/Response.zep',
                      'line' => 220,
                      'char' => 45,
                    ),
                    'file' => '/app/phalcon/Http/Message/Response.zep',
                    'line' => 220,
                    'char' => 45,
                  ),
                  87 => 
                  array (
                    'key' => 
                    array (
                      'type' => 'int',
                      'value' => '599',
                      'file' => '/app/phalcon/Http/Message/Response.zep',
                      'line' => 221,
                      'char' => 17,
                    ),
                    'value' => 
                    array (
                      'type' => 'string',
                      'value' => 'Network Connect Timeout Error',
                      'file' => '/app/phalcon/Http/Message/Response.zep',
                      'line' => 222,
                      'char' => 9,
                    ),
                    'file' => '/app/phalcon/Http/Message/Response.zep',
                    'line' => 222,
                    'char' => 9,
                  ),
                ),
                'file' => '/app/phalcon/Http/Message/Response.zep',
                'line' => 222,
                'char' => 10,
              ),
              'file' => '/app/phalcon/Http/Message/Response.zep',
              'line' => 223,
              'char' => 5,
            ),
          ),
          'docblock' => '**
     * Returns the list of status codes available
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
                'file' => '/app/phalcon/Http/Message/Response.zep',
                'line' => 132,
                'char' => 5,
              ),
            ),
            'void' => 0,
            'file' => '/app/phalcon/Http/Message/Response.zep',
            'line' => 132,
            'char' => 5,
          ),
          'file' => '/app/phalcon/Http/Message/Response.zep',
          'line' => 131,
          'last-line' => 230,
          'char' => 20,
        ),
        5 => 
        array (
          'visibility' => 
          array (
            0 => 'private',
          ),
          'type' => 'method',
          'name' => 'processCode',
          'parameters' => 
          array (
            0 => 
            array (
              'type' => 'parameter',
              'name' => 'code',
              'const' => 0,
              'data-type' => 'variable',
              'mandatory' => 0,
              'reference' => 0,
              'file' => '/app/phalcon/Http/Message/Response.zep',
              'line' => 231,
              'char' => 42,
            ),
            1 => 
            array (
              'type' => 'parameter',
              'name' => 'phrase',
              'const' => 0,
              'data-type' => 'variable',
              'mandatory' => 0,
              'default' => 
              array (
                'type' => 'string',
                'value' => '',
                'file' => '/app/phalcon/Http/Message/Response.zep',
                'line' => 231,
                'char' => 57,
              ),
              'reference' => 0,
              'file' => '/app/phalcon/Http/Message/Response.zep',
              'line' => 231,
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
                  'variable' => 'phrases',
                  'file' => '/app/phalcon/Http/Message/Response.zep',
                  'line' => 233,
                  'char' => 20,
                ),
              ),
              'file' => '/app/phalcon/Http/Message/Response.zep',
              'line' => 235,
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
                  'variable' => 'phrases',
                  'expr' => 
                  array (
                    'type' => 'mcall',
                    'variable' => 
                    array (
                      'type' => 'variable',
                      'value' => 'this',
                      'file' => '/app/phalcon/Http/Message/Response.zep',
                      'line' => 235,
                      'char' => 28,
                    ),
                    'name' => 'getPhrases',
                    'call-type' => 1,
                    'file' => '/app/phalcon/Http/Message/Response.zep',
                    'line' => 235,
                    'char' => 41,
                  ),
                  'file' => '/app/phalcon/Http/Message/Response.zep',
                  'line' => 235,
                  'char' => 41,
                ),
              ),
              'file' => '/app/phalcon/Http/Message/Response.zep',
              'line' => 237,
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
                  'file' => '/app/phalcon/Http/Message/Response.zep',
                  'line' => 237,
                  'char' => 14,
                ),
                'name' => 'checkCodeType',
                'call-type' => 1,
                'parameters' => 
                array (
                  0 => 
                  array (
                    'parameter' => 
                    array (
                      'type' => 'variable',
                      'value' => 'code',
                      'file' => '/app/phalcon/Http/Message/Response.zep',
                      'line' => 237,
                      'char' => 33,
                    ),
                    'file' => '/app/phalcon/Http/Message/Response.zep',
                    'line' => 237,
                    'char' => 33,
                  ),
                ),
                'file' => '/app/phalcon/Http/Message/Response.zep',
                'line' => 237,
                'char' => 34,
              ),
              'file' => '/app/phalcon/Http/Message/Response.zep',
              'line' => 239,
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
                  'variable' => 'code',
                  'expr' => 
                  array (
                    'type' => 'cast',
                    'left' => 'int',
                    'right' => 
                    array (
                      'type' => 'variable',
                      'value' => 'code',
                      'file' => '/app/phalcon/Http/Message/Response.zep',
                      'line' => 239,
                      'char' => 30,
                    ),
                    'file' => '/app/phalcon/Http/Message/Response.zep',
                    'line' => 239,
                    'char' => 30,
                  ),
                  'file' => '/app/phalcon/Http/Message/Response.zep',
                  'line' => 239,
                  'char' => 30,
                ),
              ),
              'file' => '/app/phalcon/Http/Message/Response.zep',
              'line' => 240,
              'char' => 12,
            ),
            4 => 
            array (
              'type' => 'mcall',
              'expr' => 
              array (
                'type' => 'mcall',
                'variable' => 
                array (
                  'type' => 'variable',
                  'value' => 'this',
                  'file' => '/app/phalcon/Http/Message/Response.zep',
                  'line' => 240,
                  'char' => 14,
                ),
                'name' => 'checkCodeValue',
                'call-type' => 1,
                'parameters' => 
                array (
                  0 => 
                  array (
                    'parameter' => 
                    array (
                      'type' => 'variable',
                      'value' => 'code',
                      'file' => '/app/phalcon/Http/Message/Response.zep',
                      'line' => 240,
                      'char' => 34,
                    ),
                    'file' => '/app/phalcon/Http/Message/Response.zep',
                    'line' => 240,
                    'char' => 34,
                  ),
                ),
                'file' => '/app/phalcon/Http/Message/Response.zep',
                'line' => 240,
                'char' => 35,
              ),
              'file' => '/app/phalcon/Http/Message/Response.zep',
              'line' => 242,
              'char' => 10,
            ),
            5 => 
            array (
              'type' => 'if',
              'expr' => 
              array (
                'type' => 'unlikely',
                'left' => 
                array (
                  'type' => 'not-identical',
                  'left' => 
                  array (
                    'type' => 'typeof',
                    'left' => 
                    array (
                      'type' => 'variable',
                      'value' => 'phrase',
                      'file' => '/app/phalcon/Http/Message/Response.zep',
                      'line' => 242,
                      'char' => 37,
                    ),
                    'file' => '/app/phalcon/Http/Message/Response.zep',
                    'line' => 242,
                    'char' => 37,
                  ),
                  'right' => 
                  array (
                    'type' => 'string',
                    'value' => 'string',
                    'file' => '/app/phalcon/Http/Message/Response.zep',
                    'line' => 242,
                    'char' => 46,
                  ),
                  'file' => '/app/phalcon/Http/Message/Response.zep',
                  'line' => 242,
                  'char' => 46,
                ),
                'file' => '/app/phalcon/Http/Message/Response.zep',
                'line' => 242,
                'char' => 46,
              ),
              'statements' => 
              array (
                0 => 
                array (
                  'type' => 'throw',
                  'expr' => 
                  array (
                    'type' => 'new',
                    'class' => 'InvalidArgumentException',
                    'dynamic' => 0,
                    'parameters' => 
                    array (
                      0 => 
                      array (
                        'parameter' => 
                        array (
                          'type' => 'string',
                          'value' => 'Invalid response reason',
                          'file' => '/app/phalcon/Http/Message/Response.zep',
                          'line' => 243,
                          'char' => 71,
                        ),
                        'file' => '/app/phalcon/Http/Message/Response.zep',
                        'line' => 243,
                        'char' => 71,
                      ),
                    ),
                    'file' => '/app/phalcon/Http/Message/Response.zep',
                    'line' => 243,
                    'char' => 72,
                  ),
                  'file' => '/app/phalcon/Http/Message/Response.zep',
                  'line' => 244,
                  'char' => 9,
                ),
              ),
              'file' => '/app/phalcon/Http/Message/Response.zep',
              'line' => 246,
              'char' => 10,
            ),
            6 => 
            array (
              'type' => 'if',
              'expr' => 
              array (
                'type' => 'likely',
                'left' => 
                array (
                  'type' => 'and',
                  'left' => 
                  array (
                    'type' => 'identical',
                    'left' => 
                    array (
                      'type' => 'string',
                      'value' => '',
                      'file' => '/app/phalcon/Http/Message/Response.zep',
                      'line' => 246,
                      'char' => 22,
                    ),
                    'right' => 
                    array (
                      'type' => 'variable',
                      'value' => 'phrase',
                      'file' => '/app/phalcon/Http/Message/Response.zep',
                      'line' => 246,
                      'char' => 32,
                    ),
                    'file' => '/app/phalcon/Http/Message/Response.zep',
                    'line' => 246,
                    'char' => 32,
                  ),
                  'right' => 
                  array (
                    'type' => 'isset',
                    'left' => 
                    array (
                      'type' => 'array-access',
                      'left' => 
                      array (
                        'type' => 'variable',
                        'value' => 'phrases',
                        'file' => '/app/phalcon/Http/Message/Response.zep',
                        'line' => 246,
                        'char' => 47,
                      ),
                      'right' => 
                      array (
                        'type' => 'variable',
                        'value' => 'code',
                        'file' => '/app/phalcon/Http/Message/Response.zep',
                        'line' => 246,
                        'char' => 52,
                      ),
                      'file' => '/app/phalcon/Http/Message/Response.zep',
                      'line' => 246,
                      'char' => 54,
                    ),
                    'file' => '/app/phalcon/Http/Message/Response.zep',
                    'line' => 246,
                    'char' => 54,
                  ),
                  'file' => '/app/phalcon/Http/Message/Response.zep',
                  'line' => 246,
                  'char' => 54,
                ),
                'file' => '/app/phalcon/Http/Message/Response.zep',
                'line' => 246,
                'char' => 54,
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
                      'variable' => 'phrase',
                      'expr' => 
                      array (
                        'type' => 'array-access',
                        'left' => 
                        array (
                          'type' => 'variable',
                          'value' => 'phrases',
                          'file' => '/app/phalcon/Http/Message/Response.zep',
                          'line' => 247,
                          'char' => 33,
                        ),
                        'right' => 
                        array (
                          'type' => 'variable',
                          'value' => 'code',
                          'file' => '/app/phalcon/Http/Message/Response.zep',
                          'line' => 247,
                          'char' => 38,
                        ),
                        'file' => '/app/phalcon/Http/Message/Response.zep',
                        'line' => 247,
                        'char' => 39,
                      ),
                      'file' => '/app/phalcon/Http/Message/Response.zep',
                      'line' => 247,
                      'char' => 39,
                    ),
                  ),
                  'file' => '/app/phalcon/Http/Message/Response.zep',
                  'line' => 248,
                  'char' => 9,
                ),
              ),
              'file' => '/app/phalcon/Http/Message/Response.zep',
              'line' => 250,
              'char' => 11,
            ),
            7 => 
            array (
              'type' => 'let',
              'assignments' => 
              array (
                0 => 
                array (
                  'assign-type' => 'object-property',
                  'operator' => 'assign',
                  'variable' => 'this',
                  'property' => 'statusCode',
                  'expr' => 
                  array (
                    'type' => 'variable',
                    'value' => 'code',
                    'file' => '/app/phalcon/Http/Message/Response.zep',
                    'line' => 250,
                    'char' => 38,
                  ),
                  'file' => '/app/phalcon/Http/Message/Response.zep',
                  'line' => 250,
                  'char' => 38,
                ),
                1 => 
                array (
                  'assign-type' => 'object-property',
                  'operator' => 'assign',
                  'variable' => 'this',
                  'property' => 'reasonPhrase',
                  'expr' => 
                  array (
                    'type' => 'variable',
                    'value' => 'phrase',
                    'file' => '/app/phalcon/Http/Message/Response.zep',
                    'line' => 251,
                    'char' => 40,
                  ),
                  'file' => '/app/phalcon/Http/Message/Response.zep',
                  'line' => 251,
                  'char' => 40,
                ),
              ),
              'file' => '/app/phalcon/Http/Message/Response.zep',
              'line' => 252,
              'char' => 5,
            ),
          ),
          'docblock' => '**
     * Set a valid status code and phrase
     *
     * @param mixed $code
     * @param mixed $phrase
     *',
          'return-type' => 
          array (
            'type' => 'return-type',
            'void' => 1,
            'file' => '/app/phalcon/Http/Message/Response.zep',
            'line' => 232,
            'char' => 5,
          ),
          'file' => '/app/phalcon/Http/Message/Response.zep',
          'line' => 231,
          'last-line' => 253,
          'char' => 20,
        ),
      ),
      'file' => '/app/phalcon/Http/Message/Response.zep',
      'line' => 25,
      'char' => 11,
    ),
    'file' => '/app/phalcon/Http/Message/Response.zep',
    'line' => 25,
    'char' => 11,
  ),
);