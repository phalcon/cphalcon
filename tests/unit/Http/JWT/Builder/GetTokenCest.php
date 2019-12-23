<?php

/**
 * This file is part of the Phalcon Framework.
 *
 * For the full copyright and license information, please view the LICENSE.md
 * file that was distributed with this source code.
 */

declare(strict_types=1);

namespace Phalcon\Test\Unit\Http\JWT\Builder;

use Phalcon\Http\JWT\Builder;
use Phalcon\Http\JWT\Exceptions\ValidatorException;
use Phalcon\Http\JWT\Signer\Hmac;
use Phalcon\Http\JWT\Token\Token;
use Phalcon\Test\Fixtures\Traits\JWTTrait;
use UnitTester;

class GetTokenCest
{
    use JWTTrait;

    /**
     * Unit Tests Phalcon\Http\JWT\Builder :: getToken()
     *
     * @since  2019-12-19
     */
    public function httpJWTBuilderGetToken(UnitTester $I)
    {
        $I->wantToTest('Http\JWT\Builder - getToken()');

        $token = $this->newToken();

        $I->assertInstanceOf(Token::class, $token);

        $parts = explode('.', $token->getToken());
        $I->assertCount(3, $parts);
    }

    /**
     * Unit Tests Phalcon\Http\JWT\Builder :: getToken() - exception
     *
     * @since  2019-12-19
     */
    public function httpJWTBuilderGetTokenException(UnitTester $I)
    {
        $I->wantToTest('Http\JWT\Builder - getToken() - exception');

        $I->expectThrowable(
            new ValidatorException(
                'Invalid passphrase (empty)'
            ),
            function () {
                $signer  = new Hmac();
                $builder = new Builder($signer);
                $token   = $builder->getToken();
            }
        );
    }
}
