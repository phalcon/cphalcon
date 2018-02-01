<?php

/**
 * Fixture for View engines test
 *
 * @copyright (c) 2011-present Phalcon Team
 * @link      http://www.phalconphp.com
 * @author    Sergii Svyrydenko <sergey.v.sviridenko@gmail.com>
 * @package   Phalcon\Test\Unit\Mvc
 *
 * The contents of this file are subject to the New BSD License that is
 * bundled with this package in the file LICENSE.txt
 *
 * If you did not receive a copy of the license and are unable to obtain it
 * through the world-wide-web, please send an email to license@phalconphp.com
 * so that we can send you a copy immediately.
 */

use Phalcon\Mvc\View;
use Phalcon\Test\Module\View\Engine\Mustache as MustacheEngine;
use Phalcon\Test\Module\View\Engine\Twig as TwigEngine;
use Phalcon\Mvc\View\Engine\Php as PhpEngine;

return [
    [
        'errorMessage' => 'Engine mustache does not work',
        'engines' => ['.mhtml' => MustacheEngine::class],
        'params' => [
            [
                'paramToView' => ['name', 'Sonny'],
                'renderLevel' => View::LEVEL_ACTION_VIEW,
                'render' => ['test4', 'index'],
                'expected' => 'Hello Sonny',
            ],
            [
                'paramToView' => ['some_eval', true],
                'renderLevel' => View::LEVEL_LAYOUT,
                'render' => ['test4', 'index'],
                'expected' => "Well, this is the view content: Hello Sonny.\n",
            ],
        ],
    ],
    [
        'errorMessage' => 'Engine twig does not work',
        'engines' => ['.twig' => TwigEngine::class],
        'params' => [
            [
                'paramToView' => ['song', 'Rock n roll'],
                'renderLevel' => View::LEVEL_ACTION_VIEW,
                'render' => ['test7', 'index'],
                'expected' => 'Hello Rock n roll!',
            ],
            [
                'paramToView' => ['some_eval', true],
                'renderLevel' => View::LEVEL_LAYOUT,
                'render' => ['test7', 'index'],
                'expected' => "Clearly, the song is: Hello Rock n roll!.\n",
            ],
        ],
    ],
];
