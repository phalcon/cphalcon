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
    'file' => '/app/phalcon/Di/ServiceProviderInterface.zep',
    'line' => 11,
    'char' => 9,
  ),
  1 => 
  array (
    'type' => 'namespace',
    'name' => 'Phalcon\\Di',
    'file' => '/app/phalcon/Di/ServiceProviderInterface.zep',
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
        'file' => '/app/phalcon/Di/ServiceProviderInterface.zep',
        'line' => 13,
        'char' => 24,
      ),
    ),
    'file' => '/app/phalcon/Di/ServiceProviderInterface.zep',
    'line' => 38,
    'char' => 2,
  ),
  3 => 
  array (
    'type' => 'comment',
    'value' => '**
 * Should be implemented by service providers, or such components, which
 * register a service in the service container.
 *
 * ```php
 * namespace Acme;
 *
 * use Phalcon\\DiInterface;
 * use Phalcon\\Di\\ServiceProviderInterface;
 *
 * class SomeServiceProvider implements ServiceProviderInterface
 * {
 *     public function register(DiInterface $di)
 *     {
 *         $di->setShared(
 *             \'service\',
 *             function () {
 *                 // ...
 *             }
 *         );
 *     }
 * }
 * ```
 *',
    'file' => '/app/phalcon/Di/ServiceProviderInterface.zep',
    'line' => 39,
    'char' => 9,
  ),
  4 => 
  array (
    'type' => 'interface',
    'name' => 'ServiceProviderInterface',
    'definition' => 
    array (
      'methods' => 
      array (
        0 => 
        array (
          'visibility' => 
          array (
            0 => 'public',
          ),
          'type' => 'method',
          'name' => 'register',
          'parameters' => 
          array (
            0 => 
            array (
              'type' => 'parameter',
              'name' => 'di',
              'const' => 0,
              'data-type' => 'variable',
              'mandatory' => 0,
              'cast' => 
              array (
                'type' => 'variable',
                'value' => 'DiInterface',
                'file' => '/app/phalcon/Di/ServiceProviderInterface.zep',
                'line' => 44,
                'char' => 45,
              ),
              'reference' => 0,
              'file' => '/app/phalcon/Di/ServiceProviderInterface.zep',
              'line' => 44,
              'char' => 46,
            ),
          ),
          'docblock' => '**
     * Registers a service provider.
     *',
          'return-type' => 
          array (
            'type' => 'return-type',
            'void' => 1,
            'file' => '/app/phalcon/Di/ServiceProviderInterface.zep',
            'line' => 44,
            'char' => 55,
          ),
          'file' => '/app/phalcon/Di/ServiceProviderInterface.zep',
          'line' => 44,
          'last-line' => 45,
          'char' => 19,
        ),
      ),
      'file' => '/app/phalcon/Di/ServiceProviderInterface.zep',
      'line' => 45,
      'char' => 1,
    ),
    'file' => '/app/phalcon/Di/ServiceProviderInterface.zep',
    'line' => 0,
    'char' => 0,
  ),
);