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

namespace Phalcon\Tests\Unit\Loader;

use One;
use Phalcon\Loader;
use Phalcon\Tests\Fixtures\Traits\LoaderTrait;
use Two;
use UnitTester;

use function dataDir;

class RegisterClassesCest
{
    use LoaderTrait;

    public function testClasses(UnitTester $I)
    {
        $loader = new Loader();

        $loader->registerClasses(
            [
                'One' => dataDir('fixtures/Loader/Example/Classes/One.php'),
            ]
        );
        $loader->registerClasses(
            [
                'Two' => dataDir('fixtures/Loader/Example/Classes/Two.php'),
            ],
            true
        );

        $loader->register();

        $I->assertInstanceOf(
            One::class,
            new One()
        );

        $I->assertInstanceOf(
            Two::class,
            new Two()
        );

        $loader->unregister();
    }
}
