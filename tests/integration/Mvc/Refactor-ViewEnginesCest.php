<?php

/*
 +------------------------------------------------------------------------+
 | Phalcon Framework                                                      |
 +------------------------------------------------------------------------+
 | Copyright (c) 2011-present Phalcon Team (https://phalcon.io)       |
 +------------------------------------------------------------------------+
 | This source file is subject to the New BSD License that is bundled     |
 | with this package in the file LICENSE.txt.                             |
 |                                                                        |
 | If you did not receive a copy of the license and are unable to         |
 | obtain it through the world-wide-web, please send an email             |
 | to license@phalcon.io so we can send you a copy immediately.       |
 +------------------------------------------------------------------------+
 */

declare(strict_types=1);

namespace Phalcon\Test\Integration\Mvc;

use Codeception\Example;
use IntegrationTester;
use Phalcon\Mvc\View;
use Phalcon\Mvc\View\Engine\Php;
use Phalcon\Test\Fixtures\Mvc\View\Engine\Mustache;
use Phalcon\Test\Fixtures\Mvc\View\Engine\Twig;
use Phalcon\Test\Fixtures\Mvc\View\IteratorObject;
use Phalcon\Test\Fixtures\Traits\DiTrait;

use function dataDir;

class ViewEnginesCest
{
    use DiTrait;

    /**
     * @var int
     */
    private $level;

    public function _before(IntegrationTester $I)
    {
        $this->newDi();
        $this->setDiView();

        $this->level = ob_get_level();
    }

    public function _after(IntegrationTester $I)
    {
        while (ob_get_level() > $this->level) {
            ob_end_flush();
        }
    }

    /**
     * Tests View::render test template engines in function
     *
     * @author       Sergii Svyrydenko <sergey.v.sviridenko@gmail.com>
     * @since        2017-01-29
     *
     * @dataProvider getViewBuiltinFunction
     */
    public function shouldRenderVoltEngineBuiltInFunctions(IntegrationTester $I, Example $example)
    {
        $params   = $example[0];
        $expected = $example[1];

        $view = $this->getService('view');

        $view->registerEngines(
            $params['engines']
        );

        foreach ($params['setVar'] as $key => $value) {
            $view->setVar($key, $value);
        }


        $view->start();

        $view->render(
            $params['render'][0],
            $params['render'][1]
        );

        $view->finish();


        $I->assertEquals(
            $expected,
            $view->getContent()
        );

        $I->safeDeleteFile(
            dataDir('fixtures/views/builtinfunction/index.volt.php')
        );
    }

    private function getViewBuiltinFunction(): array
    {
        return [
            [
                [
                    'engines'     => [
                        '.volt' => \Phalcon\Mvc\View\Engine\Volt::class,
                    ],
                    'setVar'      => [
                        'arr'    => [1, 2, 3, 4],
                        'obj'    => new IteratorObject([1, 2, 3, 4]),
                        'str'    => 'hello',
                        'no_str' => 1234,
                    ],
                    'render'      => ['builtinfunction', 'index'],
                    'removeFiles' => [],
                ],
                'Length Array: 4Length Object: 4Length String: 5Length No String: 4' .
                'Slice Array: 1,2,3,4Slice Array: 2,3Slice Array: 1,2,3' .
                'Slice Object: 2,3,4Slice Object: 2,3Slice Object: 1,2Slice String: hel' .
                'Slice String: elSlice String: lloSlice No String: 123Slice No String: 23' .
                'Slice No String: 34',
            ],
        ];
    }

    /**
     * Tests Mustache template engine
     *
     * @author Phalcon Team <team@phalcon.io>
     * @since  2012-08-17
     */
    public function shouldWorkWithMustacheEngine(IntegrationTester $I)
    {
        $data = $this->getMustacheEngine();

        $errorMessage = $data['errorMessage'];
        $engine       = $data['engines'];
        $params       = $data['params'];

        $view = $this->getService('view');

        $view->registerEngines($engine);

        $this->setParamAndCheckData($I, $errorMessage, $params, $view);
    }

    private function getMustacheEngine(): array
    {
        return [
            'errorMessage' => 'Engine mustache does not work',
            'engines'      => ['.mhtml' => Mustache::class],
            'params'       => [
                [
                    'paramToView' => ['name', 'Sonny'],
                    'renderLevel' => View::LEVEL_ACTION_VIEW,
                    'render'      => ['mustache', 'index'],
                    'expected'    => 'Hello Sonny',
                ],
                //                [
                //                    'paramToView' => ['some_eval', true],
                //                    'renderLevel' => View::LEVEL_LAYOUT,
                //                    'render'      => ['mustache', 'index'],
                //                    'expected'    => "Well, this is the view content: Hello Sonny.\n",
                //                ],
            ],
        ];
    }

    /**
     * Set params and check expected data after render view
     */
    private function setParamAndCheckData(IntegrationTester $I, string $errorMessage, array $params, View $view)
    {
        foreach ($params as $param) {
            $view->setParamToView(
                $param['paramToView'][0],
                $param['paramToView'][1]
            );

            $view->start();
            $view->setRenderLevel($param['renderLevel']);
            $view->render($param['render'][0], $param['render'][1]);
            $view->finish();

            $I->assertEquals(
                $param['expected'],
                $view->getContent(),
                $errorMessage
            );
        }
    }

//    /**
//     * Tests the mix Mustache with PHP Engines
//     *
//     * @test
//     * @author Phalcon Team <team@phalcon.io>
//     * @since  2012-08-17
//     */
//    public function shouldWorkMixPhpMustacheEnginesPartial(IntegrationTester $I)
//    {
//        $this->specify(
//            'The engine does not work as expected',
//            function ($errorMessage, $engines, $params) {
//                $this->view->setDI(Di::getDefault());
//                $this->view->setViewsDir(PATH_DATA . 'views' . DIRECTORY_SEPARATOR);
//                $this->view->registerEngines($engines);
//
//                $this->setParamAndCheckData($errorMessage, $params, $this->view);
//            },
//            [
//                'examples' => include PATH_FIXTURES . 'mvc/view_engines_test/view_set_php_mustache_partial.php'
//            ]
//        );
//    }
//
//    /**
//     * Tests the mix Mustache with PHP Engines
//     *
//     * @test
//     * @author Phalcon Team <team@phalcon.io>
//     * @since  2012-08-17
//     */
//    public function shouldWorkMixPhpTwigEnginesPartial(IntegrationTester $I)
//    {
//        $this->specify(
//            'The engine does not work as expected',
//            function ($errorMessage, $engines, $params) {
//                $this->view->setDI(Di::getDefault());
//                $this->view->setViewsDir(PATH_DATA . 'views' . DIRECTORY_SEPARATOR);
//                $this->view->registerEngines($engines);
//
//                $this->setParamAndCheckData($errorMessage, $params, $this->view);
//            },
//            [
//                'examples' => include PATH_FIXTURES . 'mvc/view_engines_test/view_set_php_twig_partial.php'
//            ]
//        );
//    }

    /**
     * Tests Twig template engine
     *
     * @author Phalcon Team <team@phalcon.io>
     * @since  2012-08-17
     */
    public function shouldWorkWithTwigEngine(IntegrationTester $I)
    {
        $data = $this->getTwigEngine();

        $errorMessage = $data['errorMessage'];
        $engine       = $data['engines'];
        $params       = $data['params'];

        $view = $this->getService('view');

        $view->registerEngines($engine);

        $this->setParamAndCheckData($I, $errorMessage, $params, $view);
    }

    private function getTwigEngine(): array
    {
        return [
            'errorMessage' => 'Engine twig does not work',
            'engines'      => ['.twig' => Twig::class],
            'params'       => [
                [
                    'paramToView' => ['song', 'Rock n roll'],
                    'renderLevel' => View::LEVEL_ACTION_VIEW,
                    'render'      => ['twig', 'index'],
                    'expected'    => 'Hello Rock n roll!',
                ],
                //                [
                //                    'paramToView' => ['some_eval', true],
                //                    'renderLevel' => View::LEVEL_LAYOUT,
                //                    'render'      => ['twig', 'index'],
                //                    'expected'    => "Clearly, the song is: Hello Rock n roll!.\n",
                //                ],
            ],
        ];
    }

    /**
     * Tests the mix Twig with PHP Engines
     *
     * @author Phalcon Team <team@phalcon.io>
     * @since  2012-08-17
     */
    public function shouldWorkMixPhpTwigEngines(IntegrationTester $I)
    {
        $I->skipTest('TODO - Check Layout');

        $data = $this->getTwigPhpEngine();

        $errorMessage = $data['errorMessage'];
        $engine       = $data['engines'];
        $params       = $data['params'];

        $view = $this->getService('view');

        $view->registerEngines($engine);

        $this->setParamAndCheckData($I, $errorMessage, $params, $view);
    }

    private function getTwigPhpEngine(): array
    {
        return [
            'errorMessage' => 'Mix PHP with Twig does nor work',
            'engines'      => [
                '.twig'  => Twig::class,
                '.phtml' => Php::class,
            ],
            'params'       => [
                [
                    'paramToView' => ['name', 'Sonny'],
                    'renderLevel' => View::LEVEL_LAYOUT,
                    'render'      => ['twigphp', 'index'],
                    'expected'    => 'Well, this is the view content: Hello Sonny.',
                ],
            ],
        ];
    }

    /**
     * Tests the mix Mustache with PHP Engines
     *
     * @author Phalcon Team <team@phalcon.io>
     * @since  2012-08-17
     */
    public function shouldWorkMixPhpMustacheEngines(IntegrationTester $I)
    {
        $I->skipTest('TODO - Check Layout');

        $data = $this->getPhpMustache();

        $errorMessage = $data['errorMessage'];
        $engine       = $data['engines'];
        $params       = $data['params'];

        $view = $this->getService('view');

        $view->registerEngines($engine);

        $this->setParamAndCheckData($I, $errorMessage, $params, $view);
    }

    private function getPhpMustache(): array
    {
        return [
            'errorMessage' => 'Mix PHP with Mustache does not work',
            'engines'      => [
                '.mhtml' => Mustache::class,
                '.phtml' => Php::class,
            ],
            'params'       => [
                [
                    'paramToView' => ['name', 'Sonny'],
                    'renderLevel' => View::LEVEL_LAYOUT,
                    'render'      => ['test6', 'index'],
                    'expected'    => 'Well, this is the view content: Hello Sonny.',
                ],
            ],
        ];
    }
}
