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

class GetTypeValuesCest
{
    /**
     * Tests Phalcon\Db\Column :: getTypeValues()
     *
     * @author Phalcon Team <team@phalcon.io>
     * @since  2018-11-13
     */
    public function dbColumnGetTypeValues(IntegrationTester $I)
    {
        $I->wantToTest('Db\Column - getTypeValues()');
        $I->skipTest('Need implementation');
    }
}
