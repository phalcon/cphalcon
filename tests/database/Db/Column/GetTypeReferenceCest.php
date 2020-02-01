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

namespace Phalcon\Test\Integration\Db\Column;

use IntegrationTester;
use Phalcon\Test\Fixtures\Traits\DbTrait;

class GetTypeReferenceCest
{
    use DbTrait;

    /**
     * Tests Phalcon\Db\Column :: getTypeReference()
     *
     * @author Phalcon Team <team@phalcon.io>
     * @since  2018-11-13
     */
    public function dbColumnGetTypeReference(IntegrationTester $I)
    {
        $I->wantToTest('Db\Column - getTypeReference()');

        $columns         = $this->getColumnsArray();
        $expectedColumns = $this->getColumnsObjects();

        foreach ($expectedColumns as $index => $column) {
            $I->assertEquals(
                $columns[$index]['typeReference'],
                $column->getTypeReference()
            );
        }
    }
}
