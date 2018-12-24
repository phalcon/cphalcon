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
 * Class GetReferencedSchemaCest
 */
class GetReferencedSchemaCest
{
    /**
     * Tests Phalcon\Db\Reference :: getReferencedSchema()
     *
     * @param IntegrationTester $I
     *
     * @author Phalcon Team <team@phalconphp.com>
     * @since  2018-11-13
     */
    public function dbReferenceGetReferencedSchema(IntegrationTester $I)
    {
        $I->wantToTest('Db\Reference - getReferencedSchema()');
        $I->skipTest('Need implementation');
    }
}
