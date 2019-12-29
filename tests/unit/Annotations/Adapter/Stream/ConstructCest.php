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

namespace Phalcon\Test\Unit\Annotations\Adapter\Stream;

use Phalcon\Annotations\Adapter\AdapterInterface;
use Phalcon\Annotations\Adapter\Stream;
use UnitTester;

use function outputDir;

class ConstructCest
{
    /**
     * Tests Phalcon\Annotations\Adapter\Stream :: __construct()
     *
     * @author Phalcon Team <team@phalcon.io>
     * @since  2018-11-13
     */
    public function annotationsAdapterStreamConstruct(UnitTester $I)
    {
        $I->wantToTest('Annotations\Adapter\Stream - __construct()');

        $adapter = new Stream(
            [
                'annotationsDir' => outputDir('tests/annotations/'),
            ]
        );

        $I->assertInstanceOf(
            AdapterInterface::class,
            $adapter
        );
    }
}
