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

namespace Phalcon\Tests\Unit\Annotations\Collection;

use Phalcon\Annotations\Collection;
use UnitTester;

class ConstructCest
{
    /**
     * Tests Phalcon\Annotations\Collection :: __construct()
     *
     * @author Jeremy PASTOURET <https://github.com/jenovateurs>
     * @since  2020-01-27
     */
    public function annotationsCollectionConstruct(UnitTester $I)
    {
        $I->wantToTest('Annotations\Collection - __construct()');

        $collection = new Collection();

        $expected = Collection::class;
        $actual   = $collection;
        $I->assertInstanceOf($expected, $actual);
    }

    /**
     * Tests Phalcon\Annotations\Collection :: __construct() with array
     * parameter
     *
     * @author Jeremy PASTOURET <https://github.com/jenovateurs>
     * @since  2020-01-27
     */
    public function annotationsCollectionConstructWithArrayParam(UnitTester $I)
    {
        $I->wantToTest('Annotations\Collection - __construct() with array parameter');

        $collection = new Collection(
            [
                [
                    'name' => 'NovAnnotation',
                ],
            ]
        );

        $expected = Collection::class;
        $actual   = $collection;
        $I->assertInstanceOf($expected, $actual);
    }
}
