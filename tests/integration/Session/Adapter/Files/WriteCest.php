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

namespace Phalcon\Test\Integration\Session\Adapter\Files;

use IntegrationTester;

/**
 * Class WriteCest
 */
class WriteCest
{
    /**
     * Tests Phalcon\Session\Adapter\Files :: write()
     *
     * @param IntegrationTester $I
     *
     * @author Phalcon Team <team@phalconphp.com>
     * @since  2018-11-13
     */
    public function sessionAdapterFilesWrite(IntegrationTester $I)
    {
        $I->wantToTest('Session\Adapter\Files - write()');
        $I->skipTest('Need implementation');
    }
}
