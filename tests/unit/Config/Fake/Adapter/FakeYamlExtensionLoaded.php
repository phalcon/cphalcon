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

namespace Phalcon\Tests\Unit\Config\Fake\Adapter;

use Phalcon\Config\Adapter\Yaml;

class FakeYamlExtensionLoaded extends Yaml
{
    /**
     * Find out whether an extension is loaded
     *
     * @param string $name
     *
     * @return bool
     *
     * @link https://php.net/manual/en/function.extension-loaded.php
     */
    protected static function phpExtensionLoaded(string $name): bool
    {
        return false;
    }
}
