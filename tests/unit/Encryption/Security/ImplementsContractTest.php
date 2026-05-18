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

namespace Phalcon\Tests\Unit\Encryption\Security;

use Phalcon\Contracts\Encryption\Security\CryptoUtils;
use Phalcon\Contracts\Encryption\Security\CsrfProtection;
use Phalcon\Contracts\Encryption\Security\PasswordSecurity;
use Phalcon\Contracts\Encryption\Security\Security as SecurityContract;
use Phalcon\Encryption\Security;
use Phalcon\Tests\AbstractUnitTestCase;

final class ImplementsContractTest extends AbstractUnitTestCase
{
    /**
     * @author Phalcon Team <team@phalcon.io>
     * @since  2026-05-06
     */
    public function testImplementsCryptoUtilsContract(): void
    {
        $security = new Security();

        $this->assertInstanceOf(CryptoUtils::class, $security);
    }

    /**
     * @author Phalcon Team <team@phalcon.io>
     * @since  2026-05-06
     */
    public function testImplementsCsrfProtectionContract(): void
    {
        $security = new Security();

        $this->assertInstanceOf(CsrfProtection::class, $security);
    }

    /**
     * @author Phalcon Team <team@phalcon.io>
     * @since  2026-05-06
     */
    public function testImplementsPasswordSecurityContract(): void
    {
        $security = new Security();

        $this->assertInstanceOf(PasswordSecurity::class, $security);
    }

    /**
     * @author Phalcon Team <team@phalcon.io>
     * @since  2026-05-06
     */
    public function testImplementsSecurityContract(): void
    {
        $security = new Security();

        $this->assertInstanceOf(SecurityContract::class, $security);
    }
}
