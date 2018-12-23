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

namespace Phalcon\Test\Integration\Db\Reference;

use IntegrationTester;

/**
 * Class GetColumnsCest
 */
class GetColumnsCest
{
    /**
     * Tests Phalcon\Db\Reference :: getColumns()
     *
     * @param IntegrationTester $I
     *
     * @author Phalcon Team <team@phalconphp.com>
     * @since  2018-11-13
     */
    public function dbReferenceGetColumns(IntegrationTester $I)
    {
        $I->wantToTest('Db\Reference - getColumns()');
        $I->skipTest('Need implementation');
    }
}
