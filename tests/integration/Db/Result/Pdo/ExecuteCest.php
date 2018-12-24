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

namespace Phalcon\Test\Integration\Db\Result\Pdo;

use IntegrationTester;

/**
 * Class ExecuteCest
 */
class ExecuteCest
{
    /**
     * Tests Phalcon\Db\Result\Pdo :: execute()
     *
     * @param IntegrationTester $I
     *
     * @author Phalcon Team <team@phalconphp.com>
     * @since  2018-11-13
     */
    public function dbResultPdoExecute(IntegrationTester $I)
    {
        $I->wantToTest('Db\Result\Pdo - execute()');
        $I->skipTest('Need implementation');
    }
}
