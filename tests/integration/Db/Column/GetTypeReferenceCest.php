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

class GetTypeReferenceCest
{
    /**
     * Tests Phalcon\Db\Column :: getTypeReference()
     *
     * @author Phalcon Team <team@phalcon.io>
     * @since  2018-11-13
     */
    public function dbColumnGetTypeReference(IntegrationTester $I)
    {
        $I->wantToTest('Db\Column - getTypeReference()');
        $I->skipTest('Need implementation');
    }
}
