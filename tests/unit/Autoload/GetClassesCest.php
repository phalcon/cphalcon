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

namespace Phalcon\Test\Unit\Loader;

use Phalcon\Loader;
use UnitTester;

use function dataDir;

class GetClassesCest
{
    /**
     * Tests Phalcon\Loader :: getClasses()
     *
     * @author Sid Roberts <https://github.com/SidRoberts>
     * @since  2019-05-25
     */
    public function loaderGetClasses(UnitTester $I)
    {
        $I->wantToTest('Loader - getClasses()');

        $loader = new Loader();

        $loader->registerClasses(
            [
                'One' => dataDir('fixtures/Loader/Example/Classes/One.php'),
                'Two' => dataDir('fixtures/Loader/Example/Classes/Two.php'),
            ]
        );

        $I->assertEquals(
            [
                'One' => dataDir('fixtures/Loader/Example/Classes/One.php'),
                'Two' => dataDir('fixtures/Loader/Example/Classes/Two.php'),
            ],
            $loader->getClasses()
        );
    }
}
