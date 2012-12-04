<?php
/**
 * IPv4.php
 * Filter\Helper\IPv4
 *
 * Helper for the Filter class
 *
 * PhalconPHP Framework
 *
 * @copyright (c) 2011-2013 Phalcon Team
 * @link      http://www.phalconphp.com
 * @author    Andres Gutierrez <andres@phalconphp.com>
 * @author    Eduar Carvajal <eduar@phalconphp.com>
 * @author    Nikolaos Dimopoulos <nikos@niden.net>
 *
 * The contents of this file are subject to the New BSD License that is
 * bundled with this package in the file docs/LICENSE.txt
 *
 * If you did not receive a copy of the license and are unable to obtain it
 * through the world-wide-web, please send an email to license@phalconphp.com
 * so that we can send you a copy immediately.
 */

/**
 * Class used by Phalcon\Filter
 */
class Filter_Helper_IPv4
{

    public function filter($value)
    {
        return filter_var($value, FILTER_VALIDATE_IP, FILTER_FLAG_IPV4);
    }

}
