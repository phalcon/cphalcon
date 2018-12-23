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

namespace Phalcon\Test\Integration\Db\Dialect\Postgresql;

use IntegrationTester;

/**
 * Class DescribeReferencesCest
 */
class DescribeReferencesCest
{
    /**
     * Tests Phalcon\Db\Dialect\Postgresql :: describeReferences()
     *
     * @param IntegrationTester $I
     *
     * @author Phalcon Team <team@phalconphp.com>
     * @since  2018-11-13
     */
    public function dbDialectPostgresqlDescribeReferences(IntegrationTester $I)
    {
        $I->wantToTest('Db\Dialect\Postgresql - describeReferences()');
        $I->skipTest('Need implementation');
    }
}
