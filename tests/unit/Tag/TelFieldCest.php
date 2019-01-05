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

namespace Phalcon\Test\Unit\Tag;

use Phalcon\Test\Fixtures\Helpers\TagHelper;

/**
 * Class TelFieldCest
 */
class TelFieldCest extends TagHelper
{
    protected $function  = 'telField';
    protected $inputType = 'tel';
}
