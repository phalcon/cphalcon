<?php

namespace PhalconCi;

class PackageCloud
{
    protected const API_ENDPOINT = "packagecloud.io";

    private $apiKey;
    private $user;
    private $repo;

    public function __construct($apiKey, $user, $repo)
    {
        $this->apiKey = $apiKey;
        $this->user = $user;
        $this->repo = $repo;
    }

    protected function buildRequestUrl($url)
    {
        $baseUrl = "https://" . $this->apiKey . ":@"  . self::API_ENDPOINT;
        return $baseUrl . $url;
    }

    protected function getCurl()
    {
        $ch = curl_init();
        curl_setopt($ch, CURLOPT_TIMEOUT, 30);
        curl_setopt($ch, CURLOPT_RETURNTRANSFER, true);

        return $ch;
    }

    public function query($url)
    {
        echo "Opening: " . $url . PHP_EOL;

        $ch = $this->getCurl();

        curl_setopt($ch, CURLOPT_URL, $this->buildRequestUrl($url));

        if (false === ($retval = curl_exec($ch))) {
            print_r(curl_error($ch));
        } else {
            return json_decode($retval);
        }
    }

    public function getOutdatedPackages($days = 30)
    {
        $now = new \DateTime();

        $packages =  $this->query("/api/v1/repos/" . $this->user . "/" . $this->repo . "/packages.json?per_page=1");
        $outdatedPackages =  [];
        foreach ($packages as $package) {
            $packageDate = \DateTime::createFromFormat("Y-m-d\TH:i:s.u\Z", $package->created_at);
            $age = $packageDate->diff($now)->days;
            if ($age > $days) {
                $package->age = $age;
                $outdatedPackages[] = $package;
            }
        }
        return $outdatedPackages;
    }

    public function deleteOutdatedPackages($days = 30)
    {
        $packages = $this->getOutdatedPackages($days);
        foreach ($packages as $package) {
            $this->deletePackage($package->destroy_url, $package->age);
        }
    }

    public function deletePackage($packageUrl, $age)
    {
        echo "Deleting: " . $packageUrl . " [" . $age . " days old]... ";
        $ch = $this->getCurl();

        curl_setopt($ch, CURLOPT_URL, $this->buildRequestUrl($packageUrl));
        curl_setopt($ch, CURLOPT_CUSTOMREQUEST, "DELETE");

        if (false === ($retval = curl_exec($ch))) {
            print_r(curl_error($ch));
        } else {
            $httpCode = curl_getinfo($ch, CURLINFO_HTTP_CODE);
            switch ($httpCode) {
                case "200":
                    echo "done" . PHP_EOL;
                    break;
                default:
                    echo "fail" . PHP_EOL;
            }
            return json_decode($retval);
        }
    }
}

$packageCloud = new PackageCloud(getenv('PACKAGECLOUD_TOKEN'), "phalcon", "nightly");
$packageCloud->deleteOutdatedPackages(30); //days
