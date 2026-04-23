<?php

/**
 * This file is part of the Phalcon Framework.
 *
 * For the full copyright and license information, please view the LICENSE.md
 * file that was distributed with this source code.
 */

declare(strict_types=1);

namespace Phalcon\Tests\Unit\Encryption\Security\JWT\Token\Parser;

use InvalidArgumentException;
use Phalcon\Encryption\Security\JWT\Signer\None;
use Phalcon\Encryption\Security\JWT\Token\Item;
use Phalcon\Encryption\Security\JWT\Token\Parser;
use Phalcon\Encryption\Security\JWT\Token\Signature;
use Phalcon\Tests\AbstractUnitTestCase;
use Phalcon\Tests\Unit\Encryption\Fake\JWTTrait;

final class ParseTest extends AbstractUnitTestCase
{
    use JWTTrait;

    /**
     * @author Phalcon Team <team@phalcon.io>
     * @since  2020-09-09
     */
    public function testEncryptionSecurityJWTTokenParserParse(): void
    {
        $source    = $this->newToken();
        $parser    = new Parser();
        $token     = $parser->parse($source->getToken());
        $headers   = $token->getHeaders();
        $claims    = $token->getClaims();
        $signature = $token->getSignature();

        $this->assertInstanceOf(Item::class, $headers);
        $this->assertInstanceOf(Item::class, $claims);
        $this->assertInstanceOf(Signature::class, $signature);

        $this->assertTrue($headers->has('typ'));
        $this->assertTrue($headers->has('alg'));

        $expected = 'JWT';
        $actual   = $headers->get('typ');
        $this->assertSame($expected, $actual);

        $expected = 'HS512';
        $actual   = $headers->get('alg');
        $this->assertSame($expected, $actual);

        $this->assertTrue($claims->has('aud'));
        $this->assertTrue($claims->has('exp'));
        $this->assertTrue($claims->has('jti'));
        $this->assertTrue($claims->has('iat'));
        $this->assertTrue($claims->has('iss'));
        $this->assertTrue($claims->has('nbf'));
        $this->assertTrue($claims->has('sub'));

        $expected = ['my-audience'];
        $actual   = $claims->get('aud');
        $this->assertSame($expected, $actual);

        $this->assertSame(
            $token->getClaims()
                  ->get('exp'),
            $claims->get('exp')
        );

        $expected = 'PH-JWT';
        $actual   = $claims->get('jti');
        $this->assertSame($expected, $actual);

        $this->assertSame(
            $token->getClaims()
                  ->get('iat'),
            $claims->get('iat')
        );

        $expected = 'Phalcon JWT';
        $actual   = $claims->get('iss');
        $this->assertSame($expected, $actual);

        $this->assertSame(
            $token->getClaims()
                  ->get('nbf'),
            $claims->get('nbf')
        );

        $expected = 'Mary had a little lamb';
        $actual   = $claims->get('sub');
        $this->assertSame($expected, $actual);
    }

    /**
     * @author Phalcon Team <team@phalcon.io>
     * @since  2020-09-09
     */
    public function testEncryptionSecurityJWTTokenParserParseAudNotAnArray(): void
    {
        $tokenString = 'eyJ0eXAiOiJKV1QiLCJhbGciOiJIUzUxMiJ9.'
            . 'eyJhdWQiOiJteS1hdWRpZW5jZSIsImV4cCI6MTU3NzE1NDg5'
            . 'NiwiaXNzIjoiUGhhbGNvbiBKV1QiLCJpYXQiOjE1NzcwNjg0O'
            . 'TYsImp0aSI6IlBILUpXVCIsIm5iZiI6MTU3Njk4MjA5Niwic3'
            . 'ViIjoiTWFyeSBoYWQgYSBsaXR0bGUgbGFtYiJ9.'
            . 'Dg33cVxxCit5Tq7TTG14DNe8eb_B94OtSIb_KGjVhdIeFyrI8D'
            . 'xZyjDfbwsyyk2LVCUVe01k1bbudjjPr-l_wA';

        $parser    = new Parser();
        $token     = $parser->parse($tokenString);
        $headers   = $token->getHeaders();
        $claims    = $token->getClaims();
        $signature = $token->getSignature();

        $this->assertInstanceOf(Item::class, $headers);
        $this->assertInstanceOf(Item::class, $claims);
        $this->assertInstanceOf(Signature::class, $signature);

        $this->assertTrue($headers->has('typ'));
        $this->assertTrue($headers->has('alg'));

        $expected = 'JWT';
        $actual   = $headers->get('typ');
        $this->assertSame($expected, $actual);

        $expected = 'HS512';
        $actual   = $headers->get('alg');
        $this->assertSame($expected, $actual);

        $this->assertTrue($claims->has('aud'));
        $this->assertTrue($claims->has('exp'));
        $this->assertTrue($claims->has('jti'));
        $this->assertTrue($claims->has('iat'));
        $this->assertTrue($claims->has('iss'));
        $this->assertTrue($claims->has('nbf'));
        $this->assertTrue($claims->has('sub'));

        $expected = ['my-audience'];
        $actual   = $claims->get('aud');
        $this->assertSame($expected, $actual);

        $this->assertSame(
            $token->getClaims()
                  ->get('exp'),
            $claims->get('exp')
        );

        $expected = 'PH-JWT';
        $actual   = $claims->get('jti');
        $this->assertSame($expected, $actual);

        $this->assertSame(
            $token->getClaims()
                  ->get('iat'),
            $claims->get('iat')
        );

        $expected = 'Phalcon JWT';
        $actual   = $claims->get('iss');
        $this->assertSame($expected, $actual);

        $this->assertSame(
            $token->getClaims()
                  ->get('nbf'),
            $claims->get('nbf')
        );

        $expected = 'Mary had a little lamb';
        $actual   = $claims->get('sub');
        $this->assertSame($expected, $actual);
    }

    /**
     * @author Phalcon Team <team@phalcon.io>
     * @since  2020-09-09
     */
    public function testEncryptionSecurityJWTTokenParserParseExceptionClaimsNotArray(): void
    {
        $this->expectException(InvalidArgumentException::class);
        $this->expectExceptionMessage('Invalid Claims (not an array)');

        $tokenString = 'eyJ0eXAiOiJKV1QiLCJhbGciOiJIUzUxMiJ9.'
            . 'Im9uZSI.'
            . 'cbY2T8Wty9ejBnDuvivja3BelmRx1Z_YRlaLlFkv0EkXA'
            . '873JhKg_rbU6MdhsTXa9fmFGSvc87x-5HvUD1kMWA';

        $parser = new Parser();
        $parser->parse($tokenString);
    }

    /**
     * @author Phalcon Team <team@phalcon.io>
     * @since  2020-09-09
     */
    public function testEncryptionSecurityJWTTokenParserParseExceptionHeadersNotArray(): void
    {
        $this->expectException(InvalidArgumentException::class);
        $this->expectExceptionMessage('Invalid Header (not an array)');

        $tokenString = 'Im9uZXR3byI.'
            . 'eyJhdWQiOlsibXktYXVkaWVuY2UiXSwiZXhwIjoxNTc3MTQwNjI'
            . 'yLCJpc3MiOiJQaGFsY29uIEpXVCIsImlhdCI6MTU3NzA1NDIyMiw'
            . 'ianRpIjoiUEgtSldUIiwibmJmIjoxNTc2OTY3ODIyLCJzdWIiOiJN'
            . 'YXJ5IGhhZCBhIGxpdHRsZSBsYW1iIn0.'
            . '8wA9TNxo7BufOGtpih5j2DHebuF5YbCuptSZC_UL35WrQisOv2Mx'
            . 'EcI7fkz4z2YYKavLKKKUPFPsLuYsZ3cFRw';

        $parser = new Parser();
        $parser->parse($tokenString);
    }

    /**
     * @author Phalcon Team <team@phalcon.io>
     * @since  2020-09-09
     */
    public function testEncryptionSecurityJWTTokenParserParseExceptionNoTyp(): void
    {
        $this->expectException(InvalidArgumentException::class);
        $this->expectExceptionMessage("Invalid Header (missing 'typ' element)");

        $tokenString = 'eyJhdWQiOlsibXktYXVkaWVuY2UiXSwiZXhwIjoxNT'
            . 'c3MTQwODAyLCJpc3MiOiJQaGFsY29uIEpXVCIsImlhd'
            . 'CI6MTU3NzA1NDQwMiwianRpIjoiUEgtSldUIiwibmJmI'
            . 'joxNTc2OTY4MDAyLCJzdWIiOiJNYXJ5IGhhZCBhIGxpd'
            . 'HRsZSBsYW1iIn0.'
            . 'eyJhbGciOiJIUzUxMiJ9.'
            . '1IVBMm7v7oQtDtAatiINF4eHAGzwW7cdMsiBNJgpxFe'
            . 'NZyt7n9CxBDidUENQE03ybMYrIpASZVidVFinVL4g1g';

        $parser = new Parser();
        $parser->parse($tokenString);
    }

    /**
     * @author Phalcon Team <team@phalcon.io>
     * @since  2020-09-09
     */
    public function testEncryptionSecurityJWTTokenParserParseExceptionWrongJwt(): void
    {
        $this->expectException(InvalidArgumentException::class);
        $this->expectExceptionMessage('Invalid JWT string (dots misalignment)');

        $tokenString = 'eyJhdWQiOlsibXktYXVkaWVuY2UiXSwiZXhwIjoxNT';

        $parser = new Parser();
        $parser->parse($tokenString);
    }

    /**
     * @author Phalcon Team <team@phalcon.io>
     * @since  2020-09-09
     */
    public function testEncryptionSecurityJWTTokenParserParseNoSignature(): void
    {
        $source    = $this->newToken(None::class);
        $parser    = new Parser();
        $token     = $parser->parse($source->getToken());
        $headers   = $token->getHeaders();
        $claims    = $token->getClaims();
        $signature = $token->getSignature();

        $this->assertInstanceOf(Item::class, $headers);
        $this->assertInstanceOf(Item::class, $claims);
        $this->assertInstanceOf(Signature::class, $signature);

        $this->assertTrue($headers->has('typ'));
        $this->assertTrue($headers->has('alg'));

        $expected = 'JWT';
        $actual   = $headers->get('typ');
        $this->assertSame($expected, $actual);

        $expected = 'none';
        $actual   = $headers->get('alg');
        $this->assertSame($expected, $actual);

        $this->assertTrue($claims->has('aud'));
        $this->assertTrue($claims->has('exp'));
        $this->assertTrue($claims->has('jti'));
        $this->assertTrue($claims->has('iat'));
        $this->assertTrue($claims->has('iss'));
        $this->assertTrue($claims->has('nbf'));
        $this->assertTrue($claims->has('sub'));

        $expected = ['my-audience'];
        $actual   = $claims->get('aud');
        $this->assertSame($expected, $actual);

        $this->assertSame(
            $token->getClaims()
                  ->get('exp'),
            $claims->get('exp')
        );

        $expected = 'PH-JWT';
        $actual   = $claims->get('jti');
        $this->assertSame($expected, $actual);

        $this->assertSame(
            $token->getClaims()
                  ->get('iat'),
            $claims->get('iat')
        );

        $expected = 'Phalcon JWT';
        $actual   = $claims->get('iss');
        $this->assertSame($expected, $actual);

        $this->assertSame(
            $token->getClaims()
                  ->get('nbf'),
            $claims->get('nbf')
        );

        $expected = 'Mary had a little lamb';
        $actual   = $claims->get('sub');
        $this->assertSame($expected, $actual);

        $this->assertEmpty($signature->getEncoded());
    }
}
