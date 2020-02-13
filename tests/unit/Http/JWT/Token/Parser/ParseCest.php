<?php

/**
 * This file is part of the Phalcon Framework.
 *
 * For the full copyright and license information, please view the LICENSE.md
 * file that was distributed with this source code.
 */

declare(strict_types=1);

namespace Phalcon\Test\Unit\Http\JWT\Token\Parser;

use Phalcon\Security\JWT\Signer\None;
use Phalcon\Security\JWT\Token\Item;
use Phalcon\Security\JWT\Token\Parser;
use Phalcon\Security\JWT\Token\Signature;
use Phalcon\Test\Fixtures\Traits\JWTTrait;
use UnitTester;

class ParseCest
{
    use JWTTrait;

    /**
     * Unit Tests Phalcon\Security\JWT\Token\Parser :: parse()
     *
     * @since  2019-12-22
     */
    public function httpJWTTokenParserParse(UnitTester $I)
    {
        $I->wantToTest('Http\JWT\Token\Parser - parse()');

        $source    = $this->newToken();
        $parser    = new Parser();
        $token     = $parser->parse($source->getToken());
        $headers   = $token->getHeaders();
        $claims    = $token->getClaims();
        $signature = $token->getSignature();

        $I->assertInstanceOf(Item::class, $headers);
        $I->assertInstanceOf(Item::class, $claims);
        $I->assertInstanceOf(Signature::class, $signature);

        $I->assertTrue($headers->has("typ"));
        $I->assertTrue($headers->has("alg"));

        $I->assertEquals("JWT", $headers->get("typ"));
        $I->assertEquals("HS512", $headers->get("alg"));

        $I->assertTrue($claims->has("aud"));
        $I->assertTrue($claims->has("exp"));
        $I->assertTrue($claims->has("jti"));
        $I->assertTrue($claims->has("iat"));
        $I->assertTrue($claims->has("iss"));
        $I->assertTrue($claims->has("nbf"));
        $I->assertTrue($claims->has("sub"));

        $I->assertEquals(["my-audience"], $claims->get("aud"));
        $I->assertEquals($token->getClaims()->get('exp'), $claims->get("exp"));
        $I->assertEquals("PH-JWT", $claims->get("jti"));
        $I->assertEquals($token->getClaims()->get('iat'), $claims->get("iat"));
        $I->assertEquals("Phalcon JWT", $claims->get("iss"));
        $I->assertEquals($token->getClaims()->get('nbf'), $claims->get("nbf"));
        $I->assertEquals("Mary had a little lamb", $claims->get("sub"));
    }

    /**
     * Unit Tests Phalcon\Security\JWT\Token\Parser :: parse() - no signature
     *
     * @since  2019-12-22
     */
    public function httpJWTTokenParserParseNoSignature(UnitTester $I)
    {
        $I->wantToTest('Http\JWT\Token\Parser - parse() - no signature');

        $source    = $this->newToken(None::class);
        $parser    = new Parser();
        $token     = $parser->parse($source->getToken());
        $headers   = $token->getHeaders();
        $claims    = $token->getClaims();
        $signature = $token->getSignature();

        $I->assertInstanceOf(Item::class, $headers);
        $I->assertInstanceOf(Item::class, $claims);
        $I->assertInstanceOf(Signature::class, $signature);

        $I->assertTrue($headers->has("typ"));
        $I->assertTrue($headers->has("alg"));

        $I->assertEquals("JWT", $headers->get("typ"));
        $I->assertEquals("none", $headers->get("alg"));

        $I->assertTrue($claims->has("aud"));
        $I->assertTrue($claims->has("exp"));
        $I->assertTrue($claims->has("jti"));
        $I->assertTrue($claims->has("iat"));
        $I->assertTrue($claims->has("iss"));
        $I->assertTrue($claims->has("nbf"));
        $I->assertTrue($claims->has("sub"));

        $I->assertEquals(["my-audience"], $claims->get("aud"));
        $I->assertEquals($token->getClaims()->get('exp'), $claims->get("exp"));
        $I->assertEquals("PH-JWT", $claims->get("jti"));
        $I->assertEquals($token->getClaims()->get('iat'), $claims->get("iat"));
        $I->assertEquals("Phalcon JWT", $claims->get("iss"));
        $I->assertEquals($token->getClaims()->get('nbf'), $claims->get("nbf"));
        $I->assertEquals("Mary had a little lamb", $claims->get("sub"));

        $I->assertEmpty($signature->getEncoded());
    }

    /**
     * Unit Tests Phalcon\Security\JWT\Token\Parser :: parse() - aud not an array
     *
     * @since  2019-12-22
     */
    public function httpJWTTokenParserParseAudNotAnArray(UnitTester $I)
    {
        $I->wantToTest('Http\JWT\Token\Parser - parse() - aud not an array');

        $tokenString = "eyJ0eXAiOiJKV1QiLCJhbGciOiJIUzUxMiJ9."
            . "eyJhdWQiOiJteS1hdWRpZW5jZSIsImV4cCI6MTU3NzE1NDg5"
            . "NiwiaXNzIjoiUGhhbGNvbiBKV1QiLCJpYXQiOjE1NzcwNjg0O"
            . "TYsImp0aSI6IlBILUpXVCIsIm5iZiI6MTU3Njk4MjA5Niwic3"
            . "ViIjoiTWFyeSBoYWQgYSBsaXR0bGUgbGFtYiJ9."
            . "Dg33cVxxCit5Tq7TTG14DNe8eb_B94OtSIb_KGjVhdIeFyrI8D"
            . "xZyjDfbwsyyk2LVCUVe01k1bbudjjPr-l_wA";

        $parser    = new Parser();
        $token     = $parser->parse($tokenString);
        $headers   = $token->getHeaders();
        $claims    = $token->getClaims();
        $signature = $token->getSignature();

        $I->assertInstanceOf(Item::class, $headers);
        $I->assertInstanceOf(Item::class, $claims);
        $I->assertInstanceOf(Signature::class, $signature);

        $I->assertTrue($headers->has("typ"));
        $I->assertTrue($headers->has("alg"));

        $I->assertEquals("JWT", $headers->get("typ"));
        $I->assertEquals("HS512", $headers->get("alg"));

        $I->assertTrue($claims->has("aud"));
        $I->assertTrue($claims->has("exp"));
        $I->assertTrue($claims->has("jti"));
        $I->assertTrue($claims->has("iat"));
        $I->assertTrue($claims->has("iss"));
        $I->assertTrue($claims->has("nbf"));
        $I->assertTrue($claims->has("sub"));

        $I->assertEquals(["my-audience"], $claims->get("aud"));
        $I->assertEquals($token->getClaims()->get('exp'), $claims->get("exp"));
        $I->assertEquals("PH-JWT", $claims->get("jti"));
        $I->assertEquals($token->getClaims()->get('iat'), $claims->get("iat"));
        $I->assertEquals("Phalcon JWT", $claims->get("iss"));
        $I->assertEquals($token->getClaims()->get('nbf'), $claims->get("nbf"));
        $I->assertEquals("Mary had a little lamb", $claims->get("sub"));
    }

    /**
     * Unit Tests Phalcon\Security\JWT\Token\Parser :: parse() - exception claims
     * not array
     *
     * @since  2019-12-22
     */
    public function httpJWTTokenParserParseExceptionClaimsNotArray(UnitTester $I)
    {
        $I->wantToTest('Http\JWT\Token\Parser - parse() - exception claims not array');

        $I->expectThrowable(
            new \InvalidArgumentException(
                "Invalid Claims (not an array)"
            ),
            function () {
                $tokenString = "eyJ0eXAiOiJKV1QiLCJhbGciOiJIUzUxMiJ9."
                    . "Im9uZSI."
                    . "cbY2T8Wty9ejBnDuvivja3BelmRx1Z_YRlaLlFkv0EkXA"
                    . "873JhKg_rbU6MdhsTXa9fmFGSvc87x-5HvUD1kMWA";

                $parser = new Parser();
                $token  = $parser->parse($tokenString);
            }
        );
    }

    /**
     * Unit Tests Phalcon\Security\JWT\Token\Parser :: parse() - exception headers
     * not array
     *
     * @since  2019-12-22
     */
    public function httpJWTTokenParserParseExceptionHeadersNotArray(UnitTester $I)
    {
        $I->wantToTest('Http\JWT\Token\Parser - parse() - exception headers not array');

        $I->expectThrowable(
            new \InvalidArgumentException(
                "Invalid Header (not an array)"
            ),
            function () {
                $tokenString = "Im9uZXR3byI."
                    . "eyJhdWQiOlsibXktYXVkaWVuY2UiXSwiZXhwIjoxNTc3MTQwNjI"
                    . "yLCJpc3MiOiJQaGFsY29uIEpXVCIsImlhdCI6MTU3NzA1NDIyMiw"
                    . "ianRpIjoiUEgtSldUIiwibmJmIjoxNTc2OTY3ODIyLCJzdWIiOiJN"
                    . "YXJ5IGhhZCBhIGxpdHRsZSBsYW1iIn0."
                    . "8wA9TNxo7BufOGtpih5j2DHebuF5YbCuptSZC_UL35WrQisOv2Mx"
                    . "EcI7fkz4z2YYKavLKKKUPFPsLuYsZ3cFRw";

                $parser = new Parser();
                $token  = $parser->parse($tokenString);
            }
        );
    }

    /**
     * Unit Tests Phalcon\Security\JWT\Token\Parser :: parse() - exception no typ
     *
     * @since  2019-12-22
     */
    public function httpJWTTokenParserParseExceptionNoTyp(UnitTester $I)
    {
        $I->wantToTest('Http\JWT\Token\Parser - parse() - exception no typ');

        $I->expectThrowable(
            new \InvalidArgumentException(
                "Invalid Header (missing 'typ' element)"
            ),
            function () {
                $tokenString = "eyJhdWQiOlsibXktYXVkaWVuY2UiXSwiZXhwIjoxNT"
                    . "c3MTQwODAyLCJpc3MiOiJQaGFsY29uIEpXVCIsImlhd"
                    . "CI6MTU3NzA1NDQwMiwianRpIjoiUEgtSldUIiwibmJmI"
                    . "joxNTc2OTY4MDAyLCJzdWIiOiJNYXJ5IGhhZCBhIGxpd"
                    . "HRsZSBsYW1iIn0."
                    . "eyJhbGciOiJIUzUxMiJ9."
                    . "1IVBMm7v7oQtDtAatiINF4eHAGzwW7cdMsiBNJgpxFe"
                    . "NZyt7n9CxBDidUENQE03ybMYrIpASZVidVFinVL4g1g";

                $parser = new Parser();
                $token  = $parser->parse($tokenString);
            }
        );
    }

    /**
     * Unit Tests Phalcon\Security\JWT\Token\Parser :: parse() - exception wrong JWT
     *
     * @since  2019-12-22
     */
    public function httpJWTTokenParserParseExceptionWrongJwt(UnitTester $I)
    {
        $I->wantToTest('Http\JWT\Token\Parser - parse() - exception wrong JWT');

        $I->expectThrowable(
            new \InvalidArgumentException(
                "Invalid JWT string (dots misalignment)"
            ),
            function () {
                $tokenString = "eyJhdWQiOlsibXktYXVkaWVuY2UiXSwiZXhwIjoxNT";

                $parser = new Parser();
                $token  = $parser->parse($tokenString);
            }
        );
    }
}
