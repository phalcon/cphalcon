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
    'file' => '/app/phalcon/Http/Message/AbstractMessage.zep',
    'line' => 15,
    'char' => 9,
  ),
  1 => 
  array (
    'type' => 'namespace',
    'name' => 'Phalcon\\Http\\Message',
    'file' => '/app/phalcon/Http/Message/AbstractMessage.zep',
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
        'name' => 'Phalcon\\Collection\\Collection',
        'file' => '/app/phalcon/Http/Message/AbstractMessage.zep',
        'line' => 17,
        'char' => 34,
      ),
    ),
    'file' => '/app/phalcon/Http/Message/AbstractMessage.zep',
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
        'name' => 'Phalcon\\Http\\Message\\AbstractCommon',
        'file' => '/app/phalcon/Http/Message/AbstractMessage.zep',
        'line' => 18,
        'char' => 40,
      ),
    ),
    'file' => '/app/phalcon/Http/Message/AbstractMessage.zep',
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
        'file' => '/app/phalcon/Http/Message/AbstractMessage.zep',
        'line' => 19,
        'char' => 60,
      ),
    ),
    'file' => '/app/phalcon/Http/Message/AbstractMessage.zep',
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
        'name' => 'Phalcon\\Http\\Message\\Stream',
        'file' => '/app/phalcon/Http/Message/AbstractMessage.zep',
        'line' => 20,
        'char' => 32,
      ),
    ),
    'file' => '/app/phalcon/Http/Message/AbstractMessage.zep',
    'line' => 21,
    'char' => 3,
  ),
  6 => 
  array (
    'type' => 'use',
    'aliases' => 
    array (
      0 => 
      array (
        'name' => 'Psr\\Http\\Message\\StreamInterface',
        'file' => '/app/phalcon/Http/Message/AbstractMessage.zep',
        'line' => 21,
        'char' => 37,
      ),
    ),
    'file' => '/app/phalcon/Http/Message/AbstractMessage.zep',
    'line' => 22,
    'char' => 3,
  ),
  7 => 
  array (
    'type' => 'use',
    'aliases' => 
    array (
      0 => 
      array (
        'name' => 'Psr\\Http\\Message\\UriInterface',
        'file' => '/app/phalcon/Http/Message/AbstractMessage.zep',
        'line' => 22,
        'char' => 34,
      ),
    ),
    'file' => '/app/phalcon/Http/Message/AbstractMessage.zep',
    'line' => 26,
    'char' => 2,
  ),
  8 => 
  array (
    'type' => 'comment',
    'value' => '**
 * Message methods
 *',
    'file' => '/app/phalcon/Http/Message/AbstractMessage.zep',
    'line' => 27,
    'char' => 8,
  ),
  9 => 
  array (
    'type' => 'class',
    'name' => 'AbstractMessage',
    'abstract' => 1,
    'final' => 0,
    'extends' => 'AbstractCommon',
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
          'name' => 'body',
          'docblock' => '**
     * Gets the body of the message.
     *
     * @var <StreamInterface>
     *',
          'shortcuts' => 
          array (
            0 => 
            array (
              'type' => 'shortcut',
              'name' => 'get',
              'file' => '/app/phalcon/Http/Message/AbstractMessage.zep',
              'line' => 34,
              'char' => 26,
            ),
          ),
          'file' => '/app/phalcon/Http/Message/AbstractMessage.zep',
          'line' => 38,
          'char' => 6,
        ),
        1 => 
        array (
          'visibility' => 
          array (
            0 => 'protected',
          ),
          'type' => 'property',
          'name' => 'headers',
          'docblock' => '**
     * @var <Collection>
     *',
          'file' => '/app/phalcon/Http/Message/AbstractMessage.zep',
          'line' => 50,
          'char' => 6,
        ),
        2 => 
        array (
          'visibility' => 
          array (
            0 => 'protected',
          ),
          'type' => 'property',
          'name' => 'protocolVersion',
          'default' => 
          array (
            'type' => 'string',
            'value' => '1.1',
            'file' => '/app/phalcon/Http/Message/AbstractMessage.zep',
            'line' => 51,
            'char' => 37,
          ),
          'docblock' => '**
     * Retrieves the HTTP protocol version as a string.
     *
     * The string MUST contain only the HTTP version number (e.g., \'1.1\',
     * \'1.0\').
     *
     * @return string HTTP protocol version.
     *
     * @var string
     *',
          'shortcuts' => 
          array (
            0 => 
            array (
              'type' => 'shortcut',
              'name' => 'get',
              'file' => '/app/phalcon/Http/Message/AbstractMessage.zep',
              'line' => 51,
              'char' => 43,
            ),
          ),
          'file' => '/app/phalcon/Http/Message/AbstractMessage.zep',
          'line' => 61,
          'char' => 6,
        ),
        3 => 
        array (
          'visibility' => 
          array (
            0 => 'protected',
          ),
          'type' => 'property',
          'name' => 'uri',
          'docblock' => '**
     * Retrieves the URI instance.
     *
     * This method MUST return a UriInterface instance.
     *
     * @see http://tools.ietf.org/html/rfc3986#section-4.3
     *
     * @var UriInterface
     *',
          'shortcuts' => 
          array (
            0 => 
            array (
              'type' => 'shortcut',
              'name' => 'get',
              'file' => '/app/phalcon/Http/Message/AbstractMessage.zep',
              'line' => 62,
              'char' => 25,
            ),
          ),
          'file' => '/app/phalcon/Http/Message/AbstractMessage.zep',
          'line' => 76,
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
          'name' => 'getHeader',
          'parameters' => 
          array (
            0 => 
            array (
              'type' => 'parameter',
              'name' => 'name',
              'const' => 0,
              'data-type' => 'variable',
              'mandatory' => 0,
              'reference' => 0,
              'file' => '/app/phalcon/Http/Message/AbstractMessage.zep',
              'line' => 77,
              'char' => 39,
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
                  'variable' => 'name',
                  'expr' => 
                  array (
                    'type' => 'cast',
                    'left' => 'string',
                    'right' => 
                    array (
                      'type' => 'variable',
                      'value' => 'name',
                      'file' => '/app/phalcon/Http/Message/AbstractMessage.zep',
                      'line' => 79,
                      'char' => 33,
                    ),
                    'file' => '/app/phalcon/Http/Message/AbstractMessage.zep',
                    'line' => 79,
                    'char' => 33,
                  ),
                  'file' => '/app/phalcon/Http/Message/AbstractMessage.zep',
                  'line' => 79,
                  'char' => 33,
                ),
              ),
              'file' => '/app/phalcon/Http/Message/AbstractMessage.zep',
              'line' => 81,
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
                  'type' => 'property-access',
                  'left' => 
                  array (
                    'type' => 'variable',
                    'value' => 'this',
                    'file' => '/app/phalcon/Http/Message/AbstractMessage.zep',
                    'line' => 81,
                    'char' => 21,
                  ),
                  'right' => 
                  array (
                    'type' => 'variable',
                    'value' => 'headers',
                    'file' => '/app/phalcon/Http/Message/AbstractMessage.zep',
                    'line' => 81,
                    'char' => 30,
                  ),
                  'file' => '/app/phalcon/Http/Message/AbstractMessage.zep',
                  'line' => 81,
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
                      'value' => 'name',
                      'file' => '/app/phalcon/Http/Message/AbstractMessage.zep',
                      'line' => 81,
                      'char' => 39,
                    ),
                    'file' => '/app/phalcon/Http/Message/AbstractMessage.zep',
                    'line' => 81,
                    'char' => 39,
                  ),
                  1 => 
                  array (
                    'parameter' => 
                    array (
                      'type' => 'empty-array',
                      'file' => '/app/phalcon/Http/Message/AbstractMessage.zep',
                      'line' => 81,
                      'char' => 43,
                    ),
                    'file' => '/app/phalcon/Http/Message/AbstractMessage.zep',
                    'line' => 81,
                    'char' => 43,
                  ),
                ),
                'file' => '/app/phalcon/Http/Message/AbstractMessage.zep',
                'line' => 81,
                'char' => 44,
              ),
              'file' => '/app/phalcon/Http/Message/AbstractMessage.zep',
              'line' => 82,
              'char' => 5,
            ),
          ),
          'docblock' => '**
     * Retrieves a message header value by the given case-insensitive name.
     *
     * This method returns an array of all the header values of the given
     * case-insensitive header name.
     *
     * If the header does not appear in the message, this method MUST return an
     * empty array.
     *
     * @param string $name
     *
     * @return array
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
                'file' => '/app/phalcon/Http/Message/AbstractMessage.zep',
                'line' => 78,
                'char' => 5,
              ),
            ),
            'void' => 0,
            'file' => '/app/phalcon/Http/Message/AbstractMessage.zep',
            'line' => 78,
            'char' => 5,
          ),
          'file' => '/app/phalcon/Http/Message/AbstractMessage.zep',
          'line' => 77,
          'last-line' => 101,
          'char' => 19,
        ),
        1 => 
        array (
          'visibility' => 
          array (
            0 => 'public',
          ),
          'type' => 'method',
          'name' => 'getHeaderLine',
          'parameters' => 
          array (
            0 => 
            array (
              'type' => 'parameter',
              'name' => 'name',
              'const' => 0,
              'data-type' => 'variable',
              'mandatory' => 0,
              'reference' => 0,
              'file' => '/app/phalcon/Http/Message/AbstractMessage.zep',
              'line' => 102,
              'char' => 43,
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
                  'variable' => 'header',
                  'file' => '/app/phalcon/Http/Message/AbstractMessage.zep',
                  'line' => 104,
                  'char' => 19,
                ),
              ),
              'file' => '/app/phalcon/Http/Message/AbstractMessage.zep',
              'line' => 106,
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
                  'variable' => 'header',
                  'expr' => 
                  array (
                    'type' => 'mcall',
                    'variable' => 
                    array (
                      'type' => 'variable',
                      'value' => 'this',
                      'file' => '/app/phalcon/Http/Message/AbstractMessage.zep',
                      'line' => 106,
                      'char' => 27,
                    ),
                    'name' => 'getHeader',
                    'call-type' => 1,
                    'parameters' => 
                    array (
                      0 => 
                      array (
                        'parameter' => 
                        array (
                          'type' => 'variable',
                          'value' => 'name',
                          'file' => '/app/phalcon/Http/Message/AbstractMessage.zep',
                          'line' => 106,
                          'char' => 42,
                        ),
                        'file' => '/app/phalcon/Http/Message/AbstractMessage.zep',
                        'line' => 106,
                        'char' => 42,
                      ),
                    ),
                    'file' => '/app/phalcon/Http/Message/AbstractMessage.zep',
                    'line' => 106,
                    'char' => 43,
                  ),
                  'file' => '/app/phalcon/Http/Message/AbstractMessage.zep',
                  'line' => 106,
                  'char' => 43,
                ),
              ),
              'file' => '/app/phalcon/Http/Message/AbstractMessage.zep',
              'line' => 108,
              'char' => 14,
            ),
            2 => 
            array (
              'type' => 'return',
              'expr' => 
              array (
                'type' => 'fcall',
                'name' => 'implode',
                'call-type' => 1,
                'parameters' => 
                array (
                  0 => 
                  array (
                    'parameter' => 
                    array (
                      'type' => 'char',
                      'value' => ',',
                      'file' => '/app/phalcon/Http/Message/AbstractMessage.zep',
                      'line' => 108,
                      'char' => 26,
                    ),
                    'file' => '/app/phalcon/Http/Message/AbstractMessage.zep',
                    'line' => 108,
                    'char' => 26,
                  ),
                  1 => 
                  array (
                    'parameter' => 
                    array (
                      'type' => 'variable',
                      'value' => 'header',
                      'file' => '/app/phalcon/Http/Message/AbstractMessage.zep',
                      'line' => 108,
                      'char' => 34,
                    ),
                    'file' => '/app/phalcon/Http/Message/AbstractMessage.zep',
                    'line' => 108,
                    'char' => 34,
                  ),
                ),
                'file' => '/app/phalcon/Http/Message/AbstractMessage.zep',
                'line' => 108,
                'char' => 35,
              ),
              'file' => '/app/phalcon/Http/Message/AbstractMessage.zep',
              'line' => 109,
              'char' => 5,
            ),
          ),
          'docblock' => '**
     * Retrieves a comma-separated string of the values for a single header.
     *
     * This method returns all of the header values of the given
     * case-insensitive header name as a string concatenated together using
     * a comma.
     *
     * NOTE: Not all header values may be appropriately represented using
     * comma concatenation. For such headers, use getHeader() instead
     * and supply your own delimiter when concatenating.
     *
     * If the header does not appear in the message, this method MUST return
     * an empty string.
     *
     * @param string $name
     *
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
                'file' => '/app/phalcon/Http/Message/AbstractMessage.zep',
                'line' => 103,
                'char' => 5,
              ),
            ),
            'void' => 0,
            'file' => '/app/phalcon/Http/Message/AbstractMessage.zep',
            'line' => 103,
            'char' => 5,
          ),
          'file' => '/app/phalcon/Http/Message/AbstractMessage.zep',
          'line' => 102,
          'last-line' => 133,
          'char' => 19,
        ),
        2 => 
        array (
          'visibility' => 
          array (
            0 => 'public',
          ),
          'type' => 'method',
          'name' => 'getHeaders',
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
                    'file' => '/app/phalcon/Http/Message/AbstractMessage.zep',
                    'line' => 136,
                    'char' => 21,
                  ),
                  'right' => 
                  array (
                    'type' => 'variable',
                    'value' => 'headers',
                    'file' => '/app/phalcon/Http/Message/AbstractMessage.zep',
                    'line' => 136,
                    'char' => 30,
                  ),
                  'file' => '/app/phalcon/Http/Message/AbstractMessage.zep',
                  'line' => 136,
                  'char' => 30,
                ),
                'name' => 'toArray',
                'call-type' => 1,
                'file' => '/app/phalcon/Http/Message/AbstractMessage.zep',
                'line' => 136,
                'char' => 40,
              ),
              'file' => '/app/phalcon/Http/Message/AbstractMessage.zep',
              'line' => 137,
              'char' => 5,
            ),
          ),
          'docblock' => '**
     * Retrieves all message header values.
     *
     * The keys represent the header name as it will be sent over the wire, and
     * each value is an array of strings associated with the header.
     *
     *     // Represent the headers as a string
     *     foreach ($message->getHeaders() as $name => $values) {
     *         echo $name . \': \' . implode(\', \', $values);
     *     }
     *
     *     // Emit headers iteratively:
     *     foreach ($message->getHeaders() as $name => $values) {
     *         foreach ($values as $value) {
     *             header(sprintf(\'%s: %s\', $name, $value), false);
     *         }
     *     }
     *
     * While header names are not case-sensitive, getHeaders() will preserve the
     * exact case in which headers were originally specified.
     *
     * @return array
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
                'file' => '/app/phalcon/Http/Message/AbstractMessage.zep',
                'line' => 135,
                'char' => 5,
              ),
            ),
            'void' => 0,
            'file' => '/app/phalcon/Http/Message/AbstractMessage.zep',
            'line' => 135,
            'char' => 5,
          ),
          'file' => '/app/phalcon/Http/Message/AbstractMessage.zep',
          'line' => 134,
          'last-line' => 145,
          'char' => 19,
        ),
        3 => 
        array (
          'visibility' => 
          array (
            0 => 'public',
          ),
          'type' => 'method',
          'name' => 'hasHeader',
          'parameters' => 
          array (
            0 => 
            array (
              'type' => 'parameter',
              'name' => 'name',
              'const' => 0,
              'data-type' => 'variable',
              'mandatory' => 0,
              'reference' => 0,
              'file' => '/app/phalcon/Http/Message/AbstractMessage.zep',
              'line' => 146,
              'char' => 35,
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
                    'file' => '/app/phalcon/Http/Message/AbstractMessage.zep',
                    'line' => 148,
                    'char' => 21,
                  ),
                  'right' => 
                  array (
                    'type' => 'variable',
                    'value' => 'headers',
                    'file' => '/app/phalcon/Http/Message/AbstractMessage.zep',
                    'line' => 148,
                    'char' => 30,
                  ),
                  'file' => '/app/phalcon/Http/Message/AbstractMessage.zep',
                  'line' => 148,
                  'char' => 30,
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
                      'value' => 'name',
                      'file' => '/app/phalcon/Http/Message/AbstractMessage.zep',
                      'line' => 148,
                      'char' => 39,
                    ),
                    'file' => '/app/phalcon/Http/Message/AbstractMessage.zep',
                    'line' => 148,
                    'char' => 39,
                  ),
                ),
                'file' => '/app/phalcon/Http/Message/AbstractMessage.zep',
                'line' => 148,
                'char' => 40,
              ),
              'file' => '/app/phalcon/Http/Message/AbstractMessage.zep',
              'line' => 149,
              'char' => 5,
            ),
          ),
          'docblock' => '**
     * Checks if a header exists by the given case-insensitive name.
     *
     * @param string $name
     *
     * @return bool
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
                'file' => '/app/phalcon/Http/Message/AbstractMessage.zep',
                'line' => 147,
                'char' => 5,
              ),
            ),
            'void' => 0,
            'file' => '/app/phalcon/Http/Message/AbstractMessage.zep',
            'line' => 147,
            'char' => 5,
          ),
          'file' => '/app/phalcon/Http/Message/AbstractMessage.zep',
          'line' => 146,
          'last-line' => 167,
          'char' => 19,
        ),
        4 => 
        array (
          'visibility' => 
          array (
            0 => 'public',
          ),
          'type' => 'method',
          'name' => 'withAddedHeader',
          'parameters' => 
          array (
            0 => 
            array (
              'type' => 'parameter',
              'name' => 'name',
              'const' => 0,
              'data-type' => 'variable',
              'mandatory' => 0,
              'reference' => 0,
              'file' => '/app/phalcon/Http/Message/AbstractMessage.zep',
              'line' => 168,
              'char' => 45,
            ),
            1 => 
            array (
              'type' => 'parameter',
              'name' => 'value',
              'const' => 0,
              'data-type' => 'variable',
              'mandatory' => 0,
              'reference' => 0,
              'file' => '/app/phalcon/Http/Message/AbstractMessage.zep',
              'line' => 168,
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
                  'variable' => 'existing',
                  'file' => '/app/phalcon/Http/Message/AbstractMessage.zep',
                  'line' => 170,
                  'char' => 21,
                ),
                1 => 
                array (
                  'variable' => 'headers',
                  'file' => '/app/phalcon/Http/Message/AbstractMessage.zep',
                  'line' => 170,
                  'char' => 30,
                ),
              ),
              'file' => '/app/phalcon/Http/Message/AbstractMessage.zep',
              'line' => 172,
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
                  'file' => '/app/phalcon/Http/Message/AbstractMessage.zep',
                  'line' => 172,
                  'char' => 14,
                ),
                'name' => 'checkHeaderName',
                'call-type' => 1,
                'parameters' => 
                array (
                  0 => 
                  array (
                    'parameter' => 
                    array (
                      'type' => 'variable',
                      'value' => 'name',
                      'file' => '/app/phalcon/Http/Message/AbstractMessage.zep',
                      'line' => 172,
                      'char' => 35,
                    ),
                    'file' => '/app/phalcon/Http/Message/AbstractMessage.zep',
                    'line' => 172,
                    'char' => 35,
                  ),
                ),
                'file' => '/app/phalcon/Http/Message/AbstractMessage.zep',
                'line' => 172,
                'char' => 36,
              ),
              'file' => '/app/phalcon/Http/Message/AbstractMessage.zep',
              'line' => 174,
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
                  'variable' => 'headers',
                  'expr' => 
                  array (
                    'type' => 'clone',
                    'left' => 
                    array (
                      'type' => 'property-access',
                      'left' => 
                      array (
                        'type' => 'variable',
                        'value' => 'this',
                        'file' => '/app/phalcon/Http/Message/AbstractMessage.zep',
                        'line' => 174,
                        'char' => 35,
                      ),
                      'right' => 
                      array (
                        'type' => 'variable',
                        'value' => 'headers',
                        'file' => '/app/phalcon/Http/Message/AbstractMessage.zep',
                        'line' => 174,
                        'char' => 43,
                      ),
                      'file' => '/app/phalcon/Http/Message/AbstractMessage.zep',
                      'line' => 174,
                      'char' => 43,
                    ),
                    'file' => '/app/phalcon/Http/Message/AbstractMessage.zep',
                    'line' => 174,
                    'char' => 43,
                  ),
                  'file' => '/app/phalcon/Http/Message/AbstractMessage.zep',
                  'line' => 174,
                  'char' => 43,
                ),
                1 => 
                array (
                  'assign-type' => 'variable',
                  'operator' => 'assign',
                  'variable' => 'existing',
                  'expr' => 
                  array (
                    'type' => 'mcall',
                    'variable' => 
                    array (
                      'type' => 'variable',
                      'value' => 'headers',
                      'file' => '/app/phalcon/Http/Message/AbstractMessage.zep',
                      'line' => 175,
                      'char' => 32,
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
                          'value' => 'name',
                          'file' => '/app/phalcon/Http/Message/AbstractMessage.zep',
                          'line' => 175,
                          'char' => 41,
                        ),
                        'file' => '/app/phalcon/Http/Message/AbstractMessage.zep',
                        'line' => 175,
                        'char' => 41,
                      ),
                      1 => 
                      array (
                        'parameter' => 
                        array (
                          'type' => 'empty-array',
                          'file' => '/app/phalcon/Http/Message/AbstractMessage.zep',
                          'line' => 175,
                          'char' => 45,
                        ),
                        'file' => '/app/phalcon/Http/Message/AbstractMessage.zep',
                        'line' => 175,
                        'char' => 45,
                      ),
                    ),
                    'file' => '/app/phalcon/Http/Message/AbstractMessage.zep',
                    'line' => 175,
                    'char' => 46,
                  ),
                  'file' => '/app/phalcon/Http/Message/AbstractMessage.zep',
                  'line' => 175,
                  'char' => 46,
                ),
                2 => 
                array (
                  'assign-type' => 'variable',
                  'operator' => 'assign',
                  'variable' => 'value',
                  'expr' => 
                  array (
                    'type' => 'mcall',
                    'variable' => 
                    array (
                      'type' => 'variable',
                      'value' => 'this',
                      'file' => '/app/phalcon/Http/Message/AbstractMessage.zep',
                      'line' => 176,
                      'char' => 29,
                    ),
                    'name' => 'getHeaderValue',
                    'call-type' => 1,
                    'parameters' => 
                    array (
                      0 => 
                      array (
                        'parameter' => 
                        array (
                          'type' => 'variable',
                          'value' => 'value',
                          'file' => '/app/phalcon/Http/Message/AbstractMessage.zep',
                          'line' => 176,
                          'char' => 50,
                        ),
                        'file' => '/app/phalcon/Http/Message/AbstractMessage.zep',
                        'line' => 176,
                        'char' => 50,
                      ),
                    ),
                    'file' => '/app/phalcon/Http/Message/AbstractMessage.zep',
                    'line' => 176,
                    'char' => 51,
                  ),
                  'file' => '/app/phalcon/Http/Message/AbstractMessage.zep',
                  'line' => 176,
                  'char' => 51,
                ),
                3 => 
                array (
                  'assign-type' => 'variable',
                  'operator' => 'assign',
                  'variable' => 'value',
                  'expr' => 
                  array (
                    'type' => 'fcall',
                    'name' => 'array_merge',
                    'call-type' => 1,
                    'parameters' => 
                    array (
                      0 => 
                      array (
                        'parameter' => 
                        array (
                          'type' => 'variable',
                          'value' => 'existing',
                          'file' => '/app/phalcon/Http/Message/AbstractMessage.zep',
                          'line' => 177,
                          'char' => 44,
                        ),
                        'file' => '/app/phalcon/Http/Message/AbstractMessage.zep',
                        'line' => 177,
                        'char' => 44,
                      ),
                      1 => 
                      array (
                        'parameter' => 
                        array (
                          'type' => 'variable',
                          'value' => 'value',
                          'file' => '/app/phalcon/Http/Message/AbstractMessage.zep',
                          'line' => 177,
                          'char' => 51,
                        ),
                        'file' => '/app/phalcon/Http/Message/AbstractMessage.zep',
                        'line' => 177,
                        'char' => 51,
                      ),
                    ),
                    'file' => '/app/phalcon/Http/Message/AbstractMessage.zep',
                    'line' => 177,
                    'char' => 52,
                  ),
                  'file' => '/app/phalcon/Http/Message/AbstractMessage.zep',
                  'line' => 177,
                  'char' => 52,
                ),
              ),
              'file' => '/app/phalcon/Http/Message/AbstractMessage.zep',
              'line' => 179,
              'char' => 15,
            ),
            3 => 
            array (
              'type' => 'mcall',
              'expr' => 
              array (
                'type' => 'mcall',
                'variable' => 
                array (
                  'type' => 'variable',
                  'value' => 'headers',
                  'file' => '/app/phalcon/Http/Message/AbstractMessage.zep',
                  'line' => 179,
                  'char' => 17,
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
                      'value' => 'name',
                      'file' => '/app/phalcon/Http/Message/AbstractMessage.zep',
                      'line' => 179,
                      'char' => 26,
                    ),
                    'file' => '/app/phalcon/Http/Message/AbstractMessage.zep',
                    'line' => 179,
                    'char' => 26,
                  ),
                  1 => 
                  array (
                    'parameter' => 
                    array (
                      'type' => 'variable',
                      'value' => 'value',
                      'file' => '/app/phalcon/Http/Message/AbstractMessage.zep',
                      'line' => 179,
                      'char' => 33,
                    ),
                    'file' => '/app/phalcon/Http/Message/AbstractMessage.zep',
                    'line' => 179,
                    'char' => 33,
                  ),
                ),
                'file' => '/app/phalcon/Http/Message/AbstractMessage.zep',
                'line' => 179,
                'char' => 34,
              ),
              'file' => '/app/phalcon/Http/Message/AbstractMessage.zep',
              'line' => 181,
              'char' => 14,
            ),
            4 => 
            array (
              'type' => 'return',
              'expr' => 
              array (
                'type' => 'mcall',
                'variable' => 
                array (
                  'type' => 'variable',
                  'value' => 'this',
                  'file' => '/app/phalcon/Http/Message/AbstractMessage.zep',
                  'line' => 181,
                  'char' => 21,
                ),
                'name' => 'cloneInstance',
                'call-type' => 1,
                'parameters' => 
                array (
                  0 => 
                  array (
                    'parameter' => 
                    array (
                      'type' => 'variable',
                      'value' => 'headers',
                      'file' => '/app/phalcon/Http/Message/AbstractMessage.zep',
                      'line' => 181,
                      'char' => 43,
                    ),
                    'file' => '/app/phalcon/Http/Message/AbstractMessage.zep',
                    'line' => 181,
                    'char' => 43,
                  ),
                  1 => 
                  array (
                    'parameter' => 
                    array (
                      'type' => 'string',
                      'value' => 'headers',
                      'file' => '/app/phalcon/Http/Message/AbstractMessage.zep',
                      'line' => 181,
                      'char' => 52,
                    ),
                    'file' => '/app/phalcon/Http/Message/AbstractMessage.zep',
                    'line' => 181,
                    'char' => 52,
                  ),
                ),
                'file' => '/app/phalcon/Http/Message/AbstractMessage.zep',
                'line' => 181,
                'char' => 53,
              ),
              'file' => '/app/phalcon/Http/Message/AbstractMessage.zep',
              'line' => 182,
              'char' => 5,
            ),
          ),
          'docblock' => '**
     * Return an instance with the specified header appended with the given
     * value.
     *
     * Existing values for the specified header will be maintained. The new
     * value(s) will be appended to the existing list. If the header did not
     * exist previously, it will be added.
     *
     * This method MUST be implemented in such a way as to retain the
     * immutability of the message, and MUST return an instance that has the
     * new header and/or value.
     *
     * @param string          $name
     * @param string|string[] $value
     *
     * @return self
     *',
          'return-type' => 
          array (
            'type' => 'return-type',
            'list' => 
            array (
              0 => 
              array (
                'type' => 'return-type-parameter',
                'data-type' => 'object',
                'mandatory' => 0,
                'file' => '/app/phalcon/Http/Message/AbstractMessage.zep',
                'line' => 169,
                'char' => 5,
              ),
            ),
            'void' => 0,
            'file' => '/app/phalcon/Http/Message/AbstractMessage.zep',
            'line' => 169,
            'char' => 5,
          ),
          'file' => '/app/phalcon/Http/Message/AbstractMessage.zep',
          'line' => 168,
          'last-line' => 198,
          'char' => 19,
        ),
        5 => 
        array (
          'visibility' => 
          array (
            0 => 'public',
          ),
          'type' => 'method',
          'name' => 'withBody',
          'parameters' => 
          array (
            0 => 
            array (
              'type' => 'parameter',
              'name' => 'body',
              'const' => 0,
              'data-type' => 'variable',
              'mandatory' => 0,
              'cast' => 
              array (
                'type' => 'variable',
                'value' => 'StreamInterface',
                'file' => '/app/phalcon/Http/Message/AbstractMessage.zep',
                'line' => 199,
                'char' => 51,
              ),
              'reference' => 0,
              'file' => '/app/phalcon/Http/Message/AbstractMessage.zep',
              'line' => 199,
              'char' => 52,
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
                  'variable' => 'newBody',
                  'file' => '/app/phalcon/Http/Message/AbstractMessage.zep',
                  'line' => 201,
                  'char' => 20,
                ),
              ),
              'file' => '/app/phalcon/Http/Message/AbstractMessage.zep',
              'line' => 203,
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
                  'variable' => 'newBody',
                  'expr' => 
                  array (
                    'type' => 'mcall',
                    'variable' => 
                    array (
                      'type' => 'variable',
                      'value' => 'this',
                      'file' => '/app/phalcon/Http/Message/AbstractMessage.zep',
                      'line' => 203,
                      'char' => 28,
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
                          'file' => '/app/phalcon/Http/Message/AbstractMessage.zep',
                          'line' => 203,
                          'char' => 45,
                        ),
                        'file' => '/app/phalcon/Http/Message/AbstractMessage.zep',
                        'line' => 203,
                        'char' => 45,
                      ),
                      1 => 
                      array (
                        'parameter' => 
                        array (
                          'type' => 'string',
                          'value' => 'w+b',
                          'file' => '/app/phalcon/Http/Message/AbstractMessage.zep',
                          'line' => 203,
                          'char' => 50,
                        ),
                        'file' => '/app/phalcon/Http/Message/AbstractMessage.zep',
                        'line' => 203,
                        'char' => 50,
                      ),
                    ),
                    'file' => '/app/phalcon/Http/Message/AbstractMessage.zep',
                    'line' => 203,
                    'char' => 51,
                  ),
                  'file' => '/app/phalcon/Http/Message/AbstractMessage.zep',
                  'line' => 203,
                  'char' => 51,
                ),
              ),
              'file' => '/app/phalcon/Http/Message/AbstractMessage.zep',
              'line' => 205,
              'char' => 14,
            ),
            2 => 
            array (
              'type' => 'return',
              'expr' => 
              array (
                'type' => 'mcall',
                'variable' => 
                array (
                  'type' => 'variable',
                  'value' => 'this',
                  'file' => '/app/phalcon/Http/Message/AbstractMessage.zep',
                  'line' => 205,
                  'char' => 21,
                ),
                'name' => 'cloneInstance',
                'call-type' => 1,
                'parameters' => 
                array (
                  0 => 
                  array (
                    'parameter' => 
                    array (
                      'type' => 'variable',
                      'value' => 'newBody',
                      'file' => '/app/phalcon/Http/Message/AbstractMessage.zep',
                      'line' => 205,
                      'char' => 43,
                    ),
                    'file' => '/app/phalcon/Http/Message/AbstractMessage.zep',
                    'line' => 205,
                    'char' => 43,
                  ),
                  1 => 
                  array (
                    'parameter' => 
                    array (
                      'type' => 'string',
                      'value' => 'body',
                      'file' => '/app/phalcon/Http/Message/AbstractMessage.zep',
                      'line' => 205,
                      'char' => 49,
                    ),
                    'file' => '/app/phalcon/Http/Message/AbstractMessage.zep',
                    'line' => 205,
                    'char' => 49,
                  ),
                ),
                'file' => '/app/phalcon/Http/Message/AbstractMessage.zep',
                'line' => 205,
                'char' => 50,
              ),
              'file' => '/app/phalcon/Http/Message/AbstractMessage.zep',
              'line' => 206,
              'char' => 5,
            ),
          ),
          'docblock' => '**
     * Return an instance with the specified message body.
     *
     * The body MUST be a StreamInterface object.
     *
     * This method MUST be implemented in such a way as to retain the
     * immutability of the message, and MUST return a new instance that has the
     * new body stream.
     *
     * @param StreamInterface $body
     *
     * @return self
     * @throws InvalidArgumentException When the body is not valid.
     *
     *',
          'return-type' => 
          array (
            'type' => 'return-type',
            'list' => 
            array (
              0 => 
              array (
                'type' => 'return-type-parameter',
                'data-type' => 'object',
                'mandatory' => 0,
                'file' => '/app/phalcon/Http/Message/AbstractMessage.zep',
                'line' => 200,
                'char' => 5,
              ),
            ),
            'void' => 0,
            'file' => '/app/phalcon/Http/Message/AbstractMessage.zep',
            'line' => 200,
            'char' => 5,
          ),
          'file' => '/app/phalcon/Http/Message/AbstractMessage.zep',
          'line' => 199,
          'last-line' => 225,
          'char' => 19,
        ),
        6 => 
        array (
          'visibility' => 
          array (
            0 => 'public',
          ),
          'type' => 'method',
          'name' => 'withHeader',
          'parameters' => 
          array (
            0 => 
            array (
              'type' => 'parameter',
              'name' => 'name',
              'const' => 0,
              'data-type' => 'variable',
              'mandatory' => 0,
              'reference' => 0,
              'file' => '/app/phalcon/Http/Message/AbstractMessage.zep',
              'line' => 226,
              'char' => 40,
            ),
            1 => 
            array (
              'type' => 'parameter',
              'name' => 'value',
              'const' => 0,
              'data-type' => 'variable',
              'mandatory' => 0,
              'reference' => 0,
              'file' => '/app/phalcon/Http/Message/AbstractMessage.zep',
              'line' => 226,
              'char' => 51,
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
                  'variable' => 'headers',
                  'file' => '/app/phalcon/Http/Message/AbstractMessage.zep',
                  'line' => 228,
                  'char' => 20,
                ),
              ),
              'file' => '/app/phalcon/Http/Message/AbstractMessage.zep',
              'line' => 230,
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
                  'file' => '/app/phalcon/Http/Message/AbstractMessage.zep',
                  'line' => 230,
                  'char' => 14,
                ),
                'name' => 'checkHeaderName',
                'call-type' => 1,
                'parameters' => 
                array (
                  0 => 
                  array (
                    'parameter' => 
                    array (
                      'type' => 'variable',
                      'value' => 'name',
                      'file' => '/app/phalcon/Http/Message/AbstractMessage.zep',
                      'line' => 230,
                      'char' => 35,
                    ),
                    'file' => '/app/phalcon/Http/Message/AbstractMessage.zep',
                    'line' => 230,
                    'char' => 35,
                  ),
                ),
                'file' => '/app/phalcon/Http/Message/AbstractMessage.zep',
                'line' => 230,
                'char' => 36,
              ),
              'file' => '/app/phalcon/Http/Message/AbstractMessage.zep',
              'line' => 232,
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
                  'variable' => 'headers',
                  'expr' => 
                  array (
                    'type' => 'clone',
                    'left' => 
                    array (
                      'type' => 'property-access',
                      'left' => 
                      array (
                        'type' => 'variable',
                        'value' => 'this',
                        'file' => '/app/phalcon/Http/Message/AbstractMessage.zep',
                        'line' => 232,
                        'char' => 34,
                      ),
                      'right' => 
                      array (
                        'type' => 'variable',
                        'value' => 'headers',
                        'file' => '/app/phalcon/Http/Message/AbstractMessage.zep',
                        'line' => 232,
                        'char' => 42,
                      ),
                      'file' => '/app/phalcon/Http/Message/AbstractMessage.zep',
                      'line' => 232,
                      'char' => 42,
                    ),
                    'file' => '/app/phalcon/Http/Message/AbstractMessage.zep',
                    'line' => 232,
                    'char' => 42,
                  ),
                  'file' => '/app/phalcon/Http/Message/AbstractMessage.zep',
                  'line' => 232,
                  'char' => 42,
                ),
                1 => 
                array (
                  'assign-type' => 'variable',
                  'operator' => 'assign',
                  'variable' => 'value',
                  'expr' => 
                  array (
                    'type' => 'mcall',
                    'variable' => 
                    array (
                      'type' => 'variable',
                      'value' => 'this',
                      'file' => '/app/phalcon/Http/Message/AbstractMessage.zep',
                      'line' => 233,
                      'char' => 28,
                    ),
                    'name' => 'getHeaderValue',
                    'call-type' => 1,
                    'parameters' => 
                    array (
                      0 => 
                      array (
                        'parameter' => 
                        array (
                          'type' => 'variable',
                          'value' => 'value',
                          'file' => '/app/phalcon/Http/Message/AbstractMessage.zep',
                          'line' => 233,
                          'char' => 49,
                        ),
                        'file' => '/app/phalcon/Http/Message/AbstractMessage.zep',
                        'line' => 233,
                        'char' => 49,
                      ),
                    ),
                    'file' => '/app/phalcon/Http/Message/AbstractMessage.zep',
                    'line' => 233,
                    'char' => 50,
                  ),
                  'file' => '/app/phalcon/Http/Message/AbstractMessage.zep',
                  'line' => 233,
                  'char' => 50,
                ),
              ),
              'file' => '/app/phalcon/Http/Message/AbstractMessage.zep',
              'line' => 235,
              'char' => 15,
            ),
            3 => 
            array (
              'type' => 'mcall',
              'expr' => 
              array (
                'type' => 'mcall',
                'variable' => 
                array (
                  'type' => 'variable',
                  'value' => 'headers',
                  'file' => '/app/phalcon/Http/Message/AbstractMessage.zep',
                  'line' => 235,
                  'char' => 17,
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
                      'value' => 'name',
                      'file' => '/app/phalcon/Http/Message/AbstractMessage.zep',
                      'line' => 235,
                      'char' => 26,
                    ),
                    'file' => '/app/phalcon/Http/Message/AbstractMessage.zep',
                    'line' => 235,
                    'char' => 26,
                  ),
                  1 => 
                  array (
                    'parameter' => 
                    array (
                      'type' => 'variable',
                      'value' => 'value',
                      'file' => '/app/phalcon/Http/Message/AbstractMessage.zep',
                      'line' => 235,
                      'char' => 33,
                    ),
                    'file' => '/app/phalcon/Http/Message/AbstractMessage.zep',
                    'line' => 235,
                    'char' => 33,
                  ),
                ),
                'file' => '/app/phalcon/Http/Message/AbstractMessage.zep',
                'line' => 235,
                'char' => 34,
              ),
              'file' => '/app/phalcon/Http/Message/AbstractMessage.zep',
              'line' => 237,
              'char' => 14,
            ),
            4 => 
            array (
              'type' => 'return',
              'expr' => 
              array (
                'type' => 'mcall',
                'variable' => 
                array (
                  'type' => 'variable',
                  'value' => 'this',
                  'file' => '/app/phalcon/Http/Message/AbstractMessage.zep',
                  'line' => 237,
                  'char' => 21,
                ),
                'name' => 'cloneInstance',
                'call-type' => 1,
                'parameters' => 
                array (
                  0 => 
                  array (
                    'parameter' => 
                    array (
                      'type' => 'variable',
                      'value' => 'headers',
                      'file' => '/app/phalcon/Http/Message/AbstractMessage.zep',
                      'line' => 237,
                      'char' => 43,
                    ),
                    'file' => '/app/phalcon/Http/Message/AbstractMessage.zep',
                    'line' => 237,
                    'char' => 43,
                  ),
                  1 => 
                  array (
                    'parameter' => 
                    array (
                      'type' => 'string',
                      'value' => 'headers',
                      'file' => '/app/phalcon/Http/Message/AbstractMessage.zep',
                      'line' => 237,
                      'char' => 52,
                    ),
                    'file' => '/app/phalcon/Http/Message/AbstractMessage.zep',
                    'line' => 237,
                    'char' => 52,
                  ),
                ),
                'file' => '/app/phalcon/Http/Message/AbstractMessage.zep',
                'line' => 237,
                'char' => 53,
              ),
              'file' => '/app/phalcon/Http/Message/AbstractMessage.zep',
              'line' => 238,
              'char' => 5,
            ),
          ),
          'docblock' => '**
     * Return an instance with the provided value replacing the specified
     * header.
     *
     * While header names are case-insensitive, the casing of the header will
     * be preserved by this function, and returned from getHeaders().
     *
     * This method MUST be implemented in such a way as to retain the
     * immutability of the message, and MUST return an instance that has the
     * new and/or updated header and value.
     *
     * @param string          $name
     * @param string|string[] $value
     *
     * @return self
     * @throws InvalidArgumentException for invalid header names or values.
     *
     *',
          'return-type' => 
          array (
            'type' => 'return-type',
            'list' => 
            array (
              0 => 
              array (
                'type' => 'return-type-parameter',
                'data-type' => 'object',
                'mandatory' => 0,
                'file' => '/app/phalcon/Http/Message/AbstractMessage.zep',
                'line' => 227,
                'char' => 5,
              ),
            ),
            'void' => 0,
            'file' => '/app/phalcon/Http/Message/AbstractMessage.zep',
            'line' => 227,
            'char' => 5,
          ),
          'file' => '/app/phalcon/Http/Message/AbstractMessage.zep',
          'line' => 226,
          'last-line' => 253,
          'char' => 19,
        ),
        7 => 
        array (
          'visibility' => 
          array (
            0 => 'public',
          ),
          'type' => 'method',
          'name' => 'withProtocolVersion',
          'parameters' => 
          array (
            0 => 
            array (
              'type' => 'parameter',
              'name' => 'version',
              'const' => 0,
              'data-type' => 'variable',
              'mandatory' => 0,
              'reference' => 0,
              'file' => '/app/phalcon/Http/Message/AbstractMessage.zep',
              'line' => 254,
              'char' => 52,
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
                  'file' => '/app/phalcon/Http/Message/AbstractMessage.zep',
                  'line' => 256,
                  'char' => 14,
                ),
                'name' => 'processProtocol',
                'call-type' => 1,
                'parameters' => 
                array (
                  0 => 
                  array (
                    'parameter' => 
                    array (
                      'type' => 'variable',
                      'value' => 'version',
                      'file' => '/app/phalcon/Http/Message/AbstractMessage.zep',
                      'line' => 256,
                      'char' => 38,
                    ),
                    'file' => '/app/phalcon/Http/Message/AbstractMessage.zep',
                    'line' => 256,
                    'char' => 38,
                  ),
                ),
                'file' => '/app/phalcon/Http/Message/AbstractMessage.zep',
                'line' => 256,
                'char' => 39,
              ),
              'file' => '/app/phalcon/Http/Message/AbstractMessage.zep',
              'line' => 258,
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
                  'file' => '/app/phalcon/Http/Message/AbstractMessage.zep',
                  'line' => 258,
                  'char' => 21,
                ),
                'name' => 'cloneInstance',
                'call-type' => 1,
                'parameters' => 
                array (
                  0 => 
                  array (
                    'parameter' => 
                    array (
                      'type' => 'variable',
                      'value' => 'version',
                      'file' => '/app/phalcon/Http/Message/AbstractMessage.zep',
                      'line' => 258,
                      'char' => 43,
                    ),
                    'file' => '/app/phalcon/Http/Message/AbstractMessage.zep',
                    'line' => 258,
                    'char' => 43,
                  ),
                  1 => 
                  array (
                    'parameter' => 
                    array (
                      'type' => 'string',
                      'value' => 'protocolVersion',
                      'file' => '/app/phalcon/Http/Message/AbstractMessage.zep',
                      'line' => 258,
                      'char' => 60,
                    ),
                    'file' => '/app/phalcon/Http/Message/AbstractMessage.zep',
                    'line' => 258,
                    'char' => 60,
                  ),
                ),
                'file' => '/app/phalcon/Http/Message/AbstractMessage.zep',
                'line' => 258,
                'char' => 61,
              ),
              'file' => '/app/phalcon/Http/Message/AbstractMessage.zep',
              'line' => 259,
              'char' => 5,
            ),
          ),
          'docblock' => '**
     * Return an instance with the specified HTTP protocol version.
     *
     * The version string MUST contain only the HTTP version number (e.g.,
     * \'1.1\', \'1.0\').
     *
     * This method MUST be implemented in such a way as to retain the
     * immutability of the message, and MUST return an instance that has the
     * new protocol version.
     *
     * @param string $version
     *
     * @return self
     *',
          'return-type' => 
          array (
            'type' => 'return-type',
            'list' => 
            array (
              0 => 
              array (
                'type' => 'return-type-parameter',
                'data-type' => 'object',
                'mandatory' => 0,
                'file' => '/app/phalcon/Http/Message/AbstractMessage.zep',
                'line' => 255,
                'char' => 5,
              ),
            ),
            'void' => 0,
            'file' => '/app/phalcon/Http/Message/AbstractMessage.zep',
            'line' => 255,
            'char' => 5,
          ),
          'file' => '/app/phalcon/Http/Message/AbstractMessage.zep',
          'line' => 254,
          'last-line' => 273,
          'char' => 19,
        ),
        8 => 
        array (
          'visibility' => 
          array (
            0 => 'public',
          ),
          'type' => 'method',
          'name' => 'withoutHeader',
          'parameters' => 
          array (
            0 => 
            array (
              'type' => 'parameter',
              'name' => 'name',
              'const' => 0,
              'data-type' => 'variable',
              'mandatory' => 0,
              'reference' => 0,
              'file' => '/app/phalcon/Http/Message/AbstractMessage.zep',
              'line' => 274,
              'char' => 43,
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
                  'variable' => 'headers',
                  'file' => '/app/phalcon/Http/Message/AbstractMessage.zep',
                  'line' => 276,
                  'char' => 20,
                ),
              ),
              'file' => '/app/phalcon/Http/Message/AbstractMessage.zep',
              'line' => 278,
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
                  'variable' => 'headers',
                  'expr' => 
                  array (
                    'type' => 'clone',
                    'left' => 
                    array (
                      'type' => 'property-access',
                      'left' => 
                      array (
                        'type' => 'variable',
                        'value' => 'this',
                        'file' => '/app/phalcon/Http/Message/AbstractMessage.zep',
                        'line' => 278,
                        'char' => 34,
                      ),
                      'right' => 
                      array (
                        'type' => 'variable',
                        'value' => 'headers',
                        'file' => '/app/phalcon/Http/Message/AbstractMessage.zep',
                        'line' => 278,
                        'char' => 42,
                      ),
                      'file' => '/app/phalcon/Http/Message/AbstractMessage.zep',
                      'line' => 278,
                      'char' => 42,
                    ),
                    'file' => '/app/phalcon/Http/Message/AbstractMessage.zep',
                    'line' => 278,
                    'char' => 42,
                  ),
                  'file' => '/app/phalcon/Http/Message/AbstractMessage.zep',
                  'line' => 278,
                  'char' => 42,
                ),
              ),
              'file' => '/app/phalcon/Http/Message/AbstractMessage.zep',
              'line' => 280,
              'char' => 15,
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
                  'value' => 'headers',
                  'file' => '/app/phalcon/Http/Message/AbstractMessage.zep',
                  'line' => 280,
                  'char' => 17,
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
                      'value' => 'name',
                      'file' => '/app/phalcon/Http/Message/AbstractMessage.zep',
                      'line' => 280,
                      'char' => 29,
                    ),
                    'file' => '/app/phalcon/Http/Message/AbstractMessage.zep',
                    'line' => 280,
                    'char' => 29,
                  ),
                ),
                'file' => '/app/phalcon/Http/Message/AbstractMessage.zep',
                'line' => 280,
                'char' => 30,
              ),
              'file' => '/app/phalcon/Http/Message/AbstractMessage.zep',
              'line' => 282,
              'char' => 14,
            ),
            3 => 
            array (
              'type' => 'return',
              'expr' => 
              array (
                'type' => 'mcall',
                'variable' => 
                array (
                  'type' => 'variable',
                  'value' => 'this',
                  'file' => '/app/phalcon/Http/Message/AbstractMessage.zep',
                  'line' => 282,
                  'char' => 21,
                ),
                'name' => 'cloneInstance',
                'call-type' => 1,
                'parameters' => 
                array (
                  0 => 
                  array (
                    'parameter' => 
                    array (
                      'type' => 'variable',
                      'value' => 'headers',
                      'file' => '/app/phalcon/Http/Message/AbstractMessage.zep',
                      'line' => 282,
                      'char' => 43,
                    ),
                    'file' => '/app/phalcon/Http/Message/AbstractMessage.zep',
                    'line' => 282,
                    'char' => 43,
                  ),
                  1 => 
                  array (
                    'parameter' => 
                    array (
                      'type' => 'string',
                      'value' => 'headers',
                      'file' => '/app/phalcon/Http/Message/AbstractMessage.zep',
                      'line' => 282,
                      'char' => 52,
                    ),
                    'file' => '/app/phalcon/Http/Message/AbstractMessage.zep',
                    'line' => 282,
                    'char' => 52,
                  ),
                ),
                'file' => '/app/phalcon/Http/Message/AbstractMessage.zep',
                'line' => 282,
                'char' => 53,
              ),
              'file' => '/app/phalcon/Http/Message/AbstractMessage.zep',
              'line' => 283,
              'char' => 5,
            ),
          ),
          'docblock' => '**
     * Return an instance without the specified header.
     *
     * Header resolution MUST be done without case-sensitivity.
     *
     * This method MUST be implemented in such a way as to retain the
     * immutability of the message, and MUST return an instance that removes
     * the named header.
     *
     * @param string $name
     *
     * @return self
     *',
          'return-type' => 
          array (
            'type' => 'return-type',
            'list' => 
            array (
              0 => 
              array (
                'type' => 'return-type-parameter',
                'data-type' => 'object',
                'mandatory' => 0,
                'file' => '/app/phalcon/Http/Message/AbstractMessage.zep',
                'line' => 275,
                'char' => 5,
              ),
            ),
            'void' => 0,
            'file' => '/app/phalcon/Http/Message/AbstractMessage.zep',
            'line' => 275,
            'char' => 5,
          ),
          'file' => '/app/phalcon/Http/Message/AbstractMessage.zep',
          'line' => 274,
          'last-line' => 293,
          'char' => 19,
        ),
        9 => 
        array (
          'visibility' => 
          array (
            0 => 'final',
            1 => 'protected',
          ),
          'type' => 'method',
          'name' => 'checkHeaderHost',
          'parameters' => 
          array (
            0 => 
            array (
              'type' => 'parameter',
              'name' => 'collection',
              'const' => 0,
              'data-type' => 'variable',
              'mandatory' => 0,
              'cast' => 
              array (
                'type' => 'variable',
                'value' => 'Collection',
                'file' => '/app/phalcon/Http/Message/AbstractMessage.zep',
                'line' => 294,
                'char' => 68,
              ),
              'reference' => 0,
              'file' => '/app/phalcon/Http/Message/AbstractMessage.zep',
              'line' => 294,
              'char' => 69,
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
                  'file' => '/app/phalcon/Http/Message/AbstractMessage.zep',
                  'line' => 296,
                  'char' => 17,
                ),
                1 => 
                array (
                  'variable' => 'host',
                  'file' => '/app/phalcon/Http/Message/AbstractMessage.zep',
                  'line' => 296,
                  'char' => 23,
                ),
                2 => 
                array (
                  'variable' => 'hostArray',
                  'file' => '/app/phalcon/Http/Message/AbstractMessage.zep',
                  'line' => 296,
                  'char' => 34,
                ),
              ),
              'file' => '/app/phalcon/Http/Message/AbstractMessage.zep',
              'line' => 297,
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
                  'variable' => 'header',
                  'file' => '/app/phalcon/Http/Message/AbstractMessage.zep',
                  'line' => 297,
                  'char' => 21,
                ),
              ),
              'file' => '/app/phalcon/Http/Message/AbstractMessage.zep',
              'line' => 299,
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
                        'type' => 'mcall',
                        'variable' => 
                        array (
                          'type' => 'variable',
                          'value' => 'collection',
                          'file' => '/app/phalcon/Http/Message/AbstractMessage.zep',
                          'line' => 299,
                          'char' => 33,
                        ),
                        'name' => 'has',
                        'call-type' => 1,
                        'parameters' => 
                        array (
                          0 => 
                          array (
                            'parameter' => 
                            array (
                              'type' => 'string',
                              'value' => 'host',
                              'file' => '/app/phalcon/Http/Message/AbstractMessage.zep',
                              'line' => 299,
                              'char' => 42,
                            ),
                            'file' => '/app/phalcon/Http/Message/AbstractMessage.zep',
                            'line' => 299,
                            'char' => 42,
                          ),
                        ),
                        'file' => '/app/phalcon/Http/Message/AbstractMessage.zep',
                        'line' => 299,
                        'char' => 45,
                      ),
                      'right' => 
                      array (
                        'type' => 'not',
                        'left' => 
                        array (
                          'type' => 'empty',
                          'left' => 
                          array (
                            'type' => 'list',
                            'left' => 
                            array (
                              'type' => 'property-access',
                              'left' => 
                              array (
                                'type' => 'variable',
                                'value' => 'this',
                                'file' => '/app/phalcon/Http/Message/AbstractMessage.zep',
                                'line' => 300,
                                'char' => 25,
                              ),
                              'right' => 
                              array (
                                'type' => 'variable',
                                'value' => 'uri',
                                'file' => '/app/phalcon/Http/Message/AbstractMessage.zep',
                                'line' => 300,
                                'char' => 29,
                              ),
                              'file' => '/app/phalcon/Http/Message/AbstractMessage.zep',
                              'line' => 300,
                              'char' => 29,
                            ),
                            'file' => '/app/phalcon/Http/Message/AbstractMessage.zep',
                            'line' => 300,
                            'char' => 32,
                          ),
                          'file' => '/app/phalcon/Http/Message/AbstractMessage.zep',
                          'line' => 300,
                          'char' => 32,
                        ),
                        'file' => '/app/phalcon/Http/Message/AbstractMessage.zep',
                        'line' => 300,
                        'char' => 32,
                      ),
                      'file' => '/app/phalcon/Http/Message/AbstractMessage.zep',
                      'line' => 300,
                      'char' => 32,
                    ),
                    'right' => 
                    array (
                      'type' => 'not-identical',
                      'left' => 
                      array (
                        'type' => 'string',
                        'value' => '',
                        'file' => '/app/phalcon/Http/Message/AbstractMessage.zep',
                        'line' => 301,
                        'char' => 16,
                      ),
                      'right' => 
                      array (
                        'type' => 'mcall',
                        'variable' => 
                        array (
                          'type' => 'property-access',
                          'left' => 
                          array (
                            'type' => 'variable',
                            'value' => 'this',
                            'file' => '/app/phalcon/Http/Message/AbstractMessage.zep',
                            'line' => 301,
                            'char' => 23,
                          ),
                          'right' => 
                          array (
                            'type' => 'variable',
                            'value' => 'uri',
                            'file' => '/app/phalcon/Http/Message/AbstractMessage.zep',
                            'line' => 301,
                            'char' => 28,
                          ),
                          'file' => '/app/phalcon/Http/Message/AbstractMessage.zep',
                          'line' => 301,
                          'char' => 28,
                        ),
                        'name' => 'getHost',
                        'call-type' => 1,
                        'file' => '/app/phalcon/Http/Message/AbstractMessage.zep',
                        'line' => 301,
                        'char' => 38,
                      ),
                      'file' => '/app/phalcon/Http/Message/AbstractMessage.zep',
                      'line' => 301,
                      'char' => 38,
                    ),
                    'file' => '/app/phalcon/Http/Message/AbstractMessage.zep',
                    'line' => 301,
                    'char' => 38,
                  ),
                  'file' => '/app/phalcon/Http/Message/AbstractMessage.zep',
                  'line' => 301,
                  'char' => 40,
                ),
                'file' => '/app/phalcon/Http/Message/AbstractMessage.zep',
                'line' => 301,
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
                      'variable' => 'host',
                      'expr' => 
                      array (
                        'type' => 'mcall',
                        'variable' => 
                        array (
                          'type' => 'variable',
                          'value' => 'this',
                          'file' => '/app/phalcon/Http/Message/AbstractMessage.zep',
                          'line' => 303,
                          'char' => 34,
                        ),
                        'name' => 'getUriHost',
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
                                'file' => '/app/phalcon/Http/Message/AbstractMessage.zep',
                                'line' => 303,
                                'char' => 51,
                              ),
                              'right' => 
                              array (
                                'type' => 'variable',
                                'value' => 'uri',
                                'file' => '/app/phalcon/Http/Message/AbstractMessage.zep',
                                'line' => 303,
                                'char' => 55,
                              ),
                              'file' => '/app/phalcon/Http/Message/AbstractMessage.zep',
                              'line' => 303,
                              'char' => 55,
                            ),
                            'file' => '/app/phalcon/Http/Message/AbstractMessage.zep',
                            'line' => 303,
                            'char' => 55,
                          ),
                        ),
                        'file' => '/app/phalcon/Http/Message/AbstractMessage.zep',
                        'line' => 303,
                        'char' => 56,
                      ),
                      'file' => '/app/phalcon/Http/Message/AbstractMessage.zep',
                      'line' => 303,
                      'char' => 56,
                    ),
                    1 => 
                    array (
                      'assign-type' => 'variable',
                      'operator' => 'assign',
                      'variable' => 'hostArray',
                      'expr' => 
                      array (
                        'type' => 'variable',
                        'value' => 'host',
                        'file' => '/app/phalcon/Http/Message/AbstractMessage.zep',
                        'line' => 304,
                        'char' => 33,
                      ),
                      'file' => '/app/phalcon/Http/Message/AbstractMessage.zep',
                      'line' => 304,
                      'char' => 33,
                    ),
                  ),
                  'file' => '/app/phalcon/Http/Message/AbstractMessage.zep',
                  'line' => 305,
                  'char' => 14,
                ),
                1 => 
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
                          'value' => 'host',
                          'file' => '/app/phalcon/Http/Message/AbstractMessage.zep',
                          'line' => 305,
                          'char' => 39,
                        ),
                        'file' => '/app/phalcon/Http/Message/AbstractMessage.zep',
                        'line' => 305,
                        'char' => 39,
                      ),
                      'right' => 
                      array (
                        'type' => 'string',
                        'value' => 'array',
                        'file' => '/app/phalcon/Http/Message/AbstractMessage.zep',
                        'line' => 305,
                        'char' => 47,
                      ),
                      'file' => '/app/phalcon/Http/Message/AbstractMessage.zep',
                      'line' => 305,
                      'char' => 47,
                    ),
                    'file' => '/app/phalcon/Http/Message/AbstractMessage.zep',
                    'line' => 305,
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
                          'assign-type' => 'variable',
                          'operator' => 'assign',
                          'variable' => 'hostArray',
                          'expr' => 
                          array (
                            'type' => 'array',
                            'left' => 
                            array (
                              0 => 
                              array (
                                'value' => 
                                array (
                                  'type' => 'variable',
                                  'value' => 'host',
                                  'file' => '/app/phalcon/Http/Message/AbstractMessage.zep',
                                  'line' => 306,
                                  'char' => 38,
                                ),
                                'file' => '/app/phalcon/Http/Message/AbstractMessage.zep',
                                'line' => 306,
                                'char' => 38,
                              ),
                            ),
                            'file' => '/app/phalcon/Http/Message/AbstractMessage.zep',
                            'line' => 306,
                            'char' => 39,
                          ),
                          'file' => '/app/phalcon/Http/Message/AbstractMessage.zep',
                          'line' => 306,
                          'char' => 39,
                        ),
                      ),
                      'file' => '/app/phalcon/Http/Message/AbstractMessage.zep',
                      'line' => 307,
                      'char' => 13,
                    ),
                  ),
                  'file' => '/app/phalcon/Http/Message/AbstractMessage.zep',
                  'line' => 309,
                  'char' => 22,
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
                      'value' => 'collection',
                      'file' => '/app/phalcon/Http/Message/AbstractMessage.zep',
                      'line' => 309,
                      'char' => 24,
                    ),
                    'name' => 'remove',
                    'call-type' => 1,
                    'parameters' => 
                    array (
                      0 => 
                      array (
                        'parameter' => 
                        array (
                          'type' => 'string',
                          'value' => 'host',
                          'file' => '/app/phalcon/Http/Message/AbstractMessage.zep',
                          'line' => 309,
                          'char' => 36,
                        ),
                        'file' => '/app/phalcon/Http/Message/AbstractMessage.zep',
                        'line' => 309,
                        'char' => 36,
                      ),
                    ),
                    'file' => '/app/phalcon/Http/Message/AbstractMessage.zep',
                    'line' => 309,
                    'char' => 37,
                  ),
                  'file' => '/app/phalcon/Http/Message/AbstractMessage.zep',
                  'line' => 311,
                  'char' => 15,
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
                      'variable' => 'data',
                      'expr' => 
                      array (
                        'type' => 'mcall',
                        'variable' => 
                        array (
                          'type' => 'variable',
                          'value' => 'collection',
                          'file' => '/app/phalcon/Http/Message/AbstractMessage.zep',
                          'line' => 311,
                          'char' => 45,
                        ),
                        'name' => 'toArray',
                        'call-type' => 1,
                        'file' => '/app/phalcon/Http/Message/AbstractMessage.zep',
                        'line' => 311,
                        'char' => 55,
                      ),
                      'file' => '/app/phalcon/Http/Message/AbstractMessage.zep',
                      'line' => 311,
                      'char' => 55,
                    ),
                    1 => 
                    array (
                      'assign-type' => 'variable',
                      'operator' => 'assign',
                      'variable' => 'header',
                      'expr' => 
                      array (
                        'type' => 'empty-array',
                        'file' => '/app/phalcon/Http/Message/AbstractMessage.zep',
                        'line' => 312,
                        'char' => 36,
                      ),
                      'file' => '/app/phalcon/Http/Message/AbstractMessage.zep',
                      'line' => 312,
                      'char' => 36,
                    ),
                    2 => 
                    array (
                      'assign-type' => 'array-index',
                      'operator' => 'assign',
                      'variable' => 'header',
                      'index-expr' => 
                      array (
                        0 => 
                        array (
                          'type' => 'string',
                          'value' => 'Host',
                          'file' => '/app/phalcon/Http/Message/AbstractMessage.zep',
                          'line' => 313,
                          'char' => 28,
                        ),
                      ),
                      'expr' => 
                      array (
                        'type' => 'variable',
                        'value' => 'hostArray',
                        'file' => '/app/phalcon/Http/Message/AbstractMessage.zep',
                        'line' => 313,
                        'char' => 41,
                      ),
                      'file' => '/app/phalcon/Http/Message/AbstractMessage.zep',
                      'line' => 313,
                      'char' => 41,
                    ),
                    3 => 
                    array (
                      'assign-type' => 'variable',
                      'operator' => 'assign',
                      'variable' => 'header',
                      'expr' => 
                      array (
                        'type' => 'add',
                        'left' => 
                        array (
                          'type' => 'variable',
                          'value' => 'header',
                          'file' => '/app/phalcon/Http/Message/AbstractMessage.zep',
                          'line' => 314,
                          'char' => 41,
                        ),
                        'right' => 
                        array (
                          'type' => 'cast',
                          'left' => 'array',
                          'right' => 
                          array (
                            'type' => 'variable',
                            'value' => 'data',
                            'file' => '/app/phalcon/Http/Message/AbstractMessage.zep',
                            'line' => 314,
                            'char' => 55,
                          ),
                          'file' => '/app/phalcon/Http/Message/AbstractMessage.zep',
                          'line' => 314,
                          'char' => 55,
                        ),
                        'file' => '/app/phalcon/Http/Message/AbstractMessage.zep',
                        'line' => 314,
                        'char' => 55,
                      ),
                      'file' => '/app/phalcon/Http/Message/AbstractMessage.zep',
                      'line' => 314,
                      'char' => 55,
                    ),
                  ),
                  'file' => '/app/phalcon/Http/Message/AbstractMessage.zep',
                  'line' => 316,
                  'char' => 22,
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
                      'value' => 'collection',
                      'file' => '/app/phalcon/Http/Message/AbstractMessage.zep',
                      'line' => 316,
                      'char' => 24,
                    ),
                    'name' => 'clear',
                    'call-type' => 1,
                    'file' => '/app/phalcon/Http/Message/AbstractMessage.zep',
                    'line' => 316,
                    'char' => 32,
                  ),
                  'file' => '/app/phalcon/Http/Message/AbstractMessage.zep',
                  'line' => 317,
                  'char' => 22,
                ),
                5 => 
                array (
                  'type' => 'mcall',
                  'expr' => 
                  array (
                    'type' => 'mcall',
                    'variable' => 
                    array (
                      'type' => 'variable',
                      'value' => 'collection',
                      'file' => '/app/phalcon/Http/Message/AbstractMessage.zep',
                      'line' => 317,
                      'char' => 24,
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
                          'value' => 'header',
                          'file' => '/app/phalcon/Http/Message/AbstractMessage.zep',
                          'line' => 317,
                          'char' => 36,
                        ),
                        'file' => '/app/phalcon/Http/Message/AbstractMessage.zep',
                        'line' => 317,
                        'char' => 36,
                      ),
                    ),
                    'file' => '/app/phalcon/Http/Message/AbstractMessage.zep',
                    'line' => 317,
                    'char' => 37,
                  ),
                  'file' => '/app/phalcon/Http/Message/AbstractMessage.zep',
                  'line' => 318,
                  'char' => 9,
                ),
              ),
              'file' => '/app/phalcon/Http/Message/AbstractMessage.zep',
              'line' => 320,
              'char' => 14,
            ),
            3 => 
            array (
              'type' => 'return',
              'expr' => 
              array (
                'type' => 'variable',
                'value' => 'collection',
                'file' => '/app/phalcon/Http/Message/AbstractMessage.zep',
                'line' => 320,
                'char' => 26,
              ),
              'file' => '/app/phalcon/Http/Message/AbstractMessage.zep',
              'line' => 321,
              'char' => 5,
            ),
          ),
          'docblock' => '**
     * Ensure Host is the first header.
     *
     * @see: http://tools.ietf.org/html/rfc7230#section-5.4
     *
     * @param Collection $collection
     *
     * @return Collection
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
                  'value' => 'Collection',
                  'file' => '/app/phalcon/Http/Message/AbstractMessage.zep',
                  'line' => 295,
                  'char' => 5,
                ),
                'collection' => 0,
                'file' => '/app/phalcon/Http/Message/AbstractMessage.zep',
                'line' => 295,
                'char' => 5,
              ),
            ),
            'void' => 0,
            'file' => '/app/phalcon/Http/Message/AbstractMessage.zep',
            'line' => 295,
            'char' => 5,
          ),
          'file' => '/app/phalcon/Http/Message/AbstractMessage.zep',
          'line' => 294,
          'last-line' => 329,
          'char' => 28,
        ),
        10 => 
        array (
          'visibility' => 
          array (
            0 => 'final',
            1 => 'protected',
          ),
          'type' => 'method',
          'name' => 'checkHeaderName',
          'parameters' => 
          array (
            0 => 
            array (
              'type' => 'parameter',
              'name' => 'name',
              'const' => 0,
              'data-type' => 'variable',
              'mandatory' => 0,
              'reference' => 0,
              'file' => '/app/phalcon/Http/Message/AbstractMessage.zep',
              'line' => 330,
              'char' => 54,
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
                    'type' => 'or',
                    'left' => 
                    array (
                      'type' => 'not-identical',
                      'left' => 
                      array (
                        'type' => 'typeof',
                        'left' => 
                        array (
                          'type' => 'variable',
                          'value' => 'name',
                          'file' => '/app/phalcon/Http/Message/AbstractMessage.zep',
                          'line' => 332,
                          'char' => 36,
                        ),
                        'file' => '/app/phalcon/Http/Message/AbstractMessage.zep',
                        'line' => 332,
                        'char' => 36,
                      ),
                      'right' => 
                      array (
                        'type' => 'string',
                        'value' => 'string',
                        'file' => '/app/phalcon/Http/Message/AbstractMessage.zep',
                        'line' => 332,
                        'char' => 47,
                      ),
                      'file' => '/app/phalcon/Http/Message/AbstractMessage.zep',
                      'line' => 332,
                      'char' => 47,
                    ),
                    'right' => 
                    array (
                      'type' => 'not',
                      'left' => 
                      array (
                        'type' => 'fcall',
                        'name' => 'preg_match',
                        'call-type' => 1,
                        'parameters' => 
                        array (
                          0 => 
                          array (
                            'parameter' => 
                            array (
                              'type' => 'string',
                              'value' => '/^[a-zA-Z0-9\'`#$%&*+.^_|~!-]+$/',
                              'file' => '/app/phalcon/Http/Message/AbstractMessage.zep',
                              'line' => 333,
                              'char' => 56,
                            ),
                            'file' => '/app/phalcon/Http/Message/AbstractMessage.zep',
                            'line' => 333,
                            'char' => 56,
                          ),
                          1 => 
                          array (
                            'parameter' => 
                            array (
                              'type' => 'variable',
                              'value' => 'name',
                              'file' => '/app/phalcon/Http/Message/AbstractMessage.zep',
                              'line' => 333,
                              'char' => 62,
                            ),
                            'file' => '/app/phalcon/Http/Message/AbstractMessage.zep',
                            'line' => 333,
                            'char' => 62,
                          ),
                        ),
                        'file' => '/app/phalcon/Http/Message/AbstractMessage.zep',
                        'line' => 333,
                        'char' => 63,
                      ),
                      'file' => '/app/phalcon/Http/Message/AbstractMessage.zep',
                      'line' => 333,
                      'char' => 63,
                    ),
                    'file' => '/app/phalcon/Http/Message/AbstractMessage.zep',
                    'line' => 333,
                    'char' => 63,
                  ),
                  'file' => '/app/phalcon/Http/Message/AbstractMessage.zep',
                  'line' => 333,
                  'char' => 65,
                ),
                'file' => '/app/phalcon/Http/Message/AbstractMessage.zep',
                'line' => 333,
                'char' => 65,
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
                            'type' => 'string',
                            'value' => 'Invalid header name ',
                            'file' => '/app/phalcon/Http/Message/AbstractMessage.zep',
                            'line' => 335,
                            'char' => 38,
                          ),
                          'right' => 
                          array (
                            'type' => 'variable',
                            'value' => 'name',
                            'file' => '/app/phalcon/Http/Message/AbstractMessage.zep',
                            'line' => 336,
                            'char' => 13,
                          ),
                          'file' => '/app/phalcon/Http/Message/AbstractMessage.zep',
                          'line' => 336,
                          'char' => 13,
                        ),
                        'file' => '/app/phalcon/Http/Message/AbstractMessage.zep',
                        'line' => 336,
                        'char' => 13,
                      ),
                    ),
                    'file' => '/app/phalcon/Http/Message/AbstractMessage.zep',
                    'line' => 336,
                    'char' => 14,
                  ),
                  'file' => '/app/phalcon/Http/Message/AbstractMessage.zep',
                  'line' => 337,
                  'char' => 9,
                ),
              ),
              'file' => '/app/phalcon/Http/Message/AbstractMessage.zep',
              'line' => 338,
              'char' => 5,
            ),
          ),
          'docblock' => '**
     * Check the name of the header. Throw exception if not valid
     *
     * @see http://tools.ietf.org/html/rfc7230#section-3.2
     *
     * @param $name
     *',
          'return-type' => 
          array (
            'type' => 'return-type',
            'void' => 1,
            'file' => '/app/phalcon/Http/Message/AbstractMessage.zep',
            'line' => 331,
            'char' => 5,
          ),
          'file' => '/app/phalcon/Http/Message/AbstractMessage.zep',
          'line' => 330,
          'last-line' => 386,
          'char' => 28,
        ),
        11 => 
        array (
          'visibility' => 
          array (
            0 => 'final',
            1 => 'protected',
          ),
          'type' => 'method',
          'name' => 'checkHeaderValue',
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
              'file' => '/app/phalcon/Http/Message/AbstractMessage.zep',
              'line' => 387,
              'char' => 56,
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
                          'value' => 'value',
                          'file' => '/app/phalcon/Http/Message/AbstractMessage.zep',
                          'line' => 389,
                          'char' => 37,
                        ),
                        'file' => '/app/phalcon/Http/Message/AbstractMessage.zep',
                        'line' => 389,
                        'char' => 37,
                      ),
                      'right' => 
                      array (
                        'type' => 'string',
                        'value' => 'string',
                        'file' => '/app/phalcon/Http/Message/AbstractMessage.zep',
                        'line' => 389,
                        'char' => 47,
                      ),
                      'file' => '/app/phalcon/Http/Message/AbstractMessage.zep',
                      'line' => 389,
                      'char' => 47,
                    ),
                    'right' => 
                    array (
                      'type' => 'not-identical',
                      'left' => 
                      array (
                        'type' => 'bool',
                        'value' => 'true',
                        'file' => '/app/phalcon/Http/Message/AbstractMessage.zep',
                        'line' => 389,
                        'char' => 56,
                      ),
                      'right' => 
                      array (
                        'type' => 'fcall',
                        'name' => 'is_numeric',
                        'call-type' => 1,
                        'parameters' => 
                        array (
                          0 => 
                          array (
                            'parameter' => 
                            array (
                              'type' => 'variable',
                              'value' => 'value',
                              'file' => '/app/phalcon/Http/Message/AbstractMessage.zep',
                              'line' => 389,
                              'char' => 74,
                            ),
                            'file' => '/app/phalcon/Http/Message/AbstractMessage.zep',
                            'line' => 389,
                            'char' => 74,
                          ),
                        ),
                        'file' => '/app/phalcon/Http/Message/AbstractMessage.zep',
                        'line' => 389,
                        'char' => 75,
                      ),
                      'file' => '/app/phalcon/Http/Message/AbstractMessage.zep',
                      'line' => 389,
                      'char' => 75,
                    ),
                    'file' => '/app/phalcon/Http/Message/AbstractMessage.zep',
                    'line' => 389,
                    'char' => 75,
                  ),
                  'file' => '/app/phalcon/Http/Message/AbstractMessage.zep',
                  'line' => 389,
                  'char' => 77,
                ),
                'file' => '/app/phalcon/Http/Message/AbstractMessage.zep',
                'line' => 389,
                'char' => 77,
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
                          'value' => 'Invalid header value',
                          'file' => '/app/phalcon/Http/Message/AbstractMessage.zep',
                          'line' => 390,
                          'char' => 68,
                        ),
                        'file' => '/app/phalcon/Http/Message/AbstractMessage.zep',
                        'line' => 390,
                        'char' => 68,
                      ),
                    ),
                    'file' => '/app/phalcon/Http/Message/AbstractMessage.zep',
                    'line' => 390,
                    'char' => 69,
                  ),
                  'file' => '/app/phalcon/Http/Message/AbstractMessage.zep',
                  'line' => 391,
                  'char' => 9,
                ),
              ),
              'file' => '/app/phalcon/Http/Message/AbstractMessage.zep',
              'line' => 393,
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
                  'variable' => 'value',
                  'expr' => 
                  array (
                    'type' => 'cast',
                    'left' => 'string',
                    'right' => 
                    array (
                      'type' => 'variable',
                      'value' => 'value',
                      'file' => '/app/phalcon/Http/Message/AbstractMessage.zep',
                      'line' => 393,
                      'char' => 35,
                    ),
                    'file' => '/app/phalcon/Http/Message/AbstractMessage.zep',
                    'line' => 393,
                    'char' => 35,
                  ),
                  'file' => '/app/phalcon/Http/Message/AbstractMessage.zep',
                  'line' => 393,
                  'char' => 35,
                ),
              ),
              'file' => '/app/phalcon/Http/Message/AbstractMessage.zep',
              'line' => 395,
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
                    'type' => 'or',
                    'left' => 
                    array (
                      'type' => 'fcall',
                      'name' => 'preg_match',
                      'call-type' => 1,
                      'parameters' => 
                      array (
                        0 => 
                        array (
                          'parameter' => 
                          array (
                            'type' => 'string',
                            'value' => '#(?:(?:(?<!\\r)\\n)|(?:\\r(?!\\n))|(?:\\r\\n(?![ \\t])))#',
                            'file' => '/app/phalcon/Http/Message/AbstractMessage.zep',
                            'line' => 395,
                            'char' => 83,
                          ),
                          'file' => '/app/phalcon/Http/Message/AbstractMessage.zep',
                          'line' => 395,
                          'char' => 83,
                        ),
                        1 => 
                        array (
                          'parameter' => 
                          array (
                            'type' => 'variable',
                            'value' => 'value',
                            'file' => '/app/phalcon/Http/Message/AbstractMessage.zep',
                            'line' => 395,
                            'char' => 90,
                          ),
                          'file' => '/app/phalcon/Http/Message/AbstractMessage.zep',
                          'line' => 395,
                          'char' => 90,
                        ),
                      ),
                      'file' => '/app/phalcon/Http/Message/AbstractMessage.zep',
                      'line' => 395,
                      'char' => 93,
                    ),
                    'right' => 
                    array (
                      'type' => 'fcall',
                      'name' => 'preg_match',
                      'call-type' => 1,
                      'parameters' => 
                      array (
                        0 => 
                        array (
                          'parameter' => 
                          array (
                            'type' => 'string',
                            'value' => '/[^\\x09\\x0a\\x0d\\x20-\\x7E\\x80-\\xFE]/',
                            'file' => '/app/phalcon/Http/Message/AbstractMessage.zep',
                            'line' => 396,
                            'char' => 59,
                          ),
                          'file' => '/app/phalcon/Http/Message/AbstractMessage.zep',
                          'line' => 396,
                          'char' => 59,
                        ),
                        1 => 
                        array (
                          'parameter' => 
                          array (
                            'type' => 'variable',
                            'value' => 'value',
                            'file' => '/app/phalcon/Http/Message/AbstractMessage.zep',
                            'line' => 396,
                            'char' => 66,
                          ),
                          'file' => '/app/phalcon/Http/Message/AbstractMessage.zep',
                          'line' => 396,
                          'char' => 66,
                        ),
                      ),
                      'file' => '/app/phalcon/Http/Message/AbstractMessage.zep',
                      'line' => 396,
                      'char' => 67,
                    ),
                    'file' => '/app/phalcon/Http/Message/AbstractMessage.zep',
                    'line' => 396,
                    'char' => 67,
                  ),
                  'file' => '/app/phalcon/Http/Message/AbstractMessage.zep',
                  'line' => 396,
                  'char' => 69,
                ),
                'file' => '/app/phalcon/Http/Message/AbstractMessage.zep',
                'line' => 396,
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
                          'value' => 'Invalid header value',
                          'file' => '/app/phalcon/Http/Message/AbstractMessage.zep',
                          'line' => 397,
                          'char' => 68,
                        ),
                        'file' => '/app/phalcon/Http/Message/AbstractMessage.zep',
                        'line' => 397,
                        'char' => 68,
                      ),
                    ),
                    'file' => '/app/phalcon/Http/Message/AbstractMessage.zep',
                    'line' => 397,
                    'char' => 69,
                  ),
                  'file' => '/app/phalcon/Http/Message/AbstractMessage.zep',
                  'line' => 398,
                  'char' => 9,
                ),
              ),
              'file' => '/app/phalcon/Http/Message/AbstractMessage.zep',
              'line' => 399,
              'char' => 5,
            ),
          ),
          'docblock' => '**
     * Validates a header value
     *
     * Most HTTP header field values are defined using common syntax
     * components (token, quoted-string, and comment) separated by
     * whitespace or specific delimiting characters.  Delimiters are chosen
     * from the set of US-ASCII visual characters not allowed in a token
     * (DQUOTE and \'(),/:;<=>?@[\\]{}\').
     *
     *     token          = 1*tchar
     *
     *     tchar          = \'!\' / \'#\' / \'$\' / \'%\' / \'&\' / \'\'\' / \'*\'
     *                    / \'+\' / \'-\' / \'.\' / \'^\' / \'_\' / \'`\' / \'|\' / \'~\'
     *                    / DIGIT / ALPHA
     *                    ; any VCHAR, except delimiters
     *
     * A string of text is parsed as a single value if it is quoted using
     * double-quote marks.
     *
     *     quoted-string  = DQUOTE *( qdtext / quoted-pair ) DQUOTE
     *     qdtext         = HTAB / SP /%x21 / %x23-5B / %x5D-7E / obs-text
     *     obs-text       = %x80-FF
     *
     * Comments can be included in some HTTP header fields by surrounding
     * the comment text with parentheses.  Comments are only allowed in
     * fields containing \'comment\' as part of their field value definition.
     *
     *     comment        = \'(\' *( ctext / quoted-pair / comment ) \')\'
     *     ctext          = HTAB / SP / %x21-27 / %x2A-5B / %x5D-7E / obs-text
     *
     * The backslash octet (\'\\\') can be used as a single-octet quoting
     * mechanism within quoted-string and comment constructs.  Recipients
     * that process the value of a quoted-string MUST handle a quoted-pair
     * as if it were replaced by the octet following the backslash.
     *
     *     quoted-pair    = \'\\\' ( HTAB / SP / VCHAR / obs-text )
     *
     * A sender SHOULD NOT generate a quoted-pair in a quoted-string except
     * where necessary to quote DQUOTE and backslash octets occurring within
     * that string.  A sender SHOULD NOT generate a quoted-pair in a comment
     * except where necessary to quote parentheses [\'(\' and \')\'] and
     * backslash octets occurring within that comment.
     *
     * @see https://tools.ietf.org/html/rfc7230#section-3.2.6
     *
     * @param $value
     *',
          'return-type' => 
          array (
            'type' => 'return-type',
            'void' => 1,
            'file' => '/app/phalcon/Http/Message/AbstractMessage.zep',
            'line' => 388,
            'char' => 5,
          ),
          'file' => '/app/phalcon/Http/Message/AbstractMessage.zep',
          'line' => 387,
          'last-line' => 407,
          'char' => 28,
        ),
        12 => 
        array (
          'visibility' => 
          array (
            0 => 'final',
            1 => 'protected',
          ),
          'type' => 'method',
          'name' => 'getHeaderValue',
          'parameters' => 
          array (
            0 => 
            array (
              'type' => 'parameter',
              'name' => 'values',
              'const' => 0,
              'data-type' => 'variable',
              'mandatory' => 0,
              'reference' => 0,
              'file' => '/app/phalcon/Http/Message/AbstractMessage.zep',
              'line' => 408,
              'char' => 55,
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
                  'file' => '/app/phalcon/Http/Message/AbstractMessage.zep',
                  'line' => 410,
                  'char' => 18,
                ),
                1 => 
                array (
                  'variable' => 'valueArray',
                  'file' => '/app/phalcon/Http/Message/AbstractMessage.zep',
                  'line' => 410,
                  'char' => 30,
                ),
                2 => 
                array (
                  'variable' => 'valueData',
                  'file' => '/app/phalcon/Http/Message/AbstractMessage.zep',
                  'line' => 410,
                  'char' => 41,
                ),
              ),
              'file' => '/app/phalcon/Http/Message/AbstractMessage.zep',
              'line' => 412,
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
                  'variable' => 'valueArray',
                  'expr' => 
                  array (
                    'type' => 'variable',
                    'value' => 'values',
                    'file' => '/app/phalcon/Http/Message/AbstractMessage.zep',
                    'line' => 412,
                    'char' => 32,
                  ),
                  'file' => '/app/phalcon/Http/Message/AbstractMessage.zep',
                  'line' => 412,
                  'char' => 32,
                ),
              ),
              'file' => '/app/phalcon/Http/Message/AbstractMessage.zep',
              'line' => 413,
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
                  'type' => 'not-identical',
                  'left' => 
                  array (
                    'type' => 'typeof',
                    'left' => 
                    array (
                      'type' => 'variable',
                      'value' => 'values',
                      'file' => '/app/phalcon/Http/Message/AbstractMessage.zep',
                      'line' => 413,
                      'char' => 37,
                    ),
                    'file' => '/app/phalcon/Http/Message/AbstractMessage.zep',
                    'line' => 413,
                    'char' => 37,
                  ),
                  'right' => 
                  array (
                    'type' => 'string',
                    'value' => 'array',
                    'file' => '/app/phalcon/Http/Message/AbstractMessage.zep',
                    'line' => 413,
                    'char' => 45,
                  ),
                  'file' => '/app/phalcon/Http/Message/AbstractMessage.zep',
                  'line' => 413,
                  'char' => 45,
                ),
                'file' => '/app/phalcon/Http/Message/AbstractMessage.zep',
                'line' => 413,
                'char' => 45,
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
                      'variable' => 'valueArray',
                      'expr' => 
                      array (
                        'type' => 'array',
                        'left' => 
                        array (
                          0 => 
                          array (
                            'value' => 
                            array (
                              'type' => 'variable',
                              'value' => 'values',
                              'file' => '/app/phalcon/Http/Message/AbstractMessage.zep',
                              'line' => 414,
                              'char' => 37,
                            ),
                            'file' => '/app/phalcon/Http/Message/AbstractMessage.zep',
                            'line' => 414,
                            'char' => 37,
                          ),
                        ),
                        'file' => '/app/phalcon/Http/Message/AbstractMessage.zep',
                        'line' => 414,
                        'char' => 38,
                      ),
                      'file' => '/app/phalcon/Http/Message/AbstractMessage.zep',
                      'line' => 414,
                      'char' => 38,
                    ),
                  ),
                  'file' => '/app/phalcon/Http/Message/AbstractMessage.zep',
                  'line' => 415,
                  'char' => 9,
                ),
              ),
              'file' => '/app/phalcon/Http/Message/AbstractMessage.zep',
              'line' => 417,
              'char' => 10,
            ),
            3 => 
            array (
              'type' => 'if',
              'expr' => 
              array (
                'type' => 'unlikely',
                'left' => 
                array (
                  'type' => 'empty',
                  'left' => 
                  array (
                    'type' => 'list',
                    'left' => 
                    array (
                      'type' => 'variable',
                      'value' => 'valueArray',
                      'file' => '/app/phalcon/Http/Message/AbstractMessage.zep',
                      'line' => 417,
                      'char' => 37,
                    ),
                    'file' => '/app/phalcon/Http/Message/AbstractMessage.zep',
                    'line' => 417,
                    'char' => 39,
                  ),
                  'file' => '/app/phalcon/Http/Message/AbstractMessage.zep',
                  'line' => 417,
                  'char' => 39,
                ),
                'file' => '/app/phalcon/Http/Message/AbstractMessage.zep',
                'line' => 417,
                'char' => 39,
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
                            'type' => 'string',
                            'value' => 'Invalid header value: must be a string or ',
                            'file' => '/app/phalcon/Http/Message/AbstractMessage.zep',
                            'line' => 419,
                            'char' => 60,
                          ),
                          'right' => 
                          array (
                            'type' => 'string',
                            'value' => 'array of strings; cannot be an empty array',
                            'file' => '/app/phalcon/Http/Message/AbstractMessage.zep',
                            'line' => 421,
                            'char' => 13,
                          ),
                          'file' => '/app/phalcon/Http/Message/AbstractMessage.zep',
                          'line' => 421,
                          'char' => 13,
                        ),
                        'file' => '/app/phalcon/Http/Message/AbstractMessage.zep',
                        'line' => 421,
                        'char' => 13,
                      ),
                    ),
                    'file' => '/app/phalcon/Http/Message/AbstractMessage.zep',
                    'line' => 421,
                    'char' => 14,
                  ),
                  'file' => '/app/phalcon/Http/Message/AbstractMessage.zep',
                  'line' => 422,
                  'char' => 9,
                ),
              ),
              'file' => '/app/phalcon/Http/Message/AbstractMessage.zep',
              'line' => 424,
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
                  'variable' => 'valueData',
                  'expr' => 
                  array (
                    'type' => 'empty-array',
                    'file' => '/app/phalcon/Http/Message/AbstractMessage.zep',
                    'line' => 424,
                    'char' => 27,
                  ),
                  'file' => '/app/phalcon/Http/Message/AbstractMessage.zep',
                  'line' => 424,
                  'char' => 27,
                ),
              ),
              'file' => '/app/phalcon/Http/Message/AbstractMessage.zep',
              'line' => 425,
              'char' => 11,
            ),
            5 => 
            array (
              'type' => 'for',
              'expr' => 
              array (
                'type' => 'variable',
                'value' => 'valueArray',
                'file' => '/app/phalcon/Http/Message/AbstractMessage.zep',
                'line' => 425,
                'char' => 33,
              ),
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
                      'file' => '/app/phalcon/Http/Message/AbstractMessage.zep',
                      'line' => 426,
                      'char' => 18,
                    ),
                    'name' => 'checkHeaderValue',
                    'call-type' => 1,
                    'parameters' => 
                    array (
                      0 => 
                      array (
                        'parameter' => 
                        array (
                          'type' => 'variable',
                          'value' => 'value',
                          'file' => '/app/phalcon/Http/Message/AbstractMessage.zep',
                          'line' => 426,
                          'char' => 41,
                        ),
                        'file' => '/app/phalcon/Http/Message/AbstractMessage.zep',
                        'line' => 426,
                        'char' => 41,
                      ),
                    ),
                    'file' => '/app/phalcon/Http/Message/AbstractMessage.zep',
                    'line' => 426,
                    'char' => 42,
                  ),
                  'file' => '/app/phalcon/Http/Message/AbstractMessage.zep',
                  'line' => 428,
                  'char' => 15,
                ),
                1 => 
                array (
                  'type' => 'let',
                  'assignments' => 
                  array (
                    0 => 
                    array (
                      'assign-type' => 'variable-append',
                      'operator' => 'assign',
                      'variable' => 'valueData',
                      'expr' => 
                      array (
                        'type' => 'cast',
                        'left' => 'string',
                        'right' => 
                        array (
                          'type' => 'variable',
                          'value' => 'value',
                          'file' => '/app/phalcon/Http/Message/AbstractMessage.zep',
                          'line' => 428,
                          'char' => 45,
                        ),
                        'file' => '/app/phalcon/Http/Message/AbstractMessage.zep',
                        'line' => 428,
                        'char' => 45,
                      ),
                      'file' => '/app/phalcon/Http/Message/AbstractMessage.zep',
                      'line' => 428,
                      'char' => 45,
                    ),
                  ),
                  'file' => '/app/phalcon/Http/Message/AbstractMessage.zep',
                  'line' => 429,
                  'char' => 9,
                ),
              ),
              'file' => '/app/phalcon/Http/Message/AbstractMessage.zep',
              'line' => 431,
              'char' => 14,
            ),
            6 => 
            array (
              'type' => 'return',
              'expr' => 
              array (
                'type' => 'variable',
                'value' => 'valueData',
                'file' => '/app/phalcon/Http/Message/AbstractMessage.zep',
                'line' => 431,
                'char' => 25,
              ),
              'file' => '/app/phalcon/Http/Message/AbstractMessage.zep',
              'line' => 432,
              'char' => 5,
            ),
          ),
          'docblock' => '**
     * Returns the header values checked for validity
     *
     * @param $values
     *
     * @return array
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
                'file' => '/app/phalcon/Http/Message/AbstractMessage.zep',
                'line' => 409,
                'char' => 5,
              ),
            ),
            'void' => 0,
            'file' => '/app/phalcon/Http/Message/AbstractMessage.zep',
            'line' => 409,
            'char' => 5,
          ),
          'file' => '/app/phalcon/Http/Message/AbstractMessage.zep',
          'line' => 408,
          'last-line' => 440,
          'char' => 28,
        ),
        13 => 
        array (
          'visibility' => 
          array (
            0 => 'final',
            1 => 'protected',
          ),
          'type' => 'method',
          'name' => 'getUriHost',
          'parameters' => 
          array (
            0 => 
            array (
              'type' => 'parameter',
              'name' => 'uri',
              'const' => 0,
              'data-type' => 'variable',
              'mandatory' => 0,
              'cast' => 
              array (
                'type' => 'variable',
                'value' => 'UriInterface',
                'file' => '/app/phalcon/Http/Message/AbstractMessage.zep',
                'line' => 441,
                'char' => 58,
              ),
              'reference' => 0,
              'file' => '/app/phalcon/Http/Message/AbstractMessage.zep',
              'line' => 441,
              'char' => 59,
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
                  'variable' => 'host',
                  'file' => '/app/phalcon/Http/Message/AbstractMessage.zep',
                  'line' => 443,
                  'char' => 17,
                ),
              ),
              'file' => '/app/phalcon/Http/Message/AbstractMessage.zep',
              'line' => 445,
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
                  'variable' => 'host',
                  'expr' => 
                  array (
                    'type' => 'mcall',
                    'variable' => 
                    array (
                      'type' => 'variable',
                      'value' => 'uri',
                      'file' => '/app/phalcon/Http/Message/AbstractMessage.zep',
                      'line' => 445,
                      'char' => 24,
                    ),
                    'name' => 'getHost',
                    'call-type' => 1,
                    'file' => '/app/phalcon/Http/Message/AbstractMessage.zep',
                    'line' => 445,
                    'char' => 34,
                  ),
                  'file' => '/app/phalcon/Http/Message/AbstractMessage.zep',
                  'line' => 445,
                  'char' => 34,
                ),
              ),
              'file' => '/app/phalcon/Http/Message/AbstractMessage.zep',
              'line' => 447,
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
                  'type' => 'not-identical',
                  'left' => 
                  array (
                    'type' => 'null',
                    'file' => '/app/phalcon/Http/Message/AbstractMessage.zep',
                    'line' => 447,
                    'char' => 28,
                  ),
                  'right' => 
                  array (
                    'type' => 'mcall',
                    'variable' => 
                    array (
                      'type' => 'variable',
                      'value' => 'uri',
                      'file' => '/app/phalcon/Http/Message/AbstractMessage.zep',
                      'line' => 447,
                      'char' => 34,
                    ),
                    'name' => 'getPort',
                    'call-type' => 1,
                    'file' => '/app/phalcon/Http/Message/AbstractMessage.zep',
                    'line' => 447,
                    'char' => 45,
                  ),
                  'file' => '/app/phalcon/Http/Message/AbstractMessage.zep',
                  'line' => 447,
                  'char' => 45,
                ),
                'file' => '/app/phalcon/Http/Message/AbstractMessage.zep',
                'line' => 447,
                'char' => 45,
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
                      'operator' => 'concat-assign',
                      'variable' => 'host',
                      'expr' => 
                      array (
                        'type' => 'concat',
                        'left' => 
                        array (
                          'type' => 'string',
                          'value' => ':',
                          'file' => '/app/phalcon/Http/Message/AbstractMessage.zep',
                          'line' => 448,
                          'char' => 26,
                        ),
                        'right' => 
                        array (
                          'type' => 'mcall',
                          'variable' => 
                          array (
                            'type' => 'variable',
                            'value' => 'uri',
                            'file' => '/app/phalcon/Http/Message/AbstractMessage.zep',
                            'line' => 448,
                            'char' => 32,
                          ),
                          'name' => 'getPort',
                          'call-type' => 1,
                          'file' => '/app/phalcon/Http/Message/AbstractMessage.zep',
                          'line' => 448,
                          'char' => 42,
                        ),
                        'file' => '/app/phalcon/Http/Message/AbstractMessage.zep',
                        'line' => 448,
                        'char' => 42,
                      ),
                      'file' => '/app/phalcon/Http/Message/AbstractMessage.zep',
                      'line' => 448,
                      'char' => 42,
                    ),
                  ),
                  'file' => '/app/phalcon/Http/Message/AbstractMessage.zep',
                  'line' => 449,
                  'char' => 9,
                ),
              ),
              'file' => '/app/phalcon/Http/Message/AbstractMessage.zep',
              'line' => 451,
              'char' => 14,
            ),
            3 => 
            array (
              'type' => 'return',
              'expr' => 
              array (
                'type' => 'variable',
                'value' => 'host',
                'file' => '/app/phalcon/Http/Message/AbstractMessage.zep',
                'line' => 451,
                'char' => 20,
              ),
              'file' => '/app/phalcon/Http/Message/AbstractMessage.zep',
              'line' => 452,
              'char' => 5,
            ),
          ),
          'docblock' => '**
     * Return the host and if applicable the port
     *
     * @param UriInterface $uri
     *
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
                'file' => '/app/phalcon/Http/Message/AbstractMessage.zep',
                'line' => 442,
                'char' => 5,
              ),
            ),
            'void' => 0,
            'file' => '/app/phalcon/Http/Message/AbstractMessage.zep',
            'line' => 442,
            'char' => 5,
          ),
          'file' => '/app/phalcon/Http/Message/AbstractMessage.zep',
          'line' => 441,
          'last-line' => 460,
          'char' => 28,
        ),
        14 => 
        array (
          'visibility' => 
          array (
            0 => 'final',
            1 => 'protected',
          ),
          'type' => 'method',
          'name' => 'populateHeaderCollection',
          'parameters' => 
          array (
            0 => 
            array (
              'type' => 'parameter',
              'name' => 'headers',
              'const' => 0,
              'data-type' => 'array',
              'mandatory' => 0,
              'reference' => 0,
              'file' => '/app/phalcon/Http/Message/AbstractMessage.zep',
              'line' => 461,
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
                  'variable' => 'collection',
                  'file' => '/app/phalcon/Http/Message/AbstractMessage.zep',
                  'line' => 463,
                  'char' => 23,
                ),
                1 => 
                array (
                  'variable' => 'name',
                  'file' => '/app/phalcon/Http/Message/AbstractMessage.zep',
                  'line' => 463,
                  'char' => 29,
                ),
                2 => 
                array (
                  'variable' => 'value',
                  'file' => '/app/phalcon/Http/Message/AbstractMessage.zep',
                  'line' => 463,
                  'char' => 36,
                ),
              ),
              'file' => '/app/phalcon/Http/Message/AbstractMessage.zep',
              'line' => 465,
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
                  'variable' => 'collection',
                  'expr' => 
                  array (
                    'type' => 'new',
                    'class' => 'Collection',
                    'dynamic' => 0,
                    'file' => '/app/phalcon/Http/Message/AbstractMessage.zep',
                    'line' => 465,
                    'char' => 42,
                  ),
                  'file' => '/app/phalcon/Http/Message/AbstractMessage.zep',
                  'line' => 465,
                  'char' => 42,
                ),
              ),
              'file' => '/app/phalcon/Http/Message/AbstractMessage.zep',
              'line' => 466,
              'char' => 11,
            ),
            2 => 
            array (
              'type' => 'for',
              'expr' => 
              array (
                'type' => 'variable',
                'value' => 'headers',
                'file' => '/app/phalcon/Http/Message/AbstractMessage.zep',
                'line' => 466,
                'char' => 36,
              ),
              'key' => 'name',
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
                      'file' => '/app/phalcon/Http/Message/AbstractMessage.zep',
                      'line' => 467,
                      'char' => 18,
                    ),
                    'name' => 'checkHeaderName',
                    'call-type' => 1,
                    'parameters' => 
                    array (
                      0 => 
                      array (
                        'parameter' => 
                        array (
                          'type' => 'variable',
                          'value' => 'name',
                          'file' => '/app/phalcon/Http/Message/AbstractMessage.zep',
                          'line' => 467,
                          'char' => 39,
                        ),
                        'file' => '/app/phalcon/Http/Message/AbstractMessage.zep',
                        'line' => 467,
                        'char' => 39,
                      ),
                    ),
                    'file' => '/app/phalcon/Http/Message/AbstractMessage.zep',
                    'line' => 467,
                    'char' => 40,
                  ),
                  'file' => '/app/phalcon/Http/Message/AbstractMessage.zep',
                  'line' => 469,
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
                      'variable' => 'name',
                      'expr' => 
                      array (
                        'type' => 'cast',
                        'left' => 'string',
                        'right' => 
                        array (
                          'type' => 'variable',
                          'value' => 'name',
                          'file' => '/app/phalcon/Http/Message/AbstractMessage.zep',
                          'line' => 469,
                          'char' => 38,
                        ),
                        'file' => '/app/phalcon/Http/Message/AbstractMessage.zep',
                        'line' => 469,
                        'char' => 38,
                      ),
                      'file' => '/app/phalcon/Http/Message/AbstractMessage.zep',
                      'line' => 469,
                      'char' => 38,
                    ),
                    1 => 
                    array (
                      'assign-type' => 'variable',
                      'operator' => 'assign',
                      'variable' => 'value',
                      'expr' => 
                      array (
                        'type' => 'mcall',
                        'variable' => 
                        array (
                          'type' => 'variable',
                          'value' => 'this',
                          'file' => '/app/phalcon/Http/Message/AbstractMessage.zep',
                          'line' => 470,
                          'char' => 30,
                        ),
                        'name' => 'getHeaderValue',
                        'call-type' => 1,
                        'parameters' => 
                        array (
                          0 => 
                          array (
                            'parameter' => 
                            array (
                              'type' => 'variable',
                              'value' => 'value',
                              'file' => '/app/phalcon/Http/Message/AbstractMessage.zep',
                              'line' => 470,
                              'char' => 51,
                            ),
                            'file' => '/app/phalcon/Http/Message/AbstractMessage.zep',
                            'line' => 470,
                            'char' => 51,
                          ),
                        ),
                        'file' => '/app/phalcon/Http/Message/AbstractMessage.zep',
                        'line' => 470,
                        'char' => 52,
                      ),
                      'file' => '/app/phalcon/Http/Message/AbstractMessage.zep',
                      'line' => 470,
                      'char' => 52,
                    ),
                  ),
                  'file' => '/app/phalcon/Http/Message/AbstractMessage.zep',
                  'line' => 472,
                  'char' => 22,
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
                      'value' => 'collection',
                      'file' => '/app/phalcon/Http/Message/AbstractMessage.zep',
                      'line' => 472,
                      'char' => 24,
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
                          'value' => 'name',
                          'file' => '/app/phalcon/Http/Message/AbstractMessage.zep',
                          'line' => 472,
                          'char' => 33,
                        ),
                        'file' => '/app/phalcon/Http/Message/AbstractMessage.zep',
                        'line' => 472,
                        'char' => 33,
                      ),
                      1 => 
                      array (
                        'parameter' => 
                        array (
                          'type' => 'variable',
                          'value' => 'value',
                          'file' => '/app/phalcon/Http/Message/AbstractMessage.zep',
                          'line' => 472,
                          'char' => 40,
                        ),
                        'file' => '/app/phalcon/Http/Message/AbstractMessage.zep',
                        'line' => 472,
                        'char' => 40,
                      ),
                    ),
                    'file' => '/app/phalcon/Http/Message/AbstractMessage.zep',
                    'line' => 472,
                    'char' => 41,
                  ),
                  'file' => '/app/phalcon/Http/Message/AbstractMessage.zep',
                  'line' => 473,
                  'char' => 9,
                ),
              ),
              'file' => '/app/phalcon/Http/Message/AbstractMessage.zep',
              'line' => 475,
              'char' => 14,
            ),
            3 => 
            array (
              'type' => 'return',
              'expr' => 
              array (
                'type' => 'variable',
                'value' => 'collection',
                'file' => '/app/phalcon/Http/Message/AbstractMessage.zep',
                'line' => 475,
                'char' => 26,
              ),
              'file' => '/app/phalcon/Http/Message/AbstractMessage.zep',
              'line' => 476,
              'char' => 5,
            ),
          ),
          'docblock' => '**
     * Populates the header collection
     *
     * @param array $headers
     *
     * @return Collection
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
                  'value' => 'Collection',
                  'file' => '/app/phalcon/Http/Message/AbstractMessage.zep',
                  'line' => 462,
                  'char' => 5,
                ),
                'collection' => 0,
                'file' => '/app/phalcon/Http/Message/AbstractMessage.zep',
                'line' => 462,
                'char' => 5,
              ),
            ),
            'void' => 0,
            'file' => '/app/phalcon/Http/Message/AbstractMessage.zep',
            'line' => 462,
            'char' => 5,
          ),
          'file' => '/app/phalcon/Http/Message/AbstractMessage.zep',
          'line' => 461,
          'last-line' => 485,
          'char' => 28,
        ),
        15 => 
        array (
          'visibility' => 
          array (
            0 => 'final',
            1 => 'protected',
          ),
          'type' => 'method',
          'name' => 'processBody',
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
                'file' => '/app/phalcon/Http/Message/AbstractMessage.zep',
                'line' => 486,
                'char' => 65,
              ),
              'reference' => 0,
              'file' => '/app/phalcon/Http/Message/AbstractMessage.zep',
              'line' => 486,
              'char' => 65,
            ),
            1 => 
            array (
              'type' => 'parameter',
              'name' => 'mode',
              'const' => 0,
              'data-type' => 'string',
              'mandatory' => 1,
              'default' => 
              array (
                'type' => 'string',
                'value' => 'r+b',
                'file' => '/app/phalcon/Http/Message/AbstractMessage.zep',
                'line' => 486,
                'char' => 85,
              ),
              'reference' => 0,
              'file' => '/app/phalcon/Http/Message/AbstractMessage.zep',
              'line' => 486,
              'char' => 85,
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
                      'type' => 'identical',
                      'left' => 
                      array (
                        'type' => 'typeof',
                        'left' => 
                        array (
                          'type' => 'variable',
                          'value' => 'body',
                          'file' => '/app/phalcon/Http/Message/AbstractMessage.zep',
                          'line' => 488,
                          'char' => 36,
                        ),
                        'file' => '/app/phalcon/Http/Message/AbstractMessage.zep',
                        'line' => 488,
                        'char' => 36,
                      ),
                      'right' => 
                      array (
                        'type' => 'string',
                        'value' => 'object',
                        'file' => '/app/phalcon/Http/Message/AbstractMessage.zep',
                        'line' => 488,
                        'char' => 46,
                      ),
                      'file' => '/app/phalcon/Http/Message/AbstractMessage.zep',
                      'line' => 488,
                      'char' => 46,
                    ),
                    'right' => 
                    array (
                      'type' => 'instanceof',
                      'left' => 
                      array (
                        'type' => 'variable',
                        'value' => 'body',
                        'file' => '/app/phalcon/Http/Message/AbstractMessage.zep',
                        'line' => 488,
                        'char' => 62,
                      ),
                      'right' => 
                      array (
                        'type' => 'variable',
                        'value' => 'StreamInterface',
                        'file' => '/app/phalcon/Http/Message/AbstractMessage.zep',
                        'line' => 488,
                        'char' => 79,
                      ),
                      'file' => '/app/phalcon/Http/Message/AbstractMessage.zep',
                      'line' => 488,
                      'char' => 79,
                    ),
                    'file' => '/app/phalcon/Http/Message/AbstractMessage.zep',
                    'line' => 488,
                    'char' => 79,
                  ),
                  'file' => '/app/phalcon/Http/Message/AbstractMessage.zep',
                  'line' => 488,
                  'char' => 81,
                ),
                'file' => '/app/phalcon/Http/Message/AbstractMessage.zep',
                'line' => 488,
                'char' => 81,
              ),
              'statements' => 
              array (
                0 => 
                array (
                  'type' => 'return',
                  'expr' => 
                  array (
                    'type' => 'variable',
                    'value' => 'body',
                    'file' => '/app/phalcon/Http/Message/AbstractMessage.zep',
                    'line' => 489,
                    'char' => 24,
                  ),
                  'file' => '/app/phalcon/Http/Message/AbstractMessage.zep',
                  'line' => 490,
                  'char' => 9,
                ),
              ),
              'file' => '/app/phalcon/Http/Message/AbstractMessage.zep',
              'line' => 492,
              'char' => 10,
            ),
            1 => 
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
                          'value' => 'body',
                          'file' => '/app/phalcon/Http/Message/AbstractMessage.zep',
                          'line' => 492,
                          'char' => 36,
                        ),
                        'file' => '/app/phalcon/Http/Message/AbstractMessage.zep',
                        'line' => 492,
                        'char' => 36,
                      ),
                      'right' => 
                      array (
                        'type' => 'string',
                        'value' => 'string',
                        'file' => '/app/phalcon/Http/Message/AbstractMessage.zep',
                        'line' => 492,
                        'char' => 46,
                      ),
                      'file' => '/app/phalcon/Http/Message/AbstractMessage.zep',
                      'line' => 492,
                      'char' => 46,
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
                          'value' => 'body',
                          'file' => '/app/phalcon/Http/Message/AbstractMessage.zep',
                          'line' => 492,
                          'char' => 62,
                        ),
                        'file' => '/app/phalcon/Http/Message/AbstractMessage.zep',
                        'line' => 492,
                        'char' => 62,
                      ),
                      'right' => 
                      array (
                        'type' => 'string',
                        'value' => 'resource',
                        'file' => '/app/phalcon/Http/Message/AbstractMessage.zep',
                        'line' => 492,
                        'char' => 72,
                      ),
                      'file' => '/app/phalcon/Http/Message/AbstractMessage.zep',
                      'line' => 492,
                      'char' => 72,
                    ),
                    'file' => '/app/phalcon/Http/Message/AbstractMessage.zep',
                    'line' => 492,
                    'char' => 72,
                  ),
                  'file' => '/app/phalcon/Http/Message/AbstractMessage.zep',
                  'line' => 492,
                  'char' => 74,
                ),
                'file' => '/app/phalcon/Http/Message/AbstractMessage.zep',
                'line' => 492,
                'char' => 74,
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
                          'value' => 'Invalid stream passed as a parameter',
                          'file' => '/app/phalcon/Http/Message/AbstractMessage.zep',
                          'line' => 495,
                          'char' => 13,
                        ),
                        'file' => '/app/phalcon/Http/Message/AbstractMessage.zep',
                        'line' => 495,
                        'char' => 13,
                      ),
                    ),
                    'file' => '/app/phalcon/Http/Message/AbstractMessage.zep',
                    'line' => 495,
                    'char' => 14,
                  ),
                  'file' => '/app/phalcon/Http/Message/AbstractMessage.zep',
                  'line' => 496,
                  'char' => 9,
                ),
              ),
              'file' => '/app/phalcon/Http/Message/AbstractMessage.zep',
              'line' => 498,
              'char' => 14,
            ),
            2 => 
            array (
              'type' => 'return',
              'expr' => 
              array (
                'type' => 'new',
                'class' => 'Stream',
                'dynamic' => 0,
                'parameters' => 
                array (
                  0 => 
                  array (
                    'parameter' => 
                    array (
                      'type' => 'variable',
                      'value' => 'body',
                      'file' => '/app/phalcon/Http/Message/AbstractMessage.zep',
                      'line' => 498,
                      'char' => 31,
                    ),
                    'file' => '/app/phalcon/Http/Message/AbstractMessage.zep',
                    'line' => 498,
                    'char' => 31,
                  ),
                  1 => 
                  array (
                    'parameter' => 
                    array (
                      'type' => 'variable',
                      'value' => 'mode',
                      'file' => '/app/phalcon/Http/Message/AbstractMessage.zep',
                      'line' => 498,
                      'char' => 37,
                    ),
                    'file' => '/app/phalcon/Http/Message/AbstractMessage.zep',
                    'line' => 498,
                    'char' => 37,
                  ),
                ),
                'file' => '/app/phalcon/Http/Message/AbstractMessage.zep',
                'line' => 498,
                'char' => 38,
              ),
              'file' => '/app/phalcon/Http/Message/AbstractMessage.zep',
              'line' => 499,
              'char' => 5,
            ),
          ),
          'docblock' => '**
     * Set a valid stream
     *
     * @param StreamInterface|resource|string $body
     * @param string                          $mode
     *
     * @return StreamInterface
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
                  'value' => 'StreamInterface',
                  'file' => '/app/phalcon/Http/Message/AbstractMessage.zep',
                  'line' => 487,
                  'char' => 5,
                ),
                'collection' => 0,
                'file' => '/app/phalcon/Http/Message/AbstractMessage.zep',
                'line' => 487,
                'char' => 5,
              ),
            ),
            'void' => 0,
            'file' => '/app/phalcon/Http/Message/AbstractMessage.zep',
            'line' => 487,
            'char' => 5,
          ),
          'file' => '/app/phalcon/Http/Message/AbstractMessage.zep',
          'line' => 486,
          'last-line' => 507,
          'char' => 28,
        ),
        16 => 
        array (
          'visibility' => 
          array (
            0 => 'final',
            1 => 'protected',
          ),
          'type' => 'method',
          'name' => 'processHeaders',
          'parameters' => 
          array (
            0 => 
            array (
              'type' => 'parameter',
              'name' => 'headers',
              'const' => 0,
              'data-type' => 'variable',
              'mandatory' => 0,
              'reference' => 0,
              'file' => '/app/phalcon/Http/Message/AbstractMessage.zep',
              'line' => 508,
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
                  'variable' => 'collection',
                  'file' => '/app/phalcon/Http/Message/AbstractMessage.zep',
                  'line' => 510,
                  'char' => 23,
                ),
              ),
              'file' => '/app/phalcon/Http/Message/AbstractMessage.zep',
              'line' => 512,
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
                  'type' => 'identical',
                  'left' => 
                  array (
                    'type' => 'typeof',
                    'left' => 
                    array (
                      'type' => 'variable',
                      'value' => 'headers',
                      'file' => '/app/phalcon/Http/Message/AbstractMessage.zep',
                      'line' => 512,
                      'char' => 36,
                    ),
                    'file' => '/app/phalcon/Http/Message/AbstractMessage.zep',
                    'line' => 512,
                    'char' => 36,
                  ),
                  'right' => 
                  array (
                    'type' => 'string',
                    'value' => 'array',
                    'file' => '/app/phalcon/Http/Message/AbstractMessage.zep',
                    'line' => 512,
                    'char' => 44,
                  ),
                  'file' => '/app/phalcon/Http/Message/AbstractMessage.zep',
                  'line' => 512,
                  'char' => 44,
                ),
                'file' => '/app/phalcon/Http/Message/AbstractMessage.zep',
                'line' => 512,
                'char' => 44,
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
                      'variable' => 'collection',
                      'expr' => 
                      array (
                        'type' => 'mcall',
                        'variable' => 
                        array (
                          'type' => 'variable',
                          'value' => 'this',
                          'file' => '/app/phalcon/Http/Message/AbstractMessage.zep',
                          'line' => 513,
                          'char' => 35,
                        ),
                        'name' => 'populateHeaderCollection',
                        'call-type' => 1,
                        'parameters' => 
                        array (
                          0 => 
                          array (
                            'parameter' => 
                            array (
                              'type' => 'variable',
                              'value' => 'headers',
                              'file' => '/app/phalcon/Http/Message/AbstractMessage.zep',
                              'line' => 513,
                              'char' => 68,
                            ),
                            'file' => '/app/phalcon/Http/Message/AbstractMessage.zep',
                            'line' => 513,
                            'char' => 68,
                          ),
                        ),
                        'file' => '/app/phalcon/Http/Message/AbstractMessage.zep',
                        'line' => 513,
                        'char' => 69,
                      ),
                      'file' => '/app/phalcon/Http/Message/AbstractMessage.zep',
                      'line' => 513,
                      'char' => 69,
                    ),
                  ),
                  'file' => '/app/phalcon/Http/Message/AbstractMessage.zep',
                  'line' => 514,
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
                      'variable' => 'collection',
                      'expr' => 
                      array (
                        'type' => 'mcall',
                        'variable' => 
                        array (
                          'type' => 'variable',
                          'value' => 'this',
                          'file' => '/app/phalcon/Http/Message/AbstractMessage.zep',
                          'line' => 514,
                          'char' => 35,
                        ),
                        'name' => 'checkHeaderHost',
                        'call-type' => 1,
                        'parameters' => 
                        array (
                          0 => 
                          array (
                            'parameter' => 
                            array (
                              'type' => 'variable',
                              'value' => 'collection',
                              'file' => '/app/phalcon/Http/Message/AbstractMessage.zep',
                              'line' => 514,
                              'char' => 62,
                            ),
                            'file' => '/app/phalcon/Http/Message/AbstractMessage.zep',
                            'line' => 514,
                            'char' => 62,
                          ),
                        ),
                        'file' => '/app/phalcon/Http/Message/AbstractMessage.zep',
                        'line' => 514,
                        'char' => 63,
                      ),
                      'file' => '/app/phalcon/Http/Message/AbstractMessage.zep',
                      'line' => 514,
                      'char' => 63,
                    ),
                  ),
                  'file' => '/app/phalcon/Http/Message/AbstractMessage.zep',
                  'line' => 515,
                  'char' => 9,
                ),
              ),
              'else_statements' => 
              array (
                0 => 
                array (
                  'type' => 'if',
                  'expr' => 
                  array (
                    'type' => 'unlikely',
                    'left' => 
                    array (
                      'type' => 'not',
                      'left' => 
                      array (
                        'type' => 'list',
                        'left' => 
                        array (
                          'type' => 'and',
                          'left' => 
                          array (
                            'type' => 'identical',
                            'left' => 
                            array (
                              'type' => 'typeof',
                              'left' => 
                              array (
                                'type' => 'variable',
                                'value' => 'headers',
                                'file' => '/app/phalcon/Http/Message/AbstractMessage.zep',
                                'line' => 516,
                                'char' => 44,
                              ),
                              'file' => '/app/phalcon/Http/Message/AbstractMessage.zep',
                              'line' => 516,
                              'char' => 44,
                            ),
                            'right' => 
                            array (
                              'type' => 'string',
                              'value' => 'object',
                              'file' => '/app/phalcon/Http/Message/AbstractMessage.zep',
                              'line' => 516,
                              'char' => 54,
                            ),
                            'file' => '/app/phalcon/Http/Message/AbstractMessage.zep',
                            'line' => 516,
                            'char' => 54,
                          ),
                          'right' => 
                          array (
                            'type' => 'instanceof',
                            'left' => 
                            array (
                              'type' => 'variable',
                              'value' => 'headers',
                              'file' => '/app/phalcon/Http/Message/AbstractMessage.zep',
                              'line' => 516,
                              'char' => 73,
                            ),
                            'right' => 
                            array (
                              'type' => 'variable',
                              'value' => 'Collection',
                              'file' => '/app/phalcon/Http/Message/AbstractMessage.zep',
                              'line' => 516,
                              'char' => 85,
                            ),
                            'file' => '/app/phalcon/Http/Message/AbstractMessage.zep',
                            'line' => 516,
                            'char' => 85,
                          ),
                          'file' => '/app/phalcon/Http/Message/AbstractMessage.zep',
                          'line' => 516,
                          'char' => 85,
                        ),
                        'file' => '/app/phalcon/Http/Message/AbstractMessage.zep',
                        'line' => 516,
                        'char' => 87,
                      ),
                      'file' => '/app/phalcon/Http/Message/AbstractMessage.zep',
                      'line' => 516,
                      'char' => 87,
                    ),
                    'file' => '/app/phalcon/Http/Message/AbstractMessage.zep',
                    'line' => 516,
                    'char' => 87,
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
                              'value' => 'Headers needs to be either an array or instance of Phalcon\\\\Collection\\\\Collection',
                              'file' => '/app/phalcon/Http/Message/AbstractMessage.zep',
                              'line' => 519,
                              'char' => 17,
                            ),
                            'file' => '/app/phalcon/Http/Message/AbstractMessage.zep',
                            'line' => 519,
                            'char' => 17,
                          ),
                        ),
                        'file' => '/app/phalcon/Http/Message/AbstractMessage.zep',
                        'line' => 519,
                        'char' => 18,
                      ),
                      'file' => '/app/phalcon/Http/Message/AbstractMessage.zep',
                      'line' => 520,
                      'char' => 13,
                    ),
                  ),
                  'file' => '/app/phalcon/Http/Message/AbstractMessage.zep',
                  'line' => 522,
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
                      'variable' => 'collection',
                      'expr' => 
                      array (
                        'type' => 'variable',
                        'value' => 'headers',
                        'file' => '/app/phalcon/Http/Message/AbstractMessage.zep',
                        'line' => 522,
                        'char' => 37,
                      ),
                      'file' => '/app/phalcon/Http/Message/AbstractMessage.zep',
                      'line' => 522,
                      'char' => 37,
                    ),
                  ),
                  'file' => '/app/phalcon/Http/Message/AbstractMessage.zep',
                  'line' => 523,
                  'char' => 9,
                ),
              ),
              'file' => '/app/phalcon/Http/Message/AbstractMessage.zep',
              'line' => 525,
              'char' => 14,
            ),
            2 => 
            array (
              'type' => 'return',
              'expr' => 
              array (
                'type' => 'variable',
                'value' => 'collection',
                'file' => '/app/phalcon/Http/Message/AbstractMessage.zep',
                'line' => 525,
                'char' => 26,
              ),
              'file' => '/app/phalcon/Http/Message/AbstractMessage.zep',
              'line' => 526,
              'char' => 5,
            ),
          ),
          'docblock' => '**
     * Sets the headers
     *
     * @param $headers
     *
     * @return Collection
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
                  'value' => 'Collection',
                  'file' => '/app/phalcon/Http/Message/AbstractMessage.zep',
                  'line' => 509,
                  'char' => 5,
                ),
                'collection' => 0,
                'file' => '/app/phalcon/Http/Message/AbstractMessage.zep',
                'line' => 509,
                'char' => 5,
              ),
            ),
            'void' => 0,
            'file' => '/app/phalcon/Http/Message/AbstractMessage.zep',
            'line' => 509,
            'char' => 5,
          ),
          'file' => '/app/phalcon/Http/Message/AbstractMessage.zep',
          'line' => 508,
          'last-line' => 534,
          'char' => 28,
        ),
        17 => 
        array (
          'visibility' => 
          array (
            0 => 'final',
            1 => 'protected',
          ),
          'type' => 'method',
          'name' => 'processProtocol',
          'parameters' => 
          array (
            0 => 
            array (
              'type' => 'parameter',
              'name' => 'protocol',
              'const' => 0,
              'data-type' => 'variable',
              'mandatory' => 0,
              'default' => 
              array (
                'type' => 'string',
                'value' => '',
                'file' => '/app/phalcon/Http/Message/AbstractMessage.zep',
                'line' => 535,
                'char' => 61,
              ),
              'reference' => 0,
              'file' => '/app/phalcon/Http/Message/AbstractMessage.zep',
              'line' => 535,
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
                  'variable' => 'protocols',
                  'file' => '/app/phalcon/Http/Message/AbstractMessage.zep',
                  'line' => 537,
                  'char' => 22,
                ),
              ),
              'file' => '/app/phalcon/Http/Message/AbstractMessage.zep',
              'line' => 539,
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
                  'variable' => 'protocols',
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
                          'value' => '1.0',
                          'file' => '/app/phalcon/Http/Message/AbstractMessage.zep',
                          'line' => 540,
                          'char' => 17,
                        ),
                        'value' => 
                        array (
                          'type' => 'int',
                          'value' => '1',
                          'file' => '/app/phalcon/Http/Message/AbstractMessage.zep',
                          'line' => 540,
                          'char' => 20,
                        ),
                        'file' => '/app/phalcon/Http/Message/AbstractMessage.zep',
                        'line' => 540,
                        'char' => 20,
                      ),
                      1 => 
                      array (
                        'key' => 
                        array (
                          'type' => 'string',
                          'value' => '1.1',
                          'file' => '/app/phalcon/Http/Message/AbstractMessage.zep',
                          'line' => 541,
                          'char' => 17,
                        ),
                        'value' => 
                        array (
                          'type' => 'int',
                          'value' => '1',
                          'file' => '/app/phalcon/Http/Message/AbstractMessage.zep',
                          'line' => 541,
                          'char' => 20,
                        ),
                        'file' => '/app/phalcon/Http/Message/AbstractMessage.zep',
                        'line' => 541,
                        'char' => 20,
                      ),
                      2 => 
                      array (
                        'key' => 
                        array (
                          'type' => 'string',
                          'value' => '2.0',
                          'file' => '/app/phalcon/Http/Message/AbstractMessage.zep',
                          'line' => 542,
                          'char' => 17,
                        ),
                        'value' => 
                        array (
                          'type' => 'int',
                          'value' => '1',
                          'file' => '/app/phalcon/Http/Message/AbstractMessage.zep',
                          'line' => 542,
                          'char' => 20,
                        ),
                        'file' => '/app/phalcon/Http/Message/AbstractMessage.zep',
                        'line' => 542,
                        'char' => 20,
                      ),
                      3 => 
                      array (
                        'key' => 
                        array (
                          'type' => 'string',
                          'value' => '3.0',
                          'file' => '/app/phalcon/Http/Message/AbstractMessage.zep',
                          'line' => 543,
                          'char' => 17,
                        ),
                        'value' => 
                        array (
                          'type' => 'int',
                          'value' => '1',
                          'file' => '/app/phalcon/Http/Message/AbstractMessage.zep',
                          'line' => 544,
                          'char' => 9,
                        ),
                        'file' => '/app/phalcon/Http/Message/AbstractMessage.zep',
                        'line' => 544,
                        'char' => 9,
                      ),
                    ),
                    'file' => '/app/phalcon/Http/Message/AbstractMessage.zep',
                    'line' => 544,
                    'char' => 10,
                  ),
                  'file' => '/app/phalcon/Http/Message/AbstractMessage.zep',
                  'line' => 544,
                  'char' => 10,
                ),
              ),
              'file' => '/app/phalcon/Http/Message/AbstractMessage.zep',
              'line' => 546,
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
                    'type' => 'or',
                    'left' => 
                    array (
                      'type' => 'empty',
                      'left' => 
                      array (
                        'type' => 'list',
                        'left' => 
                        array (
                          'type' => 'variable',
                          'value' => 'protocol',
                          'file' => '/app/phalcon/Http/Message/AbstractMessage.zep',
                          'line' => 546,
                          'char' => 36,
                        ),
                        'file' => '/app/phalcon/Http/Message/AbstractMessage.zep',
                        'line' => 546,
                        'char' => 39,
                      ),
                      'file' => '/app/phalcon/Http/Message/AbstractMessage.zep',
                      'line' => 546,
                      'char' => 39,
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
                          'value' => 'protocol',
                          'file' => '/app/phalcon/Http/Message/AbstractMessage.zep',
                          'line' => 546,
                          'char' => 59,
                        ),
                        'file' => '/app/phalcon/Http/Message/AbstractMessage.zep',
                        'line' => 546,
                        'char' => 59,
                      ),
                      'right' => 
                      array (
                        'type' => 'string',
                        'value' => 'string',
                        'file' => '/app/phalcon/Http/Message/AbstractMessage.zep',
                        'line' => 546,
                        'char' => 67,
                      ),
                      'file' => '/app/phalcon/Http/Message/AbstractMessage.zep',
                      'line' => 546,
                      'char' => 67,
                    ),
                    'file' => '/app/phalcon/Http/Message/AbstractMessage.zep',
                    'line' => 546,
                    'char' => 67,
                  ),
                  'file' => '/app/phalcon/Http/Message/AbstractMessage.zep',
                  'line' => 546,
                  'char' => 69,
                ),
                'file' => '/app/phalcon/Http/Message/AbstractMessage.zep',
                'line' => 546,
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
                          'value' => 'Invalid protocol value',
                          'file' => '/app/phalcon/Http/Message/AbstractMessage.zep',
                          'line' => 547,
                          'char' => 70,
                        ),
                        'file' => '/app/phalcon/Http/Message/AbstractMessage.zep',
                        'line' => 547,
                        'char' => 70,
                      ),
                    ),
                    'file' => '/app/phalcon/Http/Message/AbstractMessage.zep',
                    'line' => 547,
                    'char' => 71,
                  ),
                  'file' => '/app/phalcon/Http/Message/AbstractMessage.zep',
                  'line' => 548,
                  'char' => 9,
                ),
              ),
              'file' => '/app/phalcon/Http/Message/AbstractMessage.zep',
              'line' => 550,
              'char' => 10,
            ),
            3 => 
            array (
              'type' => 'if',
              'expr' => 
              array (
                'type' => 'unlikely',
                'left' => 
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
                        'value' => 'protocols',
                        'file' => '/app/phalcon/Http/Message/AbstractMessage.zep',
                        'line' => 550,
                        'char' => 37,
                      ),
                      'right' => 
                      array (
                        'type' => 'variable',
                        'value' => 'protocol',
                        'file' => '/app/phalcon/Http/Message/AbstractMessage.zep',
                        'line' => 550,
                        'char' => 46,
                      ),
                      'file' => '/app/phalcon/Http/Message/AbstractMessage.zep',
                      'line' => 550,
                      'char' => 48,
                    ),
                    'file' => '/app/phalcon/Http/Message/AbstractMessage.zep',
                    'line' => 550,
                    'char' => 48,
                  ),
                  'file' => '/app/phalcon/Http/Message/AbstractMessage.zep',
                  'line' => 550,
                  'char' => 48,
                ),
                'file' => '/app/phalcon/Http/Message/AbstractMessage.zep',
                'line' => 550,
                'char' => 48,
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
                            'type' => 'string',
                            'value' => 'Unsupported protocol ',
                            'file' => '/app/phalcon/Http/Message/AbstractMessage.zep',
                            'line' => 552,
                            'char' => 39,
                          ),
                          'right' => 
                          array (
                            'type' => 'variable',
                            'value' => 'protocol',
                            'file' => '/app/phalcon/Http/Message/AbstractMessage.zep',
                            'line' => 553,
                            'char' => 13,
                          ),
                          'file' => '/app/phalcon/Http/Message/AbstractMessage.zep',
                          'line' => 553,
                          'char' => 13,
                        ),
                        'file' => '/app/phalcon/Http/Message/AbstractMessage.zep',
                        'line' => 553,
                        'char' => 13,
                      ),
                    ),
                    'file' => '/app/phalcon/Http/Message/AbstractMessage.zep',
                    'line' => 553,
                    'char' => 14,
                  ),
                  'file' => '/app/phalcon/Http/Message/AbstractMessage.zep',
                  'line' => 554,
                  'char' => 9,
                ),
              ),
              'file' => '/app/phalcon/Http/Message/AbstractMessage.zep',
              'line' => 556,
              'char' => 14,
            ),
            4 => 
            array (
              'type' => 'return',
              'expr' => 
              array (
                'type' => 'variable',
                'value' => 'protocol',
                'file' => '/app/phalcon/Http/Message/AbstractMessage.zep',
                'line' => 556,
                'char' => 24,
              ),
              'file' => '/app/phalcon/Http/Message/AbstractMessage.zep',
              'line' => 557,
              'char' => 5,
            ),
          ),
          'docblock' => '**
     * Checks the protocol
     *
     * @param string $protocol
     *
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
                'file' => '/app/phalcon/Http/Message/AbstractMessage.zep',
                'line' => 536,
                'char' => 5,
              ),
            ),
            'void' => 0,
            'file' => '/app/phalcon/Http/Message/AbstractMessage.zep',
            'line' => 536,
            'char' => 5,
          ),
          'file' => '/app/phalcon/Http/Message/AbstractMessage.zep',
          'line' => 535,
          'last-line' => 558,
          'char' => 28,
        ),
      ),
      'file' => '/app/phalcon/Http/Message/AbstractMessage.zep',
      'line' => 27,
      'char' => 14,
    ),
    'file' => '/app/phalcon/Http/Message/AbstractMessage.zep',
    'line' => 27,
    'char' => 14,
  ),
);