<?php

/**
 * This file is part of the Phalcon Framework.
 *
 * (c) Phalcon Team <team@phalcon.io>
 *
 * For the full copyright and license information, please view the LICENSE.txt
 * file that was distributed with this source code.
 */

declare(strict_types=1);

namespace Phalcon\Tests\Unit\Autoload\Loader;

use LoaderEvent;
use Phalcon\Autoload\Loader;
use Phalcon\Events\Manager;
use Phalcon\Tests\Fixtures\Traits\LoaderTrait;
use UnitTester;

use function array_pop;
use function dataDir;
use function spl_autoload_functions;

class RegisterUnregisterCest
{
    use LoaderTrait;

    /**
     * Tests Phalcon\Autoload\Loader :: register()/unregister()
     *
     * @param UnitTester $I
     *
     * @author Phalcon Team <team@phalcon.io>
     * @since  2020-09-09
     */
    public function autoloaderLoaderRegisterUnregister(UnitTester $I)
    {
        $I->wantToTest('Autoload\Loader - register()/unregister()');

        $loader = new Loader();
        $loader->register();

        $functions = spl_autoload_functions();
        $item      = array_pop($functions);

        $I->assertSame($loader, $item[0]);
        $I->assertEquals('autoload', $item[1]);

        $loader->unregister();
    }

    /**
     * Tests Phalcon\Autoload\Loader :: events
     *
     * @param UnitTester $I
     *
     * @author Phalcon Team <team@phalcon.io>
     * @since  2020-09-09
     */
    public function autoloaderLoaderEvents(UnitTester $I)
    {
        $I->wantToTest('Autoload\Loader - events');

        $trace   = [];
        $loader  = new Loader();
        $manager = new Manager();

        $loader
            ->setDirectories(
                [
                    dataDir('fixtures/Loader/Example/Events/'),
                ]
            )
            ->setClasses(
                [
                    'OtherClass' => dataDir('fixtures/Loader/Example/Events/Other/'),
                ]
            )
            ->setNamespaces(
                [
                    'Other\OtherClass' => dataDir('fixtures/Loader/Example/Events/Other/'),
                ]
            )
        ;

        $manager->attach(
            'loader',
            function ($event, $loader) use (&$trace) {
                $type = $event->getType();

                if (!isset($trace[$type])) {
                    $trace[$type] = [];
                }

                $trace[$type][] = $loader->getCheckedPath();
            }
        );

        $loader->setEventsManager($manager);

        $loader->register();

        $I->assertInstanceOf(LoaderEvent::class, new LoaderEvent());

        $expected = [
            'beforeCheckClass' => [
                0 => null,
            ],
            'beforeCheckPath'  => [
                0 => dataDir('fixtures/Loader/Example/Events/LoaderEvent.php'),
            ],
            'pathFound'        => [
                0 => dataDir('fixtures/Loader/Example/Events/LoaderEvent.php'),
            ],
        ];

        $I->assertEquals($expected, $trace);

        $loader->unregister();
    }
}
