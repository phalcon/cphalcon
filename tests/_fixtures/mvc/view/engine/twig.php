<?php

use Phalcon\Mvc\View;
use Phalcon\Test\Module\View\Engine\Twig;

return [
    [
        'errorMessage' => 'Engine twig does not work',
        'engine' => ['.twig' => Twig::class],
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
