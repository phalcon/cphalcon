<?php

use Phalcon\Mvc\View;
use Phalcon\Test\Module\View\Engine\Mustache;

return [
    [
        'errorMessage' => 'Engine mustache does not work',
        'engine' => ['.mhtml' => Mustache::class],
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
];
