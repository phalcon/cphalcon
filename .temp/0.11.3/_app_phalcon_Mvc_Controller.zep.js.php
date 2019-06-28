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
    'file' => '/app/phalcon/Mvc/Controller.zep',
    'line' => 11,
    'char' => 9,
  ),
  1 => 
  array (
    'type' => 'namespace',
    'name' => 'Phalcon\\Mvc',
    'file' => '/app/phalcon/Mvc/Controller.zep',
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
        'name' => 'Phalcon\\Di\\Injectable',
        'file' => '/app/phalcon/Mvc/Controller.zep',
        'line' => 13,
        'char' => 26,
      ),
    ),
    'file' => '/app/phalcon/Mvc/Controller.zep',
    'line' => 54,
    'char' => 2,
  ),
  3 => 
  array (
    'type' => 'comment',
    'value' => '**
 * Phalcon\\Mvc\\Controller
 *
 * Every application controller should extend this class that encapsulates all
 * the controller functionality
 *
 * The controllers provide the “flow” between models and views. Controllers are
 * responsible for processing the incoming requests from the web browser,
 * interrogating the models for data, and passing that data on to the views for
 * presentation.
 *
 *```php
 * <?php
 *
 * class PeopleController extends \\Phalcon\\Mvc\\Controller
 * {
 *     // This action will be executed by default
 *     public function indexAction()
 *     {
 *
 *     }
 *
 *     public function findAction()
 *     {
 *
 *     }
 *
 *     public function saveAction()
 *     {
 *         // Forwards flow to the index action
 *         return $this->dispatcher->forward(
 *             [
 *                 "controller" => "people",
 *                 "action"     => "index",
 *             ]
 *         );
 *     }
 * }
 *```
 *',
    'file' => '/app/phalcon/Mvc/Controller.zep',
    'line' => 55,
    'char' => 8,
  ),
  4 => 
  array (
    'type' => 'class',
    'name' => 'Controller',
    'abstract' => 1,
    'final' => 0,
    'extends' => 'Injectable',
    'implements' => 
    array (
      0 => 
      array (
        'type' => 'variable',
        'value' => 'ControllerInterface',
        'file' => '/app/phalcon/Mvc/Controller.zep',
        'line' => 56,
        'char' => 1,
      ),
    ),
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
          'statements' => 
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
                      'value' => 'this',
                      'file' => '/app/phalcon/Mvc/Controller.zep',
                      'line' => 62,
                      'char' => 30,
                    ),
                    'file' => '/app/phalcon/Mvc/Controller.zep',
                    'line' => 62,
                    'char' => 30,
                  ),
                  1 => 
                  array (
                    'parameter' => 
                    array (
                      'type' => 'string',
                      'value' => 'onConstruct',
                      'file' => '/app/phalcon/Mvc/Controller.zep',
                      'line' => 62,
                      'char' => 43,
                    ),
                    'file' => '/app/phalcon/Mvc/Controller.zep',
                    'line' => 62,
                    'char' => 43,
                  ),
                ),
                'file' => '/app/phalcon/Mvc/Controller.zep',
                'line' => 62,
                'char' => 45,
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
                      'file' => '/app/phalcon/Mvc/Controller.zep',
                      'line' => 63,
                      'char' => 18,
                    ),
                    'name' => 'onConstruct',
                    'call-type' => 3,
                    'file' => '/app/phalcon/Mvc/Controller.zep',
                    'line' => 63,
                    'char' => 34,
                  ),
                  'file' => '/app/phalcon/Mvc/Controller.zep',
                  'line' => 64,
                  'char' => 9,
                ),
              ),
              'file' => '/app/phalcon/Mvc/Controller.zep',
              'line' => 65,
              'char' => 5,
            ),
          ),
          'docblock' => '**
     * Phalcon\\Mvc\\Controller constructor
     *',
          'file' => '/app/phalcon/Mvc/Controller.zep',
          'line' => 60,
          'last-line' => 66,
          'char' => 25,
        ),
      ),
      'file' => '/app/phalcon/Mvc/Controller.zep',
      'line' => 55,
      'char' => 14,
    ),
    'file' => '/app/phalcon/Mvc/Controller.zep',
    'line' => 55,
    'char' => 14,
  ),
);