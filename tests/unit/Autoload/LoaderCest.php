<?php

/**
 * This file is part of the Phalcon Framework.
 *
 * (c) Phalcon Team <team@phalcon.io>
 *
 * For the full copyright and license information, please view the LICENSE.txt
 * file that was distributed with this source code.
 */

namespace Phalcon\Test\Unit\Autoload;

use LoaderEvent;
use Phalcon\Autoload\Loader;
use Phalcon\Events\Event;
use Phalcon\Events\Manager;
use Phalcon\Test\Fixtures\Traits\LoaderTrait;
use UnitTester;

use function dataDir;

class LoaderCest
{
    use LoaderTrait;

    public function testEvents(UnitTester $I)
    {
        $I->skipTest("Needs investigation");
        $loader = new Loader();

        $loader->registerDirs(
            [
                dataDir('fixtures/Loader/Example/Events/'),
            ]
        );

        $loader->registerClasses(
            [
                'OtherClass' => dataDir('fixtures/Loader/Example/Events/Other/'),
            ]
        );

        $loader->registerNamespaces(
            [
                'Other\OtherClass' => dataDir('fixtures/Loader/Example/Events/Other/'),
            ]
        );

        $eventsManager = new Manager();

        $trace = [];

        $eventsManager->attach(
            'loader',
            function ($event, $loader) use (&$trace) {
                $type = $event->getType();

                /** @var Event $event */
                /** @var Loader $loader */
                if (!isset($trace[$type])) {
                    $trace[$type] = [];
                }

                $trace[$type][] = $loader->getCheckedPath();
            }
        );

        $loader->setEventsManager($eventsManager);

        $loader->register();

        $I->assertInstanceOf(
            LoaderEvent::class,
            new LoaderEvent()
        );

        $expected = [
            'beforeCheckClass' => [0 => null],
            'beforeCheckPath'  => [0 => dataDir('fixtures/Loader/Example/Events/LoaderEvent.php')],
            'pathFound'        => [0 => dataDir('fixtures/Loader/Example/Events/LoaderEvent.php')],
        ];

        $I->assertEquals($expected, $trace);

        $loader->unregister();
    }
}
