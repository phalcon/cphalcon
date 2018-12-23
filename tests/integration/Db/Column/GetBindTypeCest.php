<?php
declare(strict_types=1);

/**
 * This file is part of the Phalcon Framework.
 *
 * (c) Phalcon Team <team@phalconphp.com>
 *
 * For the full copyright and license information, please view the LICENSE.txt
 * file that was distributed with this source code.
 */

namespace Phalcon\Test\Integration\Db\Column;

use IntegrationTester;
use Phalcon\Test\Fixtures\Traits\Db\MysqlTrait;
use Phalcon\Test\Fixtures\Traits\DiTrait;

/**
 * Class GetBindTypeCest
 */
class GetBindTypeCest
{
    use DiTrait;
    use MysqlTrait;

    /**
     * Tests Phalcon\Db\Column :: getBindType()
     *
     * @param IntegrationTester $I
     *
     * @author Phalcon Team <team@phalconphp.com>
     * @since  2018-11-13
     */
    public function dbColumnGetBindType(IntegrationTester $I)
    {
        $I->wantToTest("Db\Column - getBindType()");
        $columns         = $this->getColumns();
        $expectedColumns = $this->getExpectedColumns();
        foreach ($expectedColumns as $index => $column) {
            $I->assertEquals($columns[$index]['_bindType'], $column->getBindType());
        }
    }
}
