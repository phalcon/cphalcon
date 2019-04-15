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

namespace Phalcon\Test\Unit\Security;

use UnitTester;
use Phalcon\Security;

/**
 * Class CheckHashCest
 */
class CheckHashCest
{
    /**
     * Tests Phalcon\Security :: checkHash()
     *
     * @param UnitTester $I
     *
     * @author Phalcon Team <team@phalconphp.com>
     * @since  2018-11-13
     */
    public function securityCheckHash(UnitTester $I)
    {
        $I->wantToTest('Security - checkHash()');
        $security = new Security();
        $password = 'PhalconROCKS!';

        $security->setDefaultHash(Security::CRYPT_DEFAULT);
        $I->assertTrue($security->checkHash($password, $security->hash($password)));

        $security->setDefaultHash(Security::CRYPT_STD_DES);
        $I->assertTrue($security->checkHash($password, $security->hash($password)));

        $security->setDefaultHash(Security::CRYPT_EXT_DES);
        $I->assertTrue($security->checkHash($password, $security->hash($password)));

        $security->setDefaultHash(Security::CRYPT_BLOWFISH);
        $I->assertTrue($security->checkHash($password, $security->hash($password)));

        $security->setDefaultHash(Security::CRYPT_BLOWFISH_A);
        $I->assertTrue($security->checkHash($password, $security->hash($password)));

        $security->setDefaultHash(Security::CRYPT_BLOWFISH_X);
        $I->assertTrue($security->checkHash($password, $security->hash($password)));

        $security->setDefaultHash(Security::CRYPT_BLOWFISH_Y);
        $I->assertTrue($security->checkHash($password, $security->hash($password)));

        $security->setDefaultHash(Security::CRYPT_SHA256);
        $I->assertTrue($security->checkHash($password, $security->hash($password)));

        $security->setDefaultHash(Security::CRYPT_SHA512);
        $I->assertTrue($security->checkHash($password, $security->hash($password)));
    }
}
