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

namespace Phalcon\Test\Integration\Db\Index;

use IntegrationTester;
use Phalcon\Test\Fixtures\Traits\DialectTrait;

class GetNameCest
{
    use DialectTrait;

    /**
     * Tests Phalcon\Db\Index :: getName()
     */
    public function dbIndexGetName(IntegrationTester $I)
    {
        $I->wantToTest('Db\Index - getName()');

        $indexes = $this->getIndexes();


        $index1 = $indexes['index1'];

        $I->assertEquals(
            'index1',
            $index1->getName()
        );


        $index2 = $indexes['index2'];

        $I->assertEquals(
            'index2',
            $index2->getName()
        );


        $index3 = $indexes['PRIMARY'];

        $I->assertEquals(
            'PRIMARY',
            $index3->getName()
        );


        $index4 = $indexes['index4'];

        $I->assertEquals(
            'index4',
            $index4->getName()
        );


        $index5 = $indexes['index5'];

        $I->assertEquals(
            'index5',
            $index5->getName()
        );
    }
}
