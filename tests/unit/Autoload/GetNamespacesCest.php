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

class GetNamespacesCest
{
    /**
     * Tests Phalcon\Loader :: getNamespaces()
     *
     * @author Sid Roberts <https://github.com/SidRoberts>
     * @since  2019-05-25
     */
    public function loaderGetNamespaces(UnitTester $I)
    {
        $I->wantToTest('Loader - getNamespaces()');

        $loader = new Loader();

        $loader->registerNamespaces(
            [
                'Example\Namespaces\Base'    => dataDir('fixtures/Loader/Example/Namespaces/Base/'),
                'Example\Namespaces\Adapter' => dataDir('fixtures/Loader/Example/Namespaces/Adapter/'),
                'Example\Namespaces'         => dataDir('fixtures/Loader/Example/Namespaces/'),
            ]
        );

        $I->assertEquals(
            [
                'Example\Namespaces\Base'    => [
                    dataDir('fixtures/Loader/Example/Namespaces/Base/'),
                ],
                'Example\Namespaces\Adapter' => [
                    dataDir('fixtures/Loader/Example/Namespaces/Adapter/'),
                ],
                'Example\Namespaces'         => [
                    dataDir('fixtures/Loader/Example/Namespaces/'),
                ],
            ],
            $loader->getNamespaces()
        );
    }
}
