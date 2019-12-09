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

class GetTypeCest
{
    use DialectTrait;

    /**
     * Tests Phalcon\Db\Index :: getType()
     */
    public function dbIndexGetType(IntegrationTester $I)
    {
        $I->wantToTest('Db\Index - getType()');

        $indexes = $this->getIndexes();


        $index4 = $indexes['index4'];

        $I->assertEquals(
            'UNIQUE',
            $index4->getType()
        );


        $index5 = $indexes['index5'];

        $I->assertEquals(
            'FULLTEXT',
            $index5->getType()
        );
    }
}
