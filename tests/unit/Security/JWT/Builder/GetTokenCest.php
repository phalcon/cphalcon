<?php

/**
 * This file is part of the Phalcon Framework.
 *
 * For the full copyright and license information, please view the LICENSE.md
 * file that was distributed with this source code.
 */

declare(strict_types=1);

namespace Phalcon\Test\Unit\Security\JWT\Builder;

use Phalcon\Security\JWT\Builder;
use Phalcon\Security\JWT\Exceptions\ValidatorException;
use Phalcon\Security\JWT\Signer\Hmac;
use Phalcon\Security\JWT\Token\Token;
use Phalcon\Test\Fixtures\Traits\JWTTrait;
use UnitTester;

class GetTokenCest
{
    use JWTTrait;

    /**
     * Unit Tests Phalcon\Security\JWT\Builder :: getToken()
     *
     * @author Phalcon Team <team@phalcon.io>
     * @since  2019-12-22
     */
    public function securityJWTBuilderGetToken(UnitTester $I)
    {
        $I->wantToTest('Security\JWT\Builder - getToken()');

        $token = $this->newToken();

        $I->assertInstanceOf(Token::class, $token);

        $parts = explode('.', $token->getToken());
        $I->assertCount(3, $parts);
    }

    /**
     * Unit Tests Phalcon\Security\JWT\Builder :: extended - getToken()
     *
     * @issue  15322
     * @since  2021-03-02
     */
    public function securityJWTBuilderExtendedGetToken(UnitTester $I)
    {
        $I->wantToTest('Security\JWT\Builder - extended - getToken()');

        $token = $this->newExtendedToken();

        $I->assertInstanceOf(Token::class, $token);

        $parts = explode('.', $token->getToken());
        $I->assertCount(3, $parts);
    }

    /**
     * Unit Tests Phalcon\Security\JWT\Builder :: getToken() - exception
     *
     * @since  2019-12-19
     */
    public function securityJWTBuilderGetTokenException(UnitTester $I)
    {
        $I->wantToTest('Security\JWT\Builder - getToken() - exception');

        $I->expectThrowable(
            new ValidatorException(
                'Invalid passphrase (empty)'
            ),
            function () {
                $signer = new Hmac();
                $builder = new Builder($signer);
                $token = $builder->getToken();
            }
        );
    }
}
